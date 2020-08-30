#include <iostream>
#include "Process.h"

using namespace std;

int cpu = 0;
Node *head = nullptr;
void menu();
void processMenu();
void ask(const string& x);
int ValidateInt(string);
Process add();
//void mmuMenu();

int main() {
    int option;
    int quantum = 4;
    do {
        system("cls");
        menu();
        option = ValidateInt("\nSelect: ") ;
        cout << endl;
        switch (option) {
            case 1:
                system("cls");
                processMenu();
                break;
            case 2:
                cout << "Beta phase" << endl;
                break;
            case 3:
                system("cls");
                ask("Quantum: ");
                cin >> quantum;
                break;
            case 4:
                sort(head);
                system("cls");
                simulate(head, cpu, quantum);
                break;
            default:
                cout << option << ": is not a valid option" << endl << endl;
        }
    }while (option < 5);
    cout << "Exiting program" << endl;
    return 0;
}

void menu(){
    cout << "1. Process settings \n2. MMU settings \n3.Quantum \n4. Simulate \n5. Exit" ;
}

void processMenu(){
    int option;
    cout << "1. Add a new process  \n2. Show all process \n3. Go back \nSelect:";
    option = ValidateInt("\nSelect: ");
    cout << endl;
    switch (option) {
        case 1: {
            system("cls");
            Process newProcess = add();
            cpu += newProcess.cpu;
            push(head,newProcess);
            break;
        }
        case 2: {
 	        system("cls");
            show(head);
            break;
        }
        case 3: {
            cout << endl;
            break;
        }
        default:
            cout << option << ": is not a valid option" << endl;
    }
}

int ValidateInt(string description){
	int number, cont = 0;
   	bool next;

	do {
	  next = false;
	  cin.clear();
	  if(cont > 0) cin.ignore(1024, '\n');
	  cout <<description;
	  cin >> number;
	  cont++;
	  if(cin.fail() && cin.rdstate()){
	     cout<<"\t\t\t\t\tERROR is not a valid option, introduzca un entero." << endl;
	     cout<<endl;
		 next = true;
	  }
	} while (next);
	
	return number;
}

void ask(const string& x) {
    cout << "Type the " + x;
}

Process add() {
    Process newProcess{};
    cin.ignore();
    ask("name:");
    cin.getline(newProcess.name,30);
   newProcess.priority = ValidateInt("Priority: ");
    newProcess.cpu = ValidateInt("Cpu: ");
    newProcess.time_arrived = ValidateInt("Time arrived: ");
    cout << endl;
    newProcess.status = "ready";
    newProcess.waiting_time = 0;
    newProcess.success_time = 0;
    return newProcess;
}
