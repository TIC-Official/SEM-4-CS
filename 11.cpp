#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class tel {
public:
    int rollNo;
    char name[10];
    char div;
    char address[20];

    void accept() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Division: ";
        cin >> div;
        cout << "Enter Address: ";
        cin >> address;
    }

    void accept2() {
        cout << "Enter new Roll No: ";
        cin >> rollNo;
    }

    void accept3() {
        cout << "Enter new Name: ";
        cin >> name;
    }

    int getRollNo() { return rollNo; }

    void show() {
        cout << "\n" << rollNo << "\t" << name << "\t" << div << "\t" << address;
    }
};

int main() {
    int ch, ch1, rec, start, add, n1, y, on, add3, start3, n3, y1, add4, start4, n4;
    char name[20], name2[20];
    tel t1;
    fstream f, g;

    do {
        cout << "\n---MENU---\n1.Insert\n2.Show\n3.Edit Record (Full)\n4.Edit by Name\n5.Modify RollNo\n6.Modify Name\n7.Delete\n8.Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            f.open("StuRecord.txt", ios::out | ios::app);
            do {
                t1.accept();
                f.write((char *)&t1, sizeof(t1));
                cout << "Add more? (1.Yes/2.No): ";
                cin >> ch1;
            } while (ch1 == 1);
            f.close();
            break;

        case 2:
            f.open("StuRecord.txt", ios::in);
            while (f.read((char *)&t1, sizeof(t1))) {
                t1.show();
            }
            f.close();
            break;

        case 3:
            cout << "Enter roll number to edit: ";
            cin >> rec;
            f.open("StuRecord.txt", ios::in | ios::out);
            while (f.read((char *)&t1, sizeof(t1))) {
                if (rec == t1.rollNo) {
                    add = f.tellg();
                    f.seekg(0, ios::beg);
                    start = f.tellg();
                    n1 = (add - start) / sizeof(t1);
                    f.seekp((n1 - 1) * sizeof(t1), ios::beg);
                    t1.accept();
                    f.write((char *)&t1, sizeof(t1));
                    break;
                }
            }
            f.close();
            break;

        case 5:
            cout << "Enter roll number to modify: ";
            cin >> on;
            f.open("StuRecord.txt", ios::in | ios::out);
            while (f.read((char *)&t1, sizeof(t1))) {
                if (on == t1.rollNo) {
                    add3 = f.tellg();
                    f.seekg(0, ios::beg);
                    start3 = f.tellg();
                    n3 = (add3 - start3) / sizeof(t1);
                    f.seekp((n3 - 1) * sizeof(t1), ios::beg);
                    t1.accept2();
                    f.write((char *)&t1, sizeof(t1));
                    break;
                }
            }
            f.close();
            break;

        case 7:
            int roll;
            cout << "Enter Roll No to delete: ";
            cin >> roll;
            f.open("StuRecord.txt", ios::in);
            g.open("temp.txt", ios::out);
            while (f.read((char *)&t1, sizeof(t1))) {
                if (t1.getRollNo() != roll)
                    g.write((char *)&t1, sizeof(t1));
            }
            f.close();
            g.close();
            remove("StuRecord.txt");
            rename("temp.txt", "StuRecord.txt");
            break;
        }
    } while (ch != 8);
    return 0;
}