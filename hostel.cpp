#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class Hostel {
    int room_no;
    char name[50];
    float fees;

public:
    void input() {
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Room No: ";
        cin>>room_no;
        cout<<"Enter Fees: ";
        cin>>fees;
    }

    void display() {
        cout<<"\nName: "<<name;
        cout<<"\nRoom No: "<<room_no;
        cout<<"\nFees: "<<fees;
        cout<<"\n----------------------";
    }

    int getRoomNo() {
        return room_no;
    }
};

// Add Student
void addStudent() {
    Hostel h;
    ofstream file("hostel.dat", ios::app);

    h.input();
    file.write((char*)&h, sizeof(h));

    file.close();
    cout<<"\nRecord Saved!\n";
}

// Show All Students
void showAll() {
    Hostel h;
    ifstream file("hostel.dat");

    while(file.read((char*)&h, sizeof(h))) {
        h.display();
    }

    file.close();
}

// Search Student by Room No
void searchStudent() {
    Hostel h;
    int r, found = 0;

    cout<<"Enter Room No to search: ";
    cin>>r;

    ifstream file("hostel.dat");

    while(file.read((char*)&h, sizeof(h))) {
        if(h.getRoomNo() == r) {
            h.display();
            found = 1;
        }
    }

    file.close();

    if(!found)
        cout<<"\nRecord not found!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout<<"\n\n--- Hostel Management System ---";
        cout<<"\n1. Add Student";
        cout<<"\n2. Show All Students";
        cout<<"\n3. Search Student";
        cout<<"\n4. Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: showAll(); break;
            case 3: searchStudent(); break;
            case 4: cout<<"Exiting..."; break;
            default: cout<<"Invalid choice!";
        }

    } while(choice != 4);

    return 0;
}