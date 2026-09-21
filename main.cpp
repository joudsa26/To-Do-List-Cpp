#include <iostream>
#include <string>
using namespace std;

struct Task { string title; bool isCompleted; Task* next; };
Task* top = nullptr;

void addTask() { 
    string title; 
    cout << "Enter task title: "; 
    getline(cin, title);

    char completed;
    cout << "Is the task completed? (y/n): ";
    cin >> completed;
    cin.ignore();

    Task* newTask = new Task;
    newTask->title = title;
    newTask->isCompleted = (completed == 'y' || completed == 'Y');
    newTask->next = top;
    top = newTask;

    cout << "Task added!" << endl;
}

void viewTasks() { 
    if (!top) { 
        cout << "No tasks!" << endl; 
        return; 
    }

    Task* current = top;
    while (current) {
        cout << current->title;
        cout << (current->isCompleted ? " (Completed)" : " (Not Completed)") << endl;
        current = current->next;
    }
}

void deleteTask() { 
    string title; 
    cout << "Enter task title to delete: "; 
    getline(cin, title);

    Task* current = top;
    Task* prev = nullptr;

    while (current) {
        if (current->title == title) {
            if (prev) {
                prev->next = current->next;
            } else {
                top = current->next;
            }

            delete current;
            cout << "Task deleted!" << endl;
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Task not found!" << endl;
}

int main() { 
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                deleteTask();
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
