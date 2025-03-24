#include <iostream>

using namespace std;

struct Node{
    int info;
    Node* next;
};

// dùng while 
void ShowList(Node*& pHead){
    if (pHead == nullptr){
        cout << "\n Danh sach rong" << endl;
    
    } 
    else {
        Node* p= pHead;
        while (p != nullptr){
            cout << p -> info << "\t";
            p = p -> next;
        }
        cout << endl;
    } 
}

// Dùng for 
void ShowList2 (Node*& pHead){
    if (pHead == nullptr){
        cout << "\n Danh sach rong" << endl;

    }
    else {
        for (Node* p = pHead; p != nullptr; p = p -> next){
            cout << p -> info << "\t";
        } cout << endl;
    }
}



int main (){
// Tạo ví dụ một danh sách liên kết với 3 phần tử
Node* node1 = new Node { 10, nullptr };
Node* node2 = new Node { 20, nullptr };
Node* node3 = new Node { 30, nullptr };

// Nối các nút lại với nhau
node1->next = node2;
node2->next = node3;

// Sử dụng hàm ShowList để in danh sách
cout << "Duyet danh sach bang while:" << endl;
ShowList(node1);

// Sử dụng hàm ShowList2 để in danh sách
cout << "Duyet danh sach bang for:" << endl;
ShowList2(node1);

// Giải phóng bộ nhớ
delete node1;
delete node2;
delete node3;

    return 0;
}