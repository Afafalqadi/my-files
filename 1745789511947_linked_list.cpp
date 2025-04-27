#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "������� �����!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);

    cout << "������� ��� �������:\n";
    printList(head);

    deleteFromBeginning(head);

    cout << "������� ��� �����:\n";
    printList(head);

    return 0;
}
