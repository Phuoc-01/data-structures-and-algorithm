#include <iostream>
using namespace std;

typedef int ElemType;
const int MaxSize = 100;

struct List
{
    ElemType data[MaxSize];
    int n;
    int maxsize;
};

void initList(List &L, int size) {
    L.n = 0;
    L.maxsize = size;
}

bool isEmpty(List L) {
    return L.n == 0;
}

bool isFull(List L) {
    return L.n == L.maxsize;
}

void addList(List &L, ElemType e) {
    if (isFull(L)) {
        cout << "List day" << endl;
        return;
    }
    L.data[L.n] = e;
    L.n++;
}

bool findElem(List L, ElemType x) {
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == x) {
            return true;
        }
    }
    return false;
}

void printList(List L) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    for (int i = 0; i < L.n; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void findElemAndPrint(List L, ElemType x) {
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == x) {
            cout << "Co trong danh sach" << endl;
            return;
        }
    }
    cout << "Khong tim thay " << x << endl;
}

void findElemIndex(List L, ElemType x) {
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == x) {
            cout << "Chi so cua gia tri " << x << " la: " << i << endl;
            return;
        }
    }
    cout << "Chi so cua gia tri " << x << " la: -1" << endl;
}

void insertElem(List &L, ElemType x, int k) {
    if (isFull(L)) {
        cout << "List day" << endl;
        return;
    }
    if (k < 0 || k > L.n) {
        cout << "Vi tri chen khong hop le" << endl;
        return;
    }
    
    for (int i = L.n; i > k; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[k] = x;
    L.n++;
    cout << "Da chen " << x << " vao vi tri " << k << endl;
}

void deleteElem(List &L, ElemType x) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    
    int index = -1;
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == x) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        cout << "Khong tim thay phan tu " << x << endl;
        return;
    }
    
    for (int i = index; i < L.n - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.n--;
    cout << "Da xoa phan tu " << x << endl;
}

void bubbleSort(List &L) {
    if (isEmpty(L)) {
        cout << "List rong, khong the sap xep" << endl;
        return;
    }
    
    for (int i = 0; i < L.n - 1; i++) {
        for (int j = 0; j < L.n - i - 1; j++) {
            if (L.data[j] > L.data[j + 1]) {
                swap(L.data[j], L.data[j + 1]);
            }
        }
    }
    cout << "Da sap xep list tang dan" << endl;
}

void deletePos(List &L, int k) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    if (k < 0 || k >= L.n) {
        cout << "Vi tri xoa khong hop le" << endl;
        return;
    }
    
    for (int i = k; i < L.n - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.n--;
    cout << "Da xoa phan tu tai vi tri " << k << endl;
}

void deleteFirst(List &L) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    deletePos(L, 0);
}

void deleteLast(List &L) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    L.n--;
    cout << "Da xoa phan tu cuoi cung" << endl;
}

void findMax(List L) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    
    ElemType max = L.data[0];
    cout << "Cac vi tri co gia tri lon nhat: ";
    
    for (int i = 1; i < L.n; i++) {
        if (L.data[i] > max) {
            max = L.data[i];
        }
    }
    
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == max) {
            cout << i << " ";
        }
    }
    cout << "(gia tri lon nhat: " << max << ")" << endl;
}

void swapElemByValue(List &L, ElemType x, ElemType y) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    
    int index1 = -1, index2 = -1;
    for (int i = 0; i < L.n; i++) {
        if (L.data[i] == x) index1 = i;
        if (L.data[i] == y) index2 = i;
    }
    
    if (index1 != -1 && index2 != -1) {
        swap(L.data[index1], L.data[index2]);
        cout << "Da hoan doi " << x << " va " << y << endl;
    } else {
        cout << "Khong tim thay ca hai phan tu can hoan doi" << endl;
    }
}

void swapElemByIndex(List &L, int i, int j) {
    if (isEmpty(L)) {
        cout << "List rong" << endl;
        return;
    }
    if (i < 0 || i >= L.n || j < 0 || j >= L.n) {
        cout << "Chi so khong hop le" << endl;
        return;
    }
    
    swap(L.data[i], L.data[j]);
    cout << "Da hoan doi phan tu tai vi tri " << i << " va " << j << endl;
}

