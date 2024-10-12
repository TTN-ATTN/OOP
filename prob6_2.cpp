#include <bits/stdc++.h>
using namespace std;

/**
 * Student structure with name, math, literature, languages scores and GPA.
 */
struct Student {
    string name;
    double math = 0, literature = 0, languages = 0;
    double gpa = 0.0;
};

/**
 * Calculate the GPA of a student.
 * Input: Student object
 * Output: GPA
 */
double calculate_gpa(Student &student) {
    return (2 * student.math + student.literature + student.languages) / 4.0;
}

/**
 * Determine the rank of the student based on their GPA.
 * Input: Student object
 * Output: A string representing the student's rank
 */
string get_rank(Student &student) {
    double gpa = calculate_gpa(student);
    if (gpa >= 9.0) return "Xuat sac";
    if (gpa >= 8.0) return "Gioi";
    if (gpa >= 6.5) return "Kha";
    if (gpa >= 5.0) return "Trung binh";
    return "Yeu";
}

/**
 * Print the student's information.
 * Input: Student object
 * Output: Student's details including GPA and rank
 */
void info(Student &student) {
    cout << "Name: " << student.name << endl;
    cout << "Math: " << student.math << endl;
    cout << "Literature: " << student.literature << endl;
    cout << "Languages: " << student.languages << endl;
    cout << "GPA: " << fixed << setprecision(2) << calculate_gpa(student) << endl;
    cout << "Rank: " << get_rank(student) << endl;
}

/**
 * Add a student to the list.
 * Input: Vector of students, Student object
 * Output: None
 */
void add_student(vector<Student> &students, Student student) {
    students.push_back(student);
}

/**
 * Check if the score is invalid.
 * Input: score - double
 * Output: True if invalid, False otherwise
 */
bool invalid_score(double score) {
    return score < 0 || score > 10;
}

/**
 * Check if the name is invalid.
 * Input: name - string
 * Output: True if invalid, False otherwise
 */
bool invalid_name(string name) {
    for(char c: name) {
        if((c > 'z' || c < 'a') && (c < 'A' || c > 'Z') && c != ' ')
            return true;
    }
    return name.size() > 30;
}

/**
 * Print the student with the highest GPA.
 * Input: Vector of students
 * Output: Student with the highest GPA
 */
void highest_gpa_student(vector<Student> &students) {
    if (students.empty()) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "\nStudent with the highest GPA: " << endl;
    double max_gpa = -1.0;
    int index = -1;

    for (int i = 0; i < students.size(); i++) {
        double gpa = calculate_gpa(students[i]);
        if (gpa > max_gpa) {
            max_gpa = gpa;
            index = i;
        }
    }

    info(students[index]);
}

/**
 * Search for a student by name.
 * Input: Vector of students
 * Output: Search result
 */
void search_by_name(vector<Student> &students) {
    cout << "Enter student's name to search: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string name;
    getline(cin, name);

    while (invalid_name(name)) {
        cout << "Invalid name! Please enter again: ";
        getline(cin, name);
    }

    transform(name.begin(), name.end(), name.begin(), ::tolower);

    cout << "\nSearch result: " << endl;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        string student_name = students[i].name;
        transform(student_name.begin(), student_name.end(), student_name.begin(), ::tolower);
        if (student_name.find(name) != string::npos) {
            info(students[i]);
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

/**
 * Print the student with the lowest math score.
 * Input: Vector of students
 * Output: Student with the lowest math score
 */
void lowest_math(vector<Student> &students) {
    if (students.empty()) {
        cout << "No students in the list." << endl;
        return;
    }

    cout << "\nStudent with the lowest math score: " << endl;
    double min_math = 11;
    int index = -1;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].math < min_math) {
            min_math = students[i].math;
            index = i;
        }
    }
    info(students[index]);
}



/**
 * Read input for a student
 * Input: None
 * Output: Student object
 */
Student Input() {
    string name;
    double math, literature, languages;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter student's name: ";
    getline(cin, name);

    while (invalid_name(name)) {
        cout << "Invalid name! Please enter again: ";
        getline(cin, name);
    }

    cout << "Enter math score: ";
    cin >> math;
    while (invalid_score(math)) {
        cout << "Invalid math score! Please enter again: ";
        cin >> math;
    }

    cout << "Enter literature score: ";
    cin >> literature;
    while (invalid_score(literature)) {
        cout << "Invalid literature score! Please enter again: ";
        cin >> literature;
    }

    cout << "Enter languages score: ";
    cin >> languages;
    while (invalid_score(languages)) {
        cout << "Invalid languages score! Please enter again: ";
        cin >> languages;
    }

    return Student{name, math, literature, languages};
}

/**
 * Display menu options and handle user input.
 * Input: Vector of students
 * Output: Results of valid options or error message
 */
void options(vector<Student> &students) {
    while (true) {
        cout << "\nMenu Options:\n";
        cout << "1. Search student with highest GPA\n";
        cout << "2. Search student with lowest math score\n";
        cout << "3. Search student(s) by name\n";
        cout << "4. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                highest_gpa_student(students);
                break;
            case 3:
                search_by_name(students);
                break;
            case 2:
                lowest_math(students);
                break;
            case 4:
                return;
            default:
                cout << "Invalid option!\n";
        }
    }
}

int main() {
    vector<Student> students;
    int n;
    do {
        cout << "Enter number of students: ";
        cin >> n;
    } while (n < 1);

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        add_student(students, Input());
    }
    options(students);
    return 0;
}
