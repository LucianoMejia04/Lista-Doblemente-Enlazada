
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

void addInicio(Node*& head, int x) {
    Node* newnode = new Node;
    newnode->dato = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (head == nullptr) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

Node* buscar(Node* head, int d) {
    Node* temp1 = head;
        do {
            temp1 = temp1->next;
        } while (temp1->dato != d && temp1 != nullptr);
        return temp1;
}

void agregarAntDesp(Node* head, int numIngre, int despAntes , char x) {

    // 1 = despues
    if (x == 1) {
        Node* temp1 = buscar(head, despAntes);
        Node* temp2 = temp1->next;

        if (temp1->next == nullptr) {
            addEnd(temp1, numIngre);
        }
        else {
            Node* newnode = new Node;
            newnode->dato = numIngre;
            newnode->next = nullptr;
            newnode->prev = nullptr;

            temp1->next = newnode;
            newnode->prev = temp1;

            newnode->next = temp2;
            temp2->prev = newnode;
        }
    }
    else {
        Node* temp1 = buscar(head, despAntes);
        Node* temp2 = temp1->prev;

        if (temp1->next == nullptr) {
            addEnd(temp1, numIngre);
        }
        else {
            Node* newnode = new Node;
            newnode->dato = numIngre;
            newnode->next = nullptr;
            newnode->prev = nullptr;

            temp1->next = newnode;
            newnode->prev = temp1;

            newnode->next = temp2;
            temp2->prev = newnode;
        }
    }

}

void eliminarNumero(Node*& head) {
    int op;

    do {
        cout << "1. Eliminar primer n�mero\n";
        cout << "2. Eliminar un n�mero espec�fico\n";
        cout << "3. Eliminar �ltimo n�mero\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opci�n: ";
        cin >> op;

        switch (op) {
        case 1: {
            if (head == nullptr) {
                cout << "La lista est� vac�a." << endl;
                break;
            }

            Node* temp1 = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp1;
            cout << "Primer n�mero eliminado." << endl;
            break;
        }

        case 2: {
            int x;
            cout << "Ingrese el n�mero a eliminar: ";
            cin >> x;

            Node* temp3 = buscar(head, x);

            if (temp3 == nullptr) {
                cout << "N�mero no encontrado." << endl;
                break;
            }

            if (temp3->prev != nullptr) {
                temp3->prev->next = temp3->next;
            }
            else {
                head = temp3->next;
            }

            if (temp3->next != nullptr) {
                temp3->next->prev = temp3->prev;
            }

            delete temp3;
            cout << "N�mero eliminado." << endl;
            break;
        }

        case 3: {
            if (head == nullptr) {
                cout << "La lista est� vac�a." << endl;
                break;
            }

            Node* temp4 = head;

            while (temp4->next != nullptr) {
                temp4 = temp4->next;
            }

            if (temp4->prev != nullptr) {
                temp4->prev->next = nullptr;
            }
            else {
                head = nullptr;
            }

            delete temp4;
            cout << "�ltimo n�mero eliminado." << endl;
            break;
        }

        case 4:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opci�n no v�lida, intente de nuevo." << endl;
            break;
        }

    } while (op != 4);
}


/*void eliminarTodo(Node*& head) {

}

void editarNumero(Node*& head) {

}*/

int main() {

    int n, m, o;
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
        cout << endl;
        cout << "            MENU             " << endl;
        cout << endl;
        cout << "1. Agregar al inicio" << endl;
        cout << "2. Agregar al final" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. Agregar numero despues de" << endl;
        cout << "5. Agregar numero antes de" << endl;
        cout << "6. Eliminar numero" << endl;
        cout << "7. Eliminar todo" << endl;
        cout << "8. Editar numero" << endl;
        cout << "9. Salir" << endl;

        cout << endl << "\t\t";
        imprimirList(head);
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

        case 6:
            system("cls");
            //eliminarNumero(head);
            break;

        case 7:
            system("cls");

            break;

        case 8:
            system("cls");

            break;

        default:
            cout << "Opcion no valida, por favor intente denuevo" << endl;
            system("pause");
            break;
        }
    } while (o != 9);
}