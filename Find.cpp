#include <iostream> 

using namespace std;

struct Node {
    int info;
    Node* next;
};

// Hàm chèn một nút mới vào cuối danh sách liên kết
void insert(Node*& pHead, int n) {
    // Tạo nút mới với giá trị n và con trỏ next trỏ đến nullptr
    Node* newNode = new Node { n, nullptr };
    
    // Nếu danh sách trống, nút mới trở thành đầu danh sách
    if (pHead == nullptr) {
        pHead = newNode;
        return;
    }
    
    // Duyệt đến nút cuối của danh sách
    Node* temp = pHead;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Gán nút mới vào cuối danh sách
    temp->next = newNode;
}


// Tìm kiếm tuần tự có nội dung là x
 Node* Find1 (Node* pHead, int x){
    bool found = false;
    Node* p = pHead;
    while (p != nullptr && !found) {
        if (p->info == x)
            found = true;   // Nếu tìm thấy, đánh dấu found = true
        else
            p = p->next;    // Nếu không, chuyển sang nút tiếp theo
    }
    // Nếu không tìm thấy, p sẽ là nullptr
    return p;
}
      

//X là nội dung cần tìm 
 Node* Find2(Node* pHead, int x){
    bool found = false;
    Node*p = pHead;
    while ((p != nullptr) && (! found)){
    if ( p -> info == x){
        found = true;

    }
    else {
        p = p -> next;
    } 
    }
    return p;  
}

// Tìm x trong danh sách đã có thứ tự 
 Node* Find3(Node*& pHead, int x){
Node*p = pHead;
while (p != nullptr) {
    if (p->info == x) {
        return p;         // Nếu tìm thấy, trả về nút đó
    } else if (p->info < x) {
        p = p->next;      // Nếu giá trị nhỏ hơn x, chuyển sang nút tiếp theo
    } else {
        // Nếu gặp nút có giá trị lớn hơn x thì không cần tìm tiếp (danh sách đã sắp xếp)
        return nullptr;
    }
}
return nullptr;           // Nếu không tìm thấy, trả về nullptr
}


main (){
Node* pHead = nullptr;

    insert {pHeap,1};
    insert {pHeap,2};
    insert {pHeap,3};
    insert {pHeap,4};
// Sử dụng các hàm tìm kiếm
Node* result1 = Find1(pHead, 3);
Node* result2 = Find2(pHead, 5);
Node* result3 = Find3(pHead, 2);

cout << "Ket qua tim kiem Find1 cho gia tri 3: ";
cout << (result1 ? to_string(result1->info) : "Not Found") << endl;

cout << "Ket qua tim kiem Find2 cho gia tri 5: ";
cout << (result2 ? to_string(result2->info) : "Not Found") << endl;

cout << "Ket qua tim kiem Find3 cho gia tri 2: ";
cout << (result3 ? to_string(result3->info) : "Not Found") << endl;

return 0;
}