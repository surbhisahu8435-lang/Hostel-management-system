#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roomNo;
    string mobileNo;
    int rollNo;
};

int main() {

    Student s[] = {
        {"Surbhi", 101, "9876543210", 1},
        {"Aman", 102, "9123456780", 2},
        {"Riya", 103, "9988776655", 3},
        {"Rahul", 104, "9090909090", 4}
    };

    int n = sizeof(s) / sizeof(s[0]);

    string searchName;
    cout << "Enter student name to search: ";
    cin >> searchName;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (s[i].name == searchName) {
            cout << "\nStudent Found!\n";
            cout << "Name: " << s[i].name << endl;
            cout << "Room No: " << s[i].roomNo << endl;
            cout << "Mobile No: " << s[i].mobileNo << endl;
            cout << "Roll No: " << s[i].rollNo << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found!";
    }

    return 0;
}