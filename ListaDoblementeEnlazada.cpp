

#include <iostream>
using namespace std;

struct Node {
	int dato;
	Node* next;
	Node* prev;
};

void addEnd(Node*& head, int valor) {

	Node* newnode = new Node;
	newnode->dato = valor;
	newnode->next = nullptr;
	newnode->prev = nullptr;

	if (head == nullptr) {
		head = newnode;
	}
	else {
		Node* temp1 = head;
		while (temp1->next != nullptr) {
			temp1 = temp1->next;
		}
	}
}

int main()  {

	int n, m;
	Node* head = nullptr;
	cout << "Ingrese el n de la lista: "; cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "Ingrese el " << i + 1 << " dato: "; cin >> m;
		addEnd(head, m);
	}


}
