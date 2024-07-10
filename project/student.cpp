using namespace std;
#include <iostream>
#include <cstring> // for strcpy and strlen

class Student {
protected:
    int student_id;
    char* name;
    int age;
    float Theory_marks;

public:
    // Constructors
    Student() {
     student_id=0;
     name="snehal";
      age=10;
    Theory_marks=0.0f;
    }

    Student(int id, const char* n, int a, float marks)
        : student_id(id), age(a), Theory_marks(marks) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Destructor
    virtual ~Student() {

    }

    // Display function
    void display() {
     cout << "Student ID: " << student_id << ", Name: " << name << ", Age: " << age << ", Theory Marks: " << Theory_marks << std::endl;
    }

    // Pure virtual functions
    virtual void conductExam() = 0;
    virtual float calTotal() const = 0;
};

class SportStudent : public Student {
private:
    char* sportName;
    int credits;

public:
    // Constructors
    SportStudent() { sportName="Cricket";
     credits=10;
      }
    SportStudent(int id, const char* n, int a, float marks, const char* sport, int cred)
        : Student(id, n, a, marks), credits(cred) {
        sportName = new char[strlen(sport) + 1];
        strcpy(sportName, sport);
    }
    // Destructor
    ~SportStudent() {

    }

    // Display function (override)
    void display() {
        Student::display();
        cout << "Sport: " << sportName << ", Credits: " << credits << std::endl;
    }

    // Override conductExam function
    void conductExam() override {
        cout << "Theory exam and physical activities are conducted." << std::endl;
    }

    // Override calTotal function
    float calTotal() const override {
        return Theory_marks + (credits * 10);
    }
};

class ScienceStudent : public Student {
private:
    char* sp_student;
    float practicalMarks;

public:
    // Constructors
    ScienceStudent() {
         sp_student="abc";
          practicalMarks=0.0f;
          }
    ScienceStudent(int id, const char* n, int a, float marks, const char* sp, float pracMarks)
        : Student(id, n, a, marks), practicalMarks(pracMarks) {
        sp_student = new char[strlen(sp) + 1];
        strcpy(sp_student, sp);
    }

    // Destructor
    ~ScienceStudent() {
       cout<<"\n ScienceStudent desrtuctor is called";
    }

    // Display function (override)
    void display() {
        Student::display();
        cout << "Science Field: " << sp_student << ", Practical Marks: " << practicalMarks << std::endl;
    }

    // Override conductExam function
    void conductExam() override {
        cout << "Theory exam and practicals are conducted." << std::endl;
    }

    // Override calTotal function
    float calTotal() const override {
        return Theory_marks + practicalMarks;
    }
};

class ArtStudent : public Student {
private:
    char* branch;
    float activityMarks;

public:
    // Constructors
    ArtStudent() {
        branch="Electrical";
        activityMarks =0.0f;
         }
    ArtStudent(int id, const char* n, int a, float marks, const char* br, float actMarks)
        : Student(id, n, a, marks), activityMarks(actMarks) {
        branch = new char[strlen(br) + 1];
        strcpy(branch, br);
    }

    // Destructor
    ~ArtStudent() {
        cout<<"\n ArtStudent destructor is called";
    }

    // Display function (override)
    void display() {
        Student::display();
        cout << "Branch: " << branch << ", Activity Marks: " << activityMarks << std::endl;
    }

    // Override conductExam function
    void conductExam() override {
        cout << "Theory exam and activity exam are conducted" << std::endl;
    }

    // Override calTotal function
    float calTotal() const override {
        return Theory_marks + (0.6 * activityMarks);
    }
};

int main() {
    Student* students[3];

    // Create instances of each type
    students[0] = new SportStudent(1, "John", 20, 80.0, "Cricket", 5);
    students[1] = new ScienceStudent(2, "Emily", 21, 75.0, "Physics", 85.0);
    students[2] = new ArtStudent(3, "Michael", 19, 70.0, "Literature", 50.0);

    // Demonstrate polymorphism
    for (int i = 0; i < 3; ++i) {
        students[i]->display();
        students[i]->conductExam();
        cout << "Total Marks: " << students[i]->calTotal() << std::endl;
        cout << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete students[i];
    }

    return 0;
}
