#include <iostream>

using namespace std;

struct Node{
    int info;
    Node* next;
};

// Kiểm tra 1 danh sách rỗng 
bool isEmpty (Node* pHead){
    pHead == nullptr;
}

// Tạo 1 node
void Init (Node*& pHead){
pHead = nullptr;
}
Node* CreatorNode (int x){
    Node* p= new NOde;
    p-> info = x;
    p -> next = nullptr;
    return p;
}

main (){
    Node* pHead;
    Init(pHead); // Khởi tạo danh sách rỗng

    // Kiểm tra danh sách có rỗng không
    cout << "Danh sach rong: " << (isEmpty(pHead) ? "true" : "false") << endl;

    // Tạo một node mới với giá trị 10 và gán làm đầu danh sách
    pHead = CreatorNode(10);

    // Kiểm tra lại danh sách sau khi thêm phần tử
    cout << "Sau khi them node, danh sach rong: " << (isEmpty(pHead) ? "true" : "false") << endl;
    cout << "Gia tri cua node dau tien: " << pHead->info << endl;

    return 0;
}