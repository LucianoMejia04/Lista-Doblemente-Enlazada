
#include <iostream>
using namespace std;

struct Node {
	int dato;
    Node* prev;
	Node* next;
};

void addEnd(Node*& head, int valor) {

    //CREAR NUEVO NODO CON DATO INGRESADO
	Node* newnode = new Node;
	newnode->dato = valor;
	newnode->next = nullptr;
	newnode->prev = nullptr;
    
	if (head == nullptr) { //VERIFICA SI ES EL PRIMER NODO CREADO
		head = newnode;
	}
	else {//Y SI NO, EMPAREJA EL NODO CREADO CON EL ULTIMO NODO 
		Node* temp1 = head;
		
		while (temp1->next != nullptr) {
			temp1 = temp1->next;
		}
		temp1->next = newnode;
		newnode->prev = temp1;
	}
}

void imprimirList(Node*& head) {
	Node* temp1 = head;
	while (temp1 != nullptr) {
		cout << temp1->dato;
		temp1 = temp1->next;
	}

}

void addInicio(Node* head, int x) {

}

Node* buscar(Node* head, int d) {
    Node* temp1 = head;
        while (temp1 != nullptr ) {
            if (temp1->dato == d) {
                return temp1;
            }
            temp1 = temp1->next;
        }
}
void agregarAntDesp(Node* head, int numIngre, int despAntes , char x) {

    Node* newnode = new Node;
    newnode->dato = numIngre;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (x == 1) {
        Node* temp1 = buscar(head, despAntes);
        Node* temp2 = temp1->next;

        temp1->next = newnode;
        newnode->prev = temp1;

        newnode->next = temp2;
        temp2->prev = newnode;
    }
    else {
        Node* temp1 = buscar(head, despAntes);
        Node* temp2 = temp1->prev;

        temp1->next = newnode;
        newnode->prev = temp1;

        newnode->next = temp2;
        temp2->prev = newnode;
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

    system("cls");
    do {
        system("cls");
        int o;
        cout << endl;
        cout << "            MENU             " << endl;
        cout << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Imprimir Lista" << endl;
        cout << "4. Agregar numero despues de" << endl;
        cout << "5. Agregar numero antes de" << endl;
        cout << endl << "\t\t";
        cin >> o;

        switch (o) {
        case 1:
            system("cls");
            int x;
            cout << "Ingrese el nuevo dato: "; cin >> x;
            addInicio(head, x);
            cout << endl;
            cout << "Numero correctamente registrado";
            break;

        case 2:
            system("cls");
            int z;
            cout << "Ingrese el nuevo dato: "; cin >> z;
            addEnd(head, z);
            cout << endl;
            cout << "Numero correctamente registrado";
            break;

        case 3:
            system("cls");
            cout << endl << "\t";

            imprimirList(head);
            cout << endl;

            system("pause");
            break;

        case 4:
            system("cls");
            int g, q;
            cout << "Numero a ingresar: "; cin >> g;
            cout << "Despues del numero: "; cin >> q;
            agregarAntDesp(head, g, q, 1);
            cout << endl;
            system("pause");
            break;

        case 5:
            system("cls");
            int a, b;
            cout << "Numero a ingresar: "; cin >> a;
            cout << "Antes del numero : "; cin >> b;
            agregarAntDesp(head, a, b, 0);
            cout << endl;
            system("pause");
            break;
        }
    } while (o != 6);


	imprimirList(head);
}
