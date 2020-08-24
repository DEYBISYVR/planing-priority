//
// Created by KTLDIAZ on 21/08/2020.
//

#ifndef TASKMANAGER_PROCESS_H
#define TASKMANAGER_PROCESS_H

#include <string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    string name;
    string status;
    int priority;
    int cpu;
    int time_arrived;
    int waiting_time = 0;
    int finished = 0;
    struct Node *prev,*next;
};

void ask(const string& x);
void show(Node*  node);
void push(Node** front, Node** rear);

#endif //TASKMANAGER_PROCESS_H
