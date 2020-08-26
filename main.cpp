#include <iostream>
#include "Process.h"

using namespace std;

Node *head = nullptr;
void menu();
void processMenu();
//void mmuMenu();

int main() {
    int option;
    do{
        menu();
        cin >> option;
        cout << endl;
        switch (option) {
            case 1:
                processMenu();
                break;
            case 2:
                cout << "Beta phase" << endl;
                break;
            default:
                cout << option << ": is not a valid option" << endl << endl;
        }
    }while (option < 3);
    cout << "Exiting program" << endl;
    return 0;
}

void menu(){
    cout << "1. Process settings \n2. MMU settings \n3. Exit \nSelect:" ;
}

void processMenu(){
    int option;
    cout << "1. Add a new process  \n2. Show all process \n3. Go back \nSelect:";
    cin  >> option;
    cout << endl;
    switch (option) {
        case 1:
            push(head);
            break;
        case 2:
            show(head);
            break;
        default:
            cout << option << ": in not a valid option" << endl;
    }
}
