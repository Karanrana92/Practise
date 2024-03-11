#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
    public:
    Task(const string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    private:
    string description;
    bool completed;
};

    class ToDoList {
    public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
    }

    void viewAllTasks() const {
        if (tasks.empty()) {
        cout << "There are no tasks in the list." << endl;
        return;
        }

        cout << "All Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
        string status = tasks[i].isCompleted() ? "Completed" : "Pending";
        cout << i + 1 << ". " << tasks[i].getDescription() << " (" << status << ")" << endl;
        }
    }

    void markTaskComplete(int task_index) {
        if (tasks.empty()) {
        cout << "There are no tasks in the list." << endl;
        return;
        }

        if (task_index < 1 || task_index > tasks.size()) {
        cout << "Invalid task index. Please enter a valid index." << endl;
        return;
        }

        tasks[task_index - 1].markCompleted();
        cout << "Task '" << tasks[task_index - 1].getDescription() << "' marked as completed." << endl;
    }

    void remove_task(int task_index) {
        if (tasks.empty()) {
        cout << "There are no tasks in the list." << endl;
        return;
        }

        if (task_index < 1 || task_index > tasks.size()) {
        cout << "Invalid task index. Please enter a valid index." << endl;
        return;
        }

        tasks.erase(tasks.begin() + task_index - 1);
        cout << "Task '" << task_index << "' removed from the list." << endl;
    }

    private:
    vector<Task> tasks;
};

int main() {
    ToDoList todo_list;

    int choice;

    while (true) {
        cout << endl << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Mark Task Complete" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1: {
            string description;
            cout << "Enter task description: ";
            cin.ignore(); 
            getline(cin, description);
            todo_list.addTask(description);
            cout << "Task added successfully." << endl;
            break;
        }
        case 2:
            todo_list.viewAllTasks();
            break;
        case 3: {
            int task_index;
            cout << "Enter the task index to mark complete: ";
            cin >> task_index;
            todo_list.markTaskComplete(task_index);
            break;
        }
        case 4: {
            int task_index;
            cout << "Enter the task index to remove: ";
            cin >> task_index;
            todo_list.remove_task(task_index);
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
