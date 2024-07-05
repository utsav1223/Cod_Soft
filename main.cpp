#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Declaring variables globally
int choice{0}, i;
int no_of_tasks{0};
int no_to_be_deleted{0};
int mark_tasks{0};
vector <string> tasks;

// Declaring prototypes
void Display_Menu();
void input_tasks();
void display_tasks();
void delete_tasks();
void marks_tasks();

int main() {
    while (true) {
        Display_Menu();
        if (choice == 1) {
            input_tasks();
        } else if (choice == 2) {
            if (tasks.empty()) {
                cout<<"----------------------------------"<<endl;
                cout << "You haven't added any task!" << endl;
            } else {
                display_tasks();
            }
        } else if (choice == 3) {
            if (tasks.empty()) {
                cout<<"----------------------------------"<<endl;
                cout << "Nothing to display ! " << endl;
            } else {
                display_tasks();
                cout << "Enter task number to be deleted/marked completed (1-"<<tasks.size()<<") : ";
                cin >> no_to_be_deleted;
                delete_tasks();
            }
        } else if (choice == 4) {
            if(tasks.empty()){
                cout<<"----------------------------------"<<endl;
                cout<<"Nothing to display ! "<<endl;
            }else{
                cout << "Marking all tasks as completed............." << endl;
                marks_tasks();
                
            }
        } else {
            cout<<"----------------------------------"<<endl;
            cout << "Program terminated!" << endl;
            break;
        }
    }
    return 0;
}
void Display_Menu() {
    cout << "Welcome to-do-list!" << endl;
    cout << "----------------------" << endl;
    cout << "  1] Want to add task!                                      Press [1]" << endl;
    cout << "  2] Want to view task!                                     Press [2]" << endl;
    cout << "  3] Want to delete the (task/mark completed)!              Press [3]" << endl;
    cout << "  4] Want to mark all tasks as [COMPLETED]                  Press [4]" << endl;
    cout << "  5] Terminate program !                                    Press [Any Key!]" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
}

void input_tasks() {
    cout << "You selected option - 1" << endl;
    cout<<"----------------------------------"<<endl;
    cout << "Enter the [NUMBER OF TASKS!] to be added: ";
    cin >> no_of_tasks;
    cout<<"----------------------------------"<<endl;
    cout << "So the [" << no_of_tasks << "] tasks to be added" << endl;
    cin.ignore();
    cout<<"----------------------------------"<<endl;
    for (i = 0; i < no_of_tasks; i++) {
        string tasks_array;
        cout << "Enter task " << i + 1 << ": ";
        getline(cin, tasks_array);
        tasks.push_back(tasks_array);
    }
    cout << "Congratulations! Your tasks have been successfully added!" << endl;
    cout<<"----------------------------------"<<endl;
}

void display_tasks() {
    cout<<"----------------------------------"<<endl;
    cout << "Your tasks!" << endl;
    for (i = 0; i < tasks.size(); i++) {
        cout << "Task number " << i + 1 << ": " << tasks[i] << endl;
    }
    cout<<"----------------------------------"<<endl;
}
void delete_tasks() {
    if(no_to_be_deleted <= tasks.size()){
        tasks.erase(tasks.begin() + no_to_be_deleted-1);
        cout<<"----------------------------------"<<endl;
        cout<<"Your task successfully deleted/marked completed !"<<endl;
        no_of_tasks--;
    }else if(no_to_be_deleted <= 0 || no_to_be_deleted > tasks.size()){
        cout<<"Task not found ! try again !"<<endl;
    }
}
void marks_tasks(){
    tasks.clear();
    cout<<"----------------------------------"<<endl;
    cout << "Congratulations ! your all tasks have been completed "<<endl;
}