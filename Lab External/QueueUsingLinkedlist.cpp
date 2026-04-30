#include <iostream>
using namespace std;
class Node {
public:   int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Queue {
private:   Node* front;
    Node* rear;
public:   Queue() {
        front = rear = nullptr;
    }
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void isFull() {
        try {
            Node* temp = new Node(0);
            delete temp;
            cout << "Queue is not full!" << endl;
        } catch (bad_alloc& e) {
            cout << "Queue is full!" << endl;
        }
    }
};

