using namespace std;
#include <iostream>
#include <cstring>

class Person {
protected:
    int person_id;
    char* name;
    int age;

public:
 Person(){
     person_id=0;
      name = new char[20];
     strcpy(name,"abc");
      age=0;
       }
  Person(int id, const char* n, int a) : person_id(id), age(a) {
    name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

   virtual ~Person() {
       cout<<"\n Person destructor";
    }

    void display() {
        std::cout << "Person ID: " << person_id << ", Name: " << name << ", Age: " << age << std::endl;
    }

    virtual void talk() = 0;

    virtual void display_identity() = 0;
};

class Doctor : public Person {
private:
    char* specialization;
    float OPD_charges;

public:
    // Constructors
    Doctor() {
    specialization = new char[20];
     strcpy(specialization,"cardiologist");
     OPD_charges=0.0f;
      }
    Doctor(int id, const char* n, int a, const char* spec, float charges)
        : Person(id, n, a), OPD_charges(charges) {
        specialization = new char[strlen(spec) + 1];
        strcpy(specialization, spec);
    }

    ~Doctor() {
       cout<<"\n doctor destructor";
    }

    void display() {
        Person::display();
        cout << "Specialization: " << specialization << ", OPD Charges: " << OPD_charges << std::endl;
    }

    void talk() override {
        cout << "My specialization is " << specialization << " and charges are " << OPD_charges;
}

    void display_identity() override {
        cout << "I am a doctor.";
    }
};

class Teacher : public Person {
private:
    char* subject;
    float rate_per_hr;

public:
    Teacher() {
    subject="Science";
    rate_per_hr=0.0f;
      }
    Teacher(int id, const char* n, int a, const char* sub, float rate)
        : Person(id, n, a), rate_per_hr(rate) {
        subject = new char[strlen(sub) + 1];
        strcpy(subject, sub);
    }
    ~Teacher() {
        cout<<"\n Teacher destructor is called";
    }

    void display() {
        Person::display();
        cout << "Subject: " << subject << ", Rate per Hour: " << rate_per_hr ;
    }

    void talk() override {
    cout << "I am a teacher, teach " << subject << " and I charge " << rate_per_hr << " per hour.";
    }

    void display_identity() override {
        cout << "I am a teacher." << std::endl;
    }
};

class Student : public Person {
private:
    char* courseName;

public:
    Student() { courseName="java";
    }
    Student(int id, const char* n, int a, const char* course)
        : Person(id, n, a) {
        courseName = new char[strlen(course) + 1];
        strcpy(courseName, course);
    }

    ~Student() {
       cout<<"\n student destructor is called";

    }
    void display() {
        Person::display();
        cout << "Course: " << courseName << std::endl;
    }

    void talk() override {
        cout << "I am a student. I enjoy learning new concepts." << std::endl;
    }

    void display_identity() override {
        std::cout << "I am a student." << std::endl;
    }
};

int main() {
    Person* people[4];

    people[0] = new Doctor(1, "Dr. Smith", 40, "Cardiology", 500.0);
    people[1] = new Teacher(2, "Ms. Johnson", 35, "Mathematics", 50.0);
    people[2] = new Student(3, "John Doe", 20, "Computer Science");
    people[3] = new Student(4, "Jane Doe", 21, "Physics");

    for (int i = 0; i < 4; ++i) {
        people[i]->display();
        people[i]->talk();
        people[i]->display_identity();
        cout << std::endl;
    }
    for (int i = 0; i < 4; ++i) {
        delete people[i];
    }


    return 0;
}
