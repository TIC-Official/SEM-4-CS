#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class Employee {
private:
    int code;
    char name[20];
    float salary;
public:
    void read() {
        cout << "Enter code: "; cin >> code;
        cout << "Enter name: "; cin.ignore(); cin.getline(name, 20);
        cout << "Enter salary: "; cin >> salary;
    }
    void display() { cout << code << " " << name << "\t" << salary << endl; }
    int getEmpCode() { return code; }
    float getSalary() { return salary; }
    void updateSalary(float s) { salary = s; }
};

fstream file;

void appendToFile() {
    Employee x;
    x.read();
    file.open("EMPLOYEE.DAT", ios::binary | ios::app);
    file.write(reinterpret_cast<char *>(&x), sizeof(x));
    file.close();
}

void displayAll() {
    Employee x;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in);
    while (file.read(reinterpret_cast<char *>(&x), sizeof(x))) {
        if (x.getSalary() >= 10000 && x.getSalary() <= 20000) {
            x.display();
        }
    }
    file.close();
}

void increaseSalary() {
    Employee x;
    int c;
    float sal;
    cout << "Enter employee code: "; cin >> c;
    file.open("EMPLOYEE.DAT", ios::binary | ios::in | ios::out);
    while (file.read(reinterpret_cast<char *>(&x), sizeof(x))) {
        if (x.getEmpCode() == c) {
            cout << "Salary hike amount: "; cin >> sal;
            x.updateSalary(x.getSalary() + sal);
            int pos = -1 * sizeof(x);
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&x), sizeof(x));
            break;
        }
    }
    file.close();
}

int main() {
    char ch;
    do {
        int n;
        cout << "\n1.Add 2.Display (10k-20k) 3.Search 4.Hike 5.Insert\nChoice: ";
        cin >> n;
        switch (n) {
            case 1: appendToFile(); break;
            case 2: displayAll(); break;
            case 4: increaseSalary(); break;
        }
        cout << "Continue? (Y/N): "; cin >> ch;
    } while (ch == 'Y' || ch == 'y');
    return 0;
}