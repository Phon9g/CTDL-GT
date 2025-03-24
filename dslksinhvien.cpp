#include <iostream>
#include <cstring>

using namespace std;

struct SinhVien {
    char HoTen[50];
    char DiaChi[70];
    char Lop[10];
    int Khoa;
};

struct Node {
    SinhVien data;
    Node* next;
};

// Khởi tạo danh sách liên kết
void KhoiTaoDanhSach(Node*& pHead) {
    pHead = nullptr;
}

// Nhập thông tin của sinh viên
void ThongTin(SinhVien& sv) {
    cout << " Ho va ten: ";
    cin.ignore();
    cin.getline(sv.HoTen, 50);
    cout << " dia chi: ";
    cin.getline(sv.DiaChi, 70);
    cout <<" lop: ";
    cin.getline(sv.Lop, 10);
    cout <<" Khoa: ";
    cin >> sv.Khoa;
    cin.ignore();
}

// In thông tin sinh viên
void InThongTin(SinhVien sv) {
    cout << sv.HoTen << " , " << sv.DiaChi << " , " << sv.Lop << " , " << sv.Khoa << endl;
}

// Thêm sinh viên vào danh sách
void Them(Node*& pHead, SinhVien sv) {
    Node* newNode = new Node;
    newNode->data = sv;
    newNode->next = pHead;
    pHead = newNode;
}

// Xuất danh sách sinh viên
void Xuat(Node* pHead) {
    if (!pHead) {
        cout << " Ds rong \n";
        return;
    }
    Node* temp = pHead;
    while (temp) {
        InThongTin(temp->data);
        temp = temp->next;
    }
}

// Xóa sinh viên theo tên
void Xoa1(Node*& pHead, const char* ten) {
    Node* temp = pHead;
    Node* prev = nullptr;

    while (temp) {
        if (strcmp(temp->data.HoTen, ten) == 0) {
            if (prev == nullptr) {
                pHead = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Xóa sinh viên theo địa chỉ
void Xoa2(Node*& pHead, const char* diachi) {
    Node* temp = pHead;
    Node* prev = nullptr;

    while (temp) {
        if (strcmp(temp->data.DiaChi, diachi) == 0) {
            if (prev == nullptr) {
                pHead = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// So sánh theo họ tên
bool SoSanh(SinhVien a, SinhVien b) {
    return strcmp(a.HoTen, b.HoTen) < 0;
}

// Sắp xếp sinh viên bằng selection sort
void SelectionSort(Node*& pHead, bool (*cmp)(SinhVien, SinhVien)) {
    for (Node* p = pHead; p; p = p->next) {
        Node* minNode = p;
        for (Node* q = p->next; q; q = q->next) {
            if (cmp(q->data, minNode->data)) {
                minNode = q;
            }
        }
        if (minNode != p) {
            swap(p->data, minNode->data);
        }
    }
}

// Xóa toàn bộ danh sách
void ClearList(Node*& pHead) {
    Node* temp;
    while (pHead) {
        temp = pHead;
        pHead = pHead->next;
        delete temp;
    }
}

int main() {
    Node* DanhSach;
    KhoiTaoDanhSach(DanhSach);

    // Nhập 10 sinh viên vào danh sách
    cout << "Nhap 10 sinh vien: \n";
    for (int i = 0; i < 10; i++) {
        SinhVien sv;
        ThongTin(sv);
        Them(DanhSach, sv);
    }

    // In danh sách ra màn hình
    cout << "\nDanh sach sinh vien vua nhap:\n";
    Xuat(DanhSach);
    // Xóa sinh viên có tên "Nguyen Van Teo"
    Xoa1(DanhSach, "Nguyen Van Teo");
    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    Xoa2(DanhSach, "Nguyen Van Cu");
    // Thêm sinh viên mới
    SinhVien sv = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    Them(DanhSach, sv);
    cout << "\nDanh sach sau khi them/xoa:\n";
    Xuat(DanhSach);
    // Sắp xếp danh sách theo tên
    SelectionSort(DanhSach, SoSanh);
    cout << "\nDanh sach sau khi sap xep theo ten:\n";
    Xuat(DanhSach);
    // Giải phóng bộ nhớ
    ClearList(DanhSach);

    return 0;
}
