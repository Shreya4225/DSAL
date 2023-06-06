#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void addStudent() {
    ofstream file("student.txt", ios::app);

    string rollNo, name, division, address;
    cout << "Enter Roll No: ";
    cin >> rollNo;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address: ";
    cin >> address;

    file << left << setw(20) << rollNo << setw(20) << name << setw(20) << division << setw(20) << address << endl;
    file.close();

    cout << "Student Successfully Added" << endl;
}

void deleteStudent() {
    ifstream inFile("student.txt");
    ofstream outFile("temp.txt", ios::out);

    string rollNo;
    cout << "Enter the Roll No to delete: ";
    cin >> rollNo;

    string line;
    bool deleted = false;
    while (getline(inFile, line)) {
        if (line.find(rollNo) == string::npos) {
            outFile << line << endl;
        } else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (deleted) {
        cout << "Student Deleted Successfully" << endl;
    } else {
        cout << "Student Doesn't Exist!" << endl;
    }
}

void searchStudent() {
    ifstream file("student.txt");
    string rollNo;
    cout << "Enter the Roll No to search: ";
    cin >> rollNo;

    string line;
    bool found = false;
    while (getline(file, line)) {
        if (line.find(rollNo) != string::npos) {
            cout << "Student Details: " << endl;
            cout << line << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student Doesn't Exist!" << endl;
    }
}

void printData() {
    ifstream file("student.txt");
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    ofstream file("student.txt", ios::out);
    file << left << setw(20) << "Roll No" << setw(20) << "Name" << setw(20) << "Division" << setw(20) << "Address" << endl;
    file.close();

    int choice = 0;
    while (choice != 5) {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Print Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printData();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
