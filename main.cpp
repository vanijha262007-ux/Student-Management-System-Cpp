#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

class student {
private:
 string Name, RollNo;
float CGPA;
 public:
 student() : Name(""), RollNO(""), CGPA(0.0) {}
 void setName(string name) {
  Name = name;
 }
 void setRollNo(string rollno) {
  RollNo = rollno;
 }
 void setCGPA(float cgpa) {
        CGPA = cgpa;
 }
    string getName() {
        return Name;
    }

    string getRollNo() {
        return RollNo;
    }

    float getCGPA() {
        return CGPA;
    }
};

void saveToFile(student s) {
    ofstream outFile("student_db.txt", ios::app);
    if (outFile.is_open()) {
        outFile << s.getRollNo() << "|" << s.getName() << "|" << s.getCGPA() << "\n";
        outFile.close();
        cout << "\n>>> Record saved to database successfully!\n";
    } else {
        cout << "\n>>> Error writing to database file!\n";
    }
}

void viewAllRecords() {
    ifstream inFile("student_db.txt");
    if (!inFile) {
        cout << "\n>>> No records found in database yet!\n";
        return;
    }
    
    string line;
    cout << "\n--- CURRENT RECORDS IN DATABASE ---\n";
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        string rNum = line.substr(0, pos1);
        string sName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string sGpa = line.substr(pos2 + 1);

        cout << "Roll No: " << rNum << " | Name: " << sName << " | CGPA: " << sGpa << "\n";
    }
    inFile.close();
}

int main() {
    student s;
  
    bool exist = false;
    while (!exist) {
        system("cls"); 

        cout << "Welcome To Student Management system" << endl;
        cout << "**********************************" << endl;
        cout << "1. Add student." << endl;
        cout << "2. Search student." << endl;
        cout << "3. Update student." << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";

        int val;
        cin >> val;

        if (val == 1) {
            string tempName, tempRoll;
            float tempGpa;

            cout << "\nEnter Full Name: ";
            cin.ignore();
            getline(cin, tempName);
            cout << "Enter Roll Number: ";
            cin >> tempRoll;
            cout << "Enter CGPA: ";
            cin >> tempGpa;

            s.setName(tempName);
            s.setRollNo(tempRoll);
            s.setCGPA(tempGpa);

            saveToFile(s);
            system("pause");
        }
        else if (val == 2) {
            viewAllRecords();
            system("pause");
        }
        else if (val == 3) {
            cout << "\nFeature under construction. Currently displaying database summary:\n";
            viewAllRecords();
            system("pause");
        }
        else if (val == 4) {
            cout << "\nExiting System Engine... Happy Coding!" << endl;
            exist = true; // Breaks execution path smoothly
        }
        else {
            cout << "\nInvalid Selection code! Select options 1-4." << endl;
            system("pause");
        }
    }
    return 0;
}
