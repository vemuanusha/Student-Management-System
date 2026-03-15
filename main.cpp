#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int marks;
};

vector<Student> students;

void loadFromFile(){
    ifstream file("students.txt");
    Student s;
    while(file >> s.id >> s.name >>s.marks){
        students.push_back(s);
    }
    file.close();
}

void saveToFile() {
    ofstream file("students.txt");
    for (Student s : students) {
        file << s.id << " " << s.name << " " << s.marks << endl;
    }
    file.close();
}

void addStudent(){
    Student s;
    cout<<"Enter ID:";
    cin>>s.id;
    cout<<"Enter Name:";
    cin>>s.name;
    cout<<"Enter Marks:";
    cin>>s.marks;

    students.push_back(s);
    saveToFile();
}

void displayStudents(){
    for(Student s:students){
       cout <<"ID:"<<s.id<<endl;
       cout <<"Name:"<<s.name<<endl;
       cout <<"Marks:"<<s.marks<<endl;
    }
}

void searchStudent(){
    int id;
    cout<<"Enter ID:";
    cin>>id;
    bool found = false;

    for (Student s : students) {
        if (s.id == id) {
            cout << "Found: " << s.name << " " << s.marks << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found\n";
    }
}

void deleteStudent(){
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (int i = 0; i < students.size(); i++){
        if(students[i].id == id){
          students.erase(students.begin() + i);
          saveToFile();
          cout << "Student deleted\n";
          return;  
        }
    }
    cout << "Student not found\n";
}
void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (Student &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new marks: ";
            cin >> s.marks;
            saveToFile();
            return;
        }
    }

    cout << "Student not found\n";
}

int main() {
    loadFromFile();

    int choice;

    while (true) {
        cout << "\n1 Add\n2 Display\n3 Search\n4 Update\n5 Delete\n6 Exit\n";
        cout<<"Enter choice:";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) displayStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) updateStudent();
        else if (choice == 5) deleteStudent();
        else if (choice == 6) break;
    }

    return 0;
}