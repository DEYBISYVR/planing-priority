//
// Created by KTLDIAZ on 21/08/2020.
//

#ifndef TASKMANAGER_PROCESS_H
#define TASKMANAGER_PROCESS_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct Process {
    char name[30];
    int status; //1 = ready, 2 = finished, 3 = blocked
    int priority;
    int cpu;
    int time_arrived;
    int waiting_time;
    int finished;
};

struct Node {
    Process data;
    struct Node *next;
};

void ask(const string& x);
void show(Node *);
void push(Node *&);

#endif //TASKMANAGER_PROCESS_H
