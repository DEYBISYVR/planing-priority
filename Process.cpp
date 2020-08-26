//
// Created by KTLDIAZ on 21/08/2020.
//

#include "Process.h"

void ask(const string& x) {
    cout << "Type the " + x;
}

void push(Node *&head) {
    Process newProcess{};
    Node* newNode = new Node;
    cin.ignore();
    ask("name:");
    cin.getline(newProcess.name,30);
    ask("priority:");
    cin >> newProcess.priority;
    ask("cpu:");
    cin >> newProcess.cpu;
    ask("time_arrived:");
    cin >> newProcess.time_arrived;
    cout << endl;
    newProcess.status = 0;
    newProcess.waiting_time = 0;
    newProcess.finished = 0;

    newNode->data= newProcess;

    Node *aux1 = head;
    Node *aux2;

    while (aux1 != nullptr && aux1->data.priority < newProcess.priority) {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (head == aux1) {
        head = newNode;
    } else {
        aux2->next = newNode;
    }

    newNode->next = aux1;
}

void sort(Node *&head){
    int swapped;

    Node *left;
    Node *right = nullptr;
    do {
        swapped = 0;
        left = head;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.priority == left->next->data.priority) {
                swapNodes(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;

    } while (swapped);
}

void swapNodes(Node *node1, Node *node2) {
    Process temp = node1->data;
    node1->data = node2 -> data;
    node2->data = temp;
}

void simulate(Node *&head){
    cout << "beta phase" << endl;
}

void show(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << "******************" << endl;
        cout << "Process: " << current->data.name << "\nPriority: " << current->data.priority
             << "\nCPU: " << current->data.cpu << "\nStatus: " <<  current->data.status
             << "\nTime arrived: " << current->data.time_arrived  << "\nWaiting time: "
             << current->data.waiting_time << "\nFinished: " << current->data.finished << endl;
        cout << "******************" << endl;
        current = current->next;
    }
}
