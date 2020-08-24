//
// Created by KTLDIAZ on 24/08/2020.
//

#include "Process.h"

void ask(const string& x) {
    cout << "Type the " + x;
}

void push(Node **front, Node **rear) {
    int priority,time_arrived,cpu;
    string name;
    Node* newNode = (Node*)malloc(sizeof(Node));
    ask("name:");
    cin >> name;
    newNode->name = name;
    ask("priority:");
    cin >> priority;
    newNode->priority = priority;
    ask("cpu:");
    cin >> cpu;
    newNode->cpu = cpu;
    ask("time_arrived:");
    cin >>time_arrived;
    newNode->time_arrived = time_arrived;
    cout << endl;
    newNode->status = "ready";

    // If linked list is empty
    if (*front == nullptr) {
        *front = newNode;
        *rear = newNode;
        newNode->next = nullptr;
    }
    else {
        // If priority is less than or equal front node's priority, then insert at the front.
        if (priority <= (*front)->priority) {
            newNode->next = *front;
            (*front)->prev = newNode->next;
            *front = newNode;
        }
            // If priority is more rear node's priority, then insert after the rear.
        else if (priority > (*rear)->priority) {
            newNode->next = nullptr;
            (*rear)->next = newNode;
            newNode->prev = (*rear)->next;
            *rear = newNode;
        } else {
            // Handle other cases, find position where we need to insert
            Node* start = (*front)->next;
            while (start->priority > priority)
                start = start->next;
            (start->prev)->next = newNode;
            newNode->next = start->prev;
            newNode->prev = (start->prev)->next;
            start->prev = newNode->next;
        }
    }
}

void show(Node *node) {
    while (node != nullptr) {
        cout << "******************" << endl;
        cout << "Process: " << node->name << "\nPriority: " << node->priority
             << "\nCPU: " << node->cpu << "\nStatus: " <<  node->status
             << "\nTime arrived: " << node->time_arrived  << "\nWaiting time: "
             << node->waiting_time << "\nFinished: " << node->finished << endl;
        cout << "******************" << endl;
        node = node->next;
    }
}