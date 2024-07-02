// TASK 4
// TO - DO LIST
// Build a simple console - based to - do list manager that allows users to add,view, and delete tasks

#include <iostream>
#include <vector>

using namespace std;

class List
{
private:
    string task;
    string des;
    string dueDate;
    bool status;

public:
    List(const string &task, const string &des, const string &dueDate)
        : task(task), des(des), dueDate(dueDate), status(false) {}

    string getTask() const
    {
        return task;
    }

    string getDes() const
    {
        return des;
    }

    string getDue() const
    {
        return dueDate;
    }

    bool getStatus() const
    {
        return status;
    }

    void setTask(const string task)
    {
        this->task = task;
    }

    void setDes(const string des)
    {
        this->des = des;
    }

    void setStatus()
    {
        this->status = true;
    }

    void setDue(const string dueDate)
    {
        this->dueDate = dueDate;
    }

    void display() const
    {
        cout << task << " {" << (status ? "Completed" : "Pending") << "} - Due: " << dueDate << endl
             << "   Description: " << des << endl;
    }
};

class ToDoList
{
private:
    vector<List> list;

public:
    // Display the menu
    void displayMenu() const
    {
        cout << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Edit Task\n";
        cout << "6. Exit\n";
        cout << "-----------------------------------------\n";
    }

    // Add a new task
    void addTask()
    {
        string task, des, dueDate;
        cin.ignore(); // Clear the newline character from the buffer
        cout << "Enter task name: ";
        getline(cin, task);
        cout << "Enter task description: ";
        getline(cin, des);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        list.emplace_back(task, des, dueDate);
        cout << "Task added successfully!" << endl;
    }

    // Delete a task
    void deleteTask()
    {
        if (list.empty())
        {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout << i + 1 << ". " << list[i].getTask() << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= list.size())
        {
            list.erase(list.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else
        {
            cout << "Invalid task number!" << endl;
        }
    }

    // Display ToDoList
    void displayList() const
    {
        if (list.empty())
        {
            cout << "No tasks to display!" << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout << i + 1 << ". ";
            list[i].display();
        }
    }

    // Mark a task as completed
    void editStatus()
    {
        if (list.empty())
        {
            cout << "No tasks to mark as completed!" << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout << i + 1 << ". " << list[i].getTask() << endl;
        }
        cout << "Enter the task number to mark as completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= list.size())
        {
            list[taskNumber - 1].setStatus();
            cout << "Task marked as completed!" << endl;
        }
        else
        {
            cout << "Invalid task number!" << endl;
        }
    }

    // Edit a task
    void editTask()
    {
        if (list.empty())
        {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < list.size(); ++i)
        {
            cout << i + 1 << ". " << list[i].getTask() << endl;
        }

        int taskNumber;
        cout << "Enter the task number to edit: ";
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= list.size())
        {
            List &task = list[taskNumber - 1];
            string name, description, dueDate;
            cin.ignore(); // Clear the newline character from the buffer
            cout << "Enter new task name (current: " << task.getTask() << "): ";
            getline(cin, name);
            cout << "Enter new task description (current: " << task.getDes() << "): ";
            getline(cin, description);
            cout << "Enter new task due date (current: " << task.getDue() << "): ";
            getline(cin, dueDate);

            task.setTask(name);
            task.setDes(description);
            task.setDue(dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else
        {
            cout << "Invalid task number!" << endl;
        }
    }

    // Run the to-do list application
    void run()
    {
        int choice;
        do
        {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayList();
                break;
            case 4:
                editStatus();
                break;
            case 5:
                editTask();
                break;
            case 6:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
            }
        } while (choice != 6);
    }
};

int main()
{
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
