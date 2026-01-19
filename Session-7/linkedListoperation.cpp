#include <iostream>
using namespace std;
struct Node{
    int data;
    Node * Next;
    Node(int val){
        data=val;
        Next=nullptr;
    }
};
void insertAtStart(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->Next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->Next) {
        temp = temp->Next;
    }
    temp->Next = newNode;
}

void insertAtMid(Node* head, int val, int pos) {
    if (pos < 1) return;
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++) {
        temp = temp->Next;
    }
    if (temp) {
        newNode->Next = temp->Next;
        temp->Next = newNode;
    }
}

void deleteFromStart(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->Next;
    delete temp;
}

void deleteFromEnd(Node*& head) {
    if(!head)return;
    if(!head->Next) {
        delete head;
        head=nullptr;
        return;
    }
    Node*temp=head;
    while(temp->Next->Next) {
        temp=temp->Next;
    }
    delete temp->Next;
    temp->Next=nullptr;
}
void display(Node* head) {
    Node*temp=head;
    while(temp){
        cout<<temp->data<< " -> ";
        temp=temp->Next;
    }
    cout <<"NULL"<<endl;
}