int main() {
    List L;
    int size;
    
    cout << "Nhap kich thuoc toi da cua List: ";
    cin >> size;
    
    if (size > MaxSize) {
        cout << "Kich thuoc khong duoc vuot qua " << MaxSize << endl;
        cout << "Tu dong dat kich thuoc = " << MaxSize << endl;
        size = MaxSize;
    }
    
    initList(L, size);
    cout << "Da khoi tao list voi kich thuoc toi da " << size << endl;
    
    int choice;
    ElemType x, y;
    int k, i, j;
    
    do {
        cout << "1. Them phan tu vao cuoi list" << endl;
        cout << "2. In list" << endl;
        cout << "3. Tim kiem phan tu (co/khong)" << endl;
        cout << "4. Tim chi so cua phan tu" << endl;
        cout << "5. Chen phan tu vao vi tri bat ky" << endl;
        cout << "6. Xoa phan tu theo gia tri" << endl;
        cout << "7. Xoa phan tu theo vi tri" << endl;
        cout << "8. Xoa phan tu dau tien" << endl;
        cout << "9. Xoa phan tu cuoi cung" << endl;
        cout << "10. Sap xep list tang dan (Bubble Sort)" << endl;
        cout << "11. Tim gia tri lon nhat va vi tri" << endl;
        cout << "12. Hoan doi 2 phan tu theo gia tri" << endl;
        cout << "13. Hoan doi 2 phan tu theo vi tri" << endl;
        cout << "14. Kiem tra list rong" << endl;
        cout << "15. Kiem tra list day" << endl;
        cout << "16. Dem so phan tu trong list" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Nhap gia tri can them: ";
                cin >> x;
                addList(L, x);
                cout << "Da them " << x << " vao list" << endl;
                break;
                
            case 2:
                printList(L);
                break;
                
            case 3:
                if (isEmpty(L)) {
                    cout << "List rong, khong the tim kiem" << endl;
                } else {
                    cout << "Nhap gia tri can tim: ";
                    cin >> x;
                    findElemAndPrint(L, x);
                }
                break;
                
            case 4:
                if (isEmpty(L)) {
                    cout << "List rong, khong the tim kiem" << endl;
                } else {
                    cout << "Nhap gia tri can tim chi so: ";
                    cin >> x;
                    findElemIndex(L, x);
                }
                break;
                
            case 5:
                if (isFull(L)) {
                    cout << "List da day, khong the chen them" << endl;
                } else {
                    cout << "Nhap gia tri can chen: ";
                    cin >> x;
                    cout << "Nhap vi tri can chen (0 - " << L.n << "): ";
                    cin >> k;
                    insertElem(L, x, k);
                }
                break;
                
            case 6:
                if (isEmpty(L)) {
                    cout << "List rong, khong the xoa" << endl;
                } else {
                    cout << "Nhap gia tri can xoa: ";
                    cin >> x;
                    deleteElem(L, x);
                }
                break;
                
            case 7:
                if (isEmpty(L)) {
                    cout << "List rong, khong the xoa" << endl;
                } else {
                    cout << "Nhap vi tri can xoa (0 - " << L.n-1 << "): ";
                    cin >> k;
                    deletePos(L, k);
                }
                break;
                
            case 8:
                deleteFirst(L);
                break;
                
            case 9:
                deleteLast(L);
                break;
                
            case 10:
                if (isEmpty(L)) {
                    cout << "List rong, khong the sap xep" << endl;
                } else {
                    bubbleSort(L);
                    printList(L);
                }
                break;
                
            case 11:
                findMax(L);
                break;
                
            case 12:
                if (isEmpty(L)) {
                    cout << "List rong, khong the hoan doi" << endl;
                } else if (L.n < 2) {
                    cout << "Can it nhat 2 phan tu de hoan doi" << endl;
                } else {
                    cout << "Nhap gia tri thu nhat: ";
                    cin >> x;
                    cout << "Nhap gia tri thu hai: ";
                    cin >> y;
                    swapElemByValue(L, x, y);
                    printList(L);
                }
                break;
                
            case 13:
                if (isEmpty(L)) {
                    cout << "List rong, khong the hoan doi" << endl;
                } else if (L.n < 2) {
                    cout << "Can it nhat 2 phan tu de hoan doi" << endl;
                } else {
                    cout << "Nhap vi tri thu nhat (0 - " << L.n-1 << "): ";
                    cin >> i;
                    cout << "Nhap vi tri thu hai (0 - " << L.n-1 << "): ";
                    cin >> j;
                    swapElemByIndex(L, i, j);
                    printList(L);
                }
                break;
                
            case 14:
                if (isEmpty(L))
                    cout << "List dang RONG" << endl;
                else
                    cout << "List KHONG rong" << endl;
                break;
                
            case 15:
                if (isFull(L))
                    cout << "List da DAY" << endl;
                else
                    cout << "List chua day (con " << L.maxsize - L.n << " cho trong)" << endl;
                break;
                
            case 16:
                cout << "So phan tu hien co trong list: " << L.n << endl;
                break;
                
            case 0:
                cout<< "error value to choice"<<endl;
                break;
                
            default:
                cout << "Lua chon khong hop le! Vui long chon lai." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}