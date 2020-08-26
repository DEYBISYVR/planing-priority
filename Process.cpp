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

    Node *aux = head;
    Node *aux2;

    while(aux != nullptr && aux->data.priority < newProcess.priority ){
        aux2 = aux;
        aux = aux->next;
    }

    if(head == aux){
        head = newNode;
    }else {
        aux2->next = newNode;
    }

    newNode->next = aux;
}

void show(Node *node) {
    Node *current = node;
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
