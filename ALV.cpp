#include <iostream>
#include <algorithm> 


using namespace std;

// Định nghĩa cấu trúc cây AVL
struct Node {
    int data;
    Node* L; 
    Node* R;
    int H;   
};

// KHoi tạo 1 node mới cho cây
Node* CreateNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->L = node->R = nullptr;
    node->H = 1; 
    // chiều cao ban đầu là 1
    return node;
}

// Hàm kiểm tra chiều cao node 
int ChieuCao(Node* node) {
    if (node != nullptr)
        return node->H;
    else
        return 0;
}

// Tính độ cân bằng
int CanBang(Node* node) {
    if (node != nullptr)
        return ChieuCao(node->L) - ChieuCao(node->R);
    else
        return 0;
}

// Hàm quay phải
Node* QuayPhai(Node* y) {
    Node* x = y->L;
    Node* T2 = x->R;

    x->R = y;
    y->L = T2;

    y->H = max(ChieuCao(y->L), ChieuCao(y->R)) + 1;
    x->H = max(ChieuCao(x->L), ChieuCao(x->R)) + 1;

    return x;
}

// Hàm quay trái
Node* QuayTrai(Node* x) {
    Node* y = x->R;
    Node* T2 = y->L;

    y->L = x;
    x->R = T2;

    x->H = max(ChieuCao(x->L), ChieuCao(x->R)) + 1;
    y->H = max(ChieuCao(y->L), ChieuCao(y->R)) + 1;

    return y;
}

// Thêm node vào cây AVL
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return CreateNode(key);

    if (key < root->data)
        root->L = insert(root->L, key);
    else if (key > root->data)
        root->R = insert(root->R, key);
    else
        return root; // không cho phép trùng

    // Cập nhật chiều cao
    root->H = max(ChieuCao(root->L), ChieuCao(root->R)) + 1;

    int balance = CanBang(root);

    // Mất cân bằng và xử lý

// Left Left
    if (balance > 1 && key < root->L->data)
        return QuayPhai(root);
// Right Right
    if (balance < -1 && key > root->R->data)
        return QuayTrai(root);
 // Left Right
    if (balance > 1 && key > root->L->data) {
        root->L = QuayTrai(root->L);
        return QuayPhai(root);
    }
// Right Left
    if (balance < -1 && key < root->R->data) {
        root->R = QuayPhai(root->R);
        return QuayTrai(root);
    }

    return root;
}

// Tìm node nhỏ nhất
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->L != nullptr)
        current = current->L;
    return current;
}

// Xoá node khỏi cây AVL
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->L = deleteNode(root->L, key);
    else if (key > root->data)
        root->R = deleteNode(root->R, key);
    else {
        // Node có 1 hoặc không có con
        if ((root->L == nullptr) || (root->R == nullptr)) {
            Node* temp = (root->L != nullptr) ? root->L : root->R;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            // Node có 2 con
            Node* temp = minValueNode(root->R);
            root->data = temp->data;
            root->R = deleteNode(root->R, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->H = max(ChieuCao(root->L), ChieuCao(root->R)) + 1;

    int balance = CanBang(root);

// Left Left
    if (balance > 1 && CanBang(root->L) >= 0)
        return QuayPhai(root);

 // Left Right
    if (balance > 1 && CanBang(root->L) < 0) {
        root->L = QuayTrai(root->L);
        return QuayPhai(root);
    }

// Right Right
    if (balance < -1 && CanBang(root->R) <= 0)
        return QuayTrai(root);

    // Right Left
    if (balance < -1 && CanBang(root->R) > 0) {
        root->R = QuayPhai(root->R);
        return QuayTrai(root);
    }

    return root;
}

// Duyệt LNR (trái - gốc - phải)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->L);
        cout << root->data << " ";
        inorder(root->R);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;
    do {
        cout << "1. Them";
        cout << "2. Xoa";
        cout << "3. Duyet LNR";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 3:
                cout << "Cay LNR: ";
                inorder(root);
                cout << endl;
                break;
            
        }

     } while (choice != 0);

    return 0;
}
