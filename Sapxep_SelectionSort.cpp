# include <iostream>

using namespace std;

struct Node {
    int info; 
    Node* next; 

};

void SelectionSort (Node*& pHead)
// Sắp xếp danh sách tăng dần 
{
    Node*p, *q, pmin; 
    int vmin;
    for (p = pHead; p -> next != nullptr; p= p -> next){
        vmin = p -> info;
        pmin = p;
        // Tìm phần tử nhỏ nhất trong phần còn lại của danh sách
        for (q = p -> next; q != nullptr; q = q -> next){
            if (q -> info < vmin){
                vmin = q -> info;
                pmin = q;
            } // hết if 
        } // hết for q 
        // Hoán  đổi giá trị của p với pmin
    if (pmin != p){
        swap (p -> info, pmin -> info);
    }
    }
} // hết for p
// hết sort 

// Hàm hiển thị danh sách liên kết
void PrintList (Node* pHead){
    while (pHead){
        cout << pHead -> info <<" " ; 
        pHead = pHead -> next;
    }
    cout << endl; 
}

//Hàm chèn 1 nút cuối danh sách liên kết
void Insert(Node*& pHead, int n);{
    Node* newNode = new Node {x, nullptr};
    if (pHead) {
        pHeap = newNode;
        return n;
    }
    Node* temp = pHead;
   while (temp -> next ) {
    temp = temp -> next;
   }
   temp -> next = newNode;
}


main () {
    Node* pHead = nullptr;
    // Chèn 1 số phần tử vào danh sách 
    Insert (pHead,1);
    Insert (pHead,2);
    Insert (pHead,3);
    Insert (pHead,4);
    
    //in ra danh sách trước và sau khi đã được sort
    cout << "Danh sach:" ; 
    PrintList (pHead); 
    SelectionSort(pHead);
    cout << "Danh sach sap xep:";
    PrintList (pHead);


    return 0;
}