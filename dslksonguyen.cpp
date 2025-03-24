/* Bài 1. Danh sách liên kết số nguyên
(a) Cài đặt CTDL ListInt dùng để chứa các số nguyên, trong đó:
• Sử dụng danh sách liên kết
• Cài đặt các phép toán: khởi tạo, hủy, thêm phần tử, xóa phần tử, thêm một danh sách phần tử, xuất danh sách
(b) Viết thành chương trình:
• Nhập 10 số nguyên và đưa vào danh sách
• In danh sách ra màn hình
• Nhập một số k và xóa số k trong danh sách
• In danh sách sau khi xóa phần tử
• Nhập 5 số nguyên vào một danh sách thứ hai
• Thêm danh sách thứ hai vào danh sách thứ nhất
• In danh sách thứ nhất ra màn hình*/

#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

// Khởi tạo danh ds liên kết
 void ListInt (Node*& pHead){
    pHead = nullptr;
}

//Hàm chèn 1 nút cuối danh sách liên kết
void Insert(Node*& pHead, int n) {
    Node* newNode = new Node {n, nullptr};
    if (!pHead) {
        pHead = newNode;
        return;
    }
    Node* temp = pHead;
   while (temp -> next ) {
    temp = temp -> next;
   }
   temp -> next = newNode;
}

// Xóa 1 phần tử k trong danh sách
void Xoa(Node*& pHead, int k){
    if (!pHead) return;
// Nếu phần tử đầu tiên là k
if (pHead->info == k){
    Node* temp = pHead;
    pHead = pHead-> next;
    delete temp;
    return; 

}
Node* temp = pHead;
while (temp-> next && temp-> next ->info != k ){
    temp = temp -> next;
}
// tìm thấy k
if (temp -> next){
    Node* toDelete = temp-> next;
    temp-> next = temp->next -> next;
    delete toDelete;
}
}
// Hàm hiển thị danh sách liên kết
void PrintList (Node* pHead){
    if (!pHead){
        cout <<"Ds rong \n";
        return;
    }
    while (pHead){
        cout << pHead -> info <<" " ; 
        pHead = pHead -> next;
    }
    cout << endl; 
}

 // Hàm thêm 1 danh sách liên kết thứ 2 
 void Merge(Node*& pHead1, Node*& pHead2) {
    if (!pHead1) {
        pHead1 = pHead2;
    } else {
        Node* temp = pHead1;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = pHead2;
    }
    pHead2 = nullptr;  // Tránh giải phóng trùng lặp
}
// xóa toàn bộ danh sách
void ClearList (Node*& pHead){
    Node* temp;
    // lặp lại cho tới khi được xóa hết không gì trong danh sách
    while (pHead){
        temp = pHead;
        pHead = pHead -> next;
        delete temp; 
    } // Hết while 
} // Hết ClearList


int main (){
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    ListInt (list1);
    ListInt (list2);

    // nhập 10 số nguyên từ bàn phím 
cout <<"Nhap 10 so nguyen vao ds 1: \n";
for (int i = 0; i < 10; i++){
    int x;
    cin >> x;
    Insert(list1, x);
}
    // In ra danh sách màn hình 
cout << "Danh sanh 1: ";
PrintList(list1);
    // nhập số k từ bàn phím và xóa 
    int k;
    cout << "Nhap so k can xoa: ";
    cin >> k;
    Xoa(list1, k);
    // In ra ds sau khi xóa 
    cout <<"Danh sach sau khi xoa" << k << ": ";
    PrintList(list1);

    // nhập 5 số nguyên từ bàn phím vào 1 danh sách thứ 2
    cout <<"Nhap 5 so nguyen cho ds 2: \n";
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x ;
        Insert(list2, x);
    }
    // Thêm danh sách 2 vào chính danh sách 1 
Merge(list1, list2);

    // In ra danh sách 1 hoàn chỉnh sau khi đã xóa k và thêm danh sách 2 vào phần tử 1
cout << "Danh sach cuoi: ";
PrintList(list1);

// Giải phóng bộ nhớ
ClearList(list1);

    return 0;
}

/*Nhap 10 so nguyen vao ds 1: 
1 2 3 4 5 6 7 8 9 10 
Danh sanh 1: 1 2 3 4 5 6 7 8 9 10 
Nhap so k can xoa: 1
Danh sach sau khi xoa1: 2 3 4 5 6 7 8 9 10 
Nhap 5 so nguyen cho ds 2: 
1 2 3 4 5
Danh sach cuoi: 2 3 4 5 6 7 8 9 10 1 2 3 4 5  */