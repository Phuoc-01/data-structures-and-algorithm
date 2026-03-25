#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pNext;	
};

Node* initNode(int value){
	Node* p = new Node;
	p->data = value;
	p->pNext = NULL;
	return p;
}

struct list
{
	Node* pHead;
	Node* pTail;	
};

void initlist(list& l){
	l.pHead = NULL;
	l.pTail = NULL;
}

void addHead(list& l, Node* p){
	if (l.pHead == NULL){
		l.pHead = p;
		l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}

void addTail(list& l, Node* p){
	if (l.pTail == NULL){
		l.pHead = p;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;  
		l.pTail = p;
	}
}

void printListFor(list l){
	for (Node* p = l.pHead; p != NULL; p = p->pNext){
		cout << p->data << " ";
	}
	cout << endl;
}

void printListWhile(list l){
	Node* p = l.pHead;
	while (p != NULL){
		cout << p->data << " ";
		p = p->pNext;
	}
	cout << endl;
}


int main(){
	Node* p1 = initNode(10);
	Node* p2 = initNode(70);
	Node* p3 = initNode(32);
	
	list l;
	initlist(l);
	
	addHead(l, p1);
	addHead(l, p2);
	addTail(l, p3);  
	
	printListFor(l);
	printListWhile(l);
	
	return 0;
}