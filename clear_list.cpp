#include <iostream>

using namespace std; 

struct Node {
    int info; 
    Node* next;
};

// Chèn 1 nút mới vào cuối danh sách liên kết
void insert(Node*& pHead, int n){
    Node* newNode = new Node {n, nullptr};
    if (pHead == nullptr){
        pHead = newNode;
        return n;
    }
    Node* temp = pHead; 
    while (temp -> next){
        temp = temp -> next;
    }
    temp -> next = newNode;
}



// xóa toàn bộ danh sách
void ClearList (Node*& pHead){
    Node*p;
    // lặp lại cho tới khi được xóa hết không gì trong danh sách
    while (pHead != nullptr){
        p = pHead;
        pHead = pHead -> next;
        delete p; 
    } // Hết while 
} // Hết ClearList


// Hàm in các giá trị trong danh sách 
void PrintList(Node*& pHead){
    while (pHead != nullptr){
        cout << pHeap -> info << " ";
        pHead = pHead -> next;
    }
    cout << endl;
}

main () {
Note* pHead = nullptr;
insert (pHead,1);
insert (pHead,2);
insert (pHead,3);
insert (pHead,4);

// in ra danh sách sau khi chèn 
cout << "Danh sanh sau khi chen: "; 
PrintList (pHead);
// xóa tát cả trong danh sách
ClearList(pHead);
cout << "Danh sach đã được xóa toàn bộ."; << endl;
PrintList (pHead);
    return 0;
}
