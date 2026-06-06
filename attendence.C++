#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Student {
public:
    int id;
    string name;
    int presentDays;
    int totalClasses;

    Student(int sid, string sname) {
        id = sid;
        name = sname;
        presentDays = 0;
        totalClasses = 0;
    }

    void markAttendance(bool present) {
        totalClasses++;
        if (present)
            presentDays++;
    }

    double getPercentage() {
        if (totalClasses == 0)
            return 0;
        return (double)presentDays / totalClasses * 100;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== STUDENT ATTENDANCE MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Mark Attendance\n";
        cout << "3. View Attendance Report\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;

            cout << "Enter Student ID: ";
            cin >> id;

            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, name);

            students.push_back(Student(id, name));
            cout << "Student Added Successfully!\n";
            break;
        }

        case 2: {
            if (students.empty()) {
                cout << "No students available.\n";
                break;
            }

            cout << "\nMark Attendance (P = Present, A = Absent)\n";

            for (auto &s : students) {
                char status;
                cout << s.name << " (" << s.id << "): ";
                cin >> status;

                if (status == 'P' || status == 'p')
                    s.markAttendance(true);
                else
                    s.markAttendance(false);
            }

            cout << "Attendance Marked Successfully!\n";
            break;
        }

        case 3: {
            if (students.empty()) {
                cout << "No student records found.\n";
                break;
            }

            cout << "\n================ ATTENDANCE REPORT ================\n";
            cout << left << setw(10) << "ID"
                 << setw(20) << "Name"
                 << setw(12) << "Present"
                 << setw(12) << "Classes"
                 << setw(12) << "Percent\n";

            for (auto &s : students) {
                cout << left << setw(10) << s.id
                     << setw(20) << s.name
                     << setw(12) << s.presentDays
                     << setw(12) << s.totalClasses
                     << fixed << setprecision(2)
                     << s.getPercentage() << "%\n";
            }
            break;
        }

        case 4:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
