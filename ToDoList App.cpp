#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(string description) {
        Task newTask(description);
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display." << endl;
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
        }
    }

    void completeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks[index - 1].completed = true;
        cout << "Task " << index << " marked as completed." << endl;
    }

    void deleteTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task " << index << " deleted." << endl;
    }
};

int main() {
    ToDoList myToDoList;
    int choice;
    string description;
    int taskNumber;

    while (true) {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. Display Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // to clear the buffer
                getline(cin, description);
                myToDoList.addTask(description);
                break;
            case 2:
                myToDoList.displayTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                myToDoList.completeTask(taskNumber);
                break;
            case 4:
                cout << "Enter task number to delete: ";
                cin >> taskNumber;
                myToDoList.deleteTask(taskNumber);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
