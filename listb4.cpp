#include <iostream>
using namespace std;

typedef int elementtype;
typedef struct node *list;

struct node {
    elementtype data;
    node *next;
};

void init(list &l) {
    l = NULL;
}

int isEmpty(list l) {
    return (l == NULL);
}

void print(list l) {
    if (isEmpty(l)) {
        cout << "Rong" << endl;
        return;
    }
    node *p = l;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void nhandoi(list l) {
    if (isEmpty(l)) return;
    node* p = l;
    while (p != NULL) {
        p->data = 2 * p->data;
        p = p->next;
    }
}

void addLast(list &l, elementtype x) {
    node* newnode = new node;
    newnode->data = x;
    newnode->next = NULL;

    if (l == NULL) {
        l = newnode;
    } else {
        node* p = l;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = newnode;
    }
}

void addTop(list &l, elementtype x) {
    node* newnode = new node;
    newnode->data = x;
    newnode->next = l;
    l = newnode;
}

bool check(list l, node* p) {
    if (p == NULL) return false;
    node* q = l;
    while (q != NULL) {
        if (q == p) return true;
        q = q->next;
    }
    return false;
}

void addAfter(list &l, elementtype x, node* p) {
    if (!check(l, p)) return;
    node* q = new node;
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void addBefore(list &l, elementtype x, node* p) {
    if (!check(l, p)) return;
    
    if (p == l) {
        addTop(l, x);
        return;
    }
    
    node* q = new node;
    node* t = l;
    
    while (t->next != p) {
        t = t->next;
    }
    
    q->data = x;
    q->next = p;
    t->next = q;
}

node* find(list l, elementtype x) {
    node* p = l;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->next;
    }
    return NULL;
}

void deleteNodeTop(list &l) {
    if (isEmpty(l)) return;
    node* p = l;
    l = l->next;
    delete p;
}

void deleteNodeLast(list &l) {
    if (isEmpty(l)) return;
    node* p = l;
    node* q = NULL;
    
    while (p->next != NULL) {
        q = p;
        p = p->next;
    }
    
    if (q == NULL) {
        l = NULL;
    } else {
        q->next = NULL;
    }
    delete p;
}

void count(list l) {
    int count = 0;
    node* p = l;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    cout << "So luong node: " << count << endl;
}

void deleteNode(list &l, node* p) {
    if (!check(l, p)) return;
    
    if (p == l) {
        deleteNodeTop(l);
        return;
    }
    
    node* q = l;
    while (q->next != p) {
        q = q->next;
    }
    
    q->next = p->next;
    delete p;
}

void deleteList(list &l) {
    node* p = l;
    while (p != NULL) {
        node* q = p;
        p = p->next;
        delete q;
    }
    l = NULL;
}

int main() {
    list myList;
    init(myList);
    int choice, x;
    node* p;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them node vao cuoi\n";
        cout << "2. Them node vao dau\n";
        cout << "3. Them node sau node p\n";
        cout << "4. Them node truoc node p\n";
        cout << "5. Tim node co gia tri x\n";
        cout << "6. Xoa node dau\n";
        cout << "7. Xoa node cuoi\n";
        cout << "8. Xoa node p\n";
        cout << "9. Nhan doi gia tri cac node\n";
        cout << "10. Dem so luong node\n";
        cout << "11. In list\n";
        cout << "12. Xoa toan bo list\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Nhap gia tri: ";
                cin >> x;
                addLast(myList, x);
                break;
                
            case 2:
                cout << "Nhap gia tri: ";
                cin >> x;
                addTop(myList, x);
                break;
                
            case 3:
                cout << "Nhap gia tri: ";
                cin >> x;
                cout << "Nhap gia tri node p can tim: ";
                cin >> x;
                p = find(myList, x);
                if(p != NULL) {
                    cout << "Nhap gia tri node moi: ";
                    cin >> x;
                    addAfter(myList, x, p);
                } else {
                    cout << "Khong tim thay node p!\n";
                }
                break;
                
            case 4:
                cout << "Nhap gia tri: ";
                cin >> x;
                cout << "Nhap gia tri node p can tim: ";
                cin >> x;
                p = find(myList, x);
                if(p != NULL) {
                    cout << "Nhap gia tri node moi: ";
                    cin >> x;
                    addBefore(myList, x, p);
                } else {
                    cout << "Khong tim thay node p!\n";
                }
                break;
                
            case 5:
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                p = find(myList, x);
                if(p != NULL) {
                    cout << "Tim thay node co gia tri " << x << endl;
                } else {
                    cout << "Khong tim thay!\n";
                }
                break;
                
            case 6:
                deleteNodeTop(myList);
                cout << "Da xoa node dau\n";
                break;
                
            case 7:
                deleteNodeLast(myList);
                cout << "Da xoa node cuoi\n";
                break;
                
            case 8:
                cout << "Nhap gia tri node p can xoa: ";
                cin >> x;
                p = find(myList, x);
                if(p != NULL) {
                    deleteNode(myList, p);
                    cout << "Da xoa node " << x << endl;
                } else {
                    cout << "Khong tim thay node!\n";
                }
                break;
                
            case 9:
                nhandoi(myList);
                cout << "Da nhan doi gia tri cac node\n";
                break;
                
            case 10:
                count(myList);
                break;
                
            case 11:
                cout << "List: ";
                print(myList);
                break;
                
            case 12:
                deleteList(myList);
                cout << "Da xoa toan bo list\n";
                break;
                
            case 0:
                deleteList(myList);
                break;
                
            default:
                cout << "Lua chon khong hop le!\n";
        }
    } while(choice != 0);

    return 0;
}