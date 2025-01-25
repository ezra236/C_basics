#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class admin {
private:
    string adminpassword = "aas5";

public:
    admin() {}
    
    void verify(const string& password) {
        if (password == adminpassword) {
            cout << "ACCESS IS GRANTED" << endl;
        } else if (password.empty()) {
            cout << "Enter a VALID Password" << endl;
        } else {
            cout << "Password is Incorrect" << endl;
        }
    }
};

class Taskk : public admin {
private:
    string task;
    vector<string> tasks;

public:
    Taskk() : admin() {}

    void add(int n, string password) {
        verify(password);
        for (int i = 0; i < n; i++) {
            cout << "Enter the task: " << endl;
            cin >> task;
            tasks.push_back(task);
        }
        for (int i = 0; i < tasks.size(); i++) {
            cout << tasks[i] << endl;
        }
    }
};

class Avail : public admin {
private:
    vector<string> arr;

public:
    Avail() : admin() {
        arr.resize(3);
    }

    void doo(const string& ds, const string& password) {
        verify(password);
        if (ds == "read") {
            arr[0] = "read";
            cout << "START" << endl;
        } else if (ds == "sleep") {
            arr[1] = "Sleep";
            cout << "Sleep" << endl;
        } else if (ds == "eat") {
            arr[2] = "eat";
            cout << "eat" << endl;
        } else {
            cout << "Enter a valid task" << endl;
        }
    }
};

int main() {
    admin s;
    Taskk d;
    Avail m;

    int n;
    string ds;
    string password;

    cout << "ENTER THE PASSWORD:" << endl;
    cin >> password;
    s.verify(password);

    cout << "HOW many tasks do you want to add:" << endl;
    cin >> n;

    d.add(n, password);

    cout << "What task do you want to do:\n1. read\n2. sleep\n3. eat" << endl;
    cin >> ds;
    m.doo(ds, password);

    return 0;
}
