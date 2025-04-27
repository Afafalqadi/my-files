#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;	
};
node* head = nullptr;

void addnode() {
    node* newnode = new node();
    cout << "Enter data to add: ";
    cin >> newnode->data;
    newnode->next = nullptr;
     newnode->next = nullptr;

    if (head == nullptr) {
        head = newnode;
    } else {
        node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        current->next = newnode;
        newnode->prev=current;
    }
    cout << "Node added." << endl;
}

void deletenode() {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    int deletevalue;
    cout << "Enter value to delete: ";
    cin >> deletevalue;

    if (head->data == deletevalue) {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted." << endl;
        return;
    }

    node* current = head;
    node* prev = nullptr;
    while (current != nullptr && current->data != deletevalue) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Value not found in the list." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Node deleted." << endl;
}

void displaylist() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    node* current = head;
    cout << " the List: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void bubbleSort() {
    if (head == nullptr || head->next == nullptr)
        return;

    bool swapped;
    node* ptr1;
    node* ptr2 = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);

    cout << "List sorted ." << endl;
}


int main() {
    int choice;
    do {
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display List\n";
        cout << "4. Sort List \n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addnode();
                break;
            case 2:
                deletenode();
                break;
            case 3:
                displaylist();
                break;
            case 4:
                bubbleSort();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. " << endl;
        }
    } while (choice != 5);

    return 0;
}
