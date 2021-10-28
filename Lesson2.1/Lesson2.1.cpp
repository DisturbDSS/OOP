
#include <iostream>
#include <string>

class Person {
protected:
    std::string Name;
    int Age;
    bool Gender;
    int Weight;
public:
    Person() : Name("name"), Age(0), Gender(true), Weight(0) {}
    Person(std::string name, int age, bool gender, int weight) : Name(name), Age(age), Gender(gender), Weight(weight) {}
};

class Student : public Person {
private:
    int studyYear;
    static int Count;
public:

    Student(std::string name, int age, bool gender, int weight, int year) : studyYear(year), Person(name, age, gender, weight) {}
    void printInfo() const {
        std::cout << "Name: " << Name << std::endl
            << "Age: " << Age << std::endl
            << "Gender: " << (Gender == true ? "Male" : "Female") << std::endl
            << "Weight: " << Weight << std::endl
            << "Study year: " << studyYear << std::endl
            << std::endl;

    }
    Student(const Student& S) : Person(S) {
        Count++;
        studyYear = S.studyYear;
    }
    static void printAmount()
    {
        std::cout << "Amount of students: " << Count << std::endl;
    }
};


int main()
{
    Student Igor("Igar", 21, true, 73, 2019);
    Student Leonid("Leonid", 48, true, 69, 2001);
    Igor.printInfo();
    Leonid.printInfo();
    Student::printAmount();
    return 0;
};