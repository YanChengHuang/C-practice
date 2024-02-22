#include <iostream>
using namespace std;

class Employee {
    
    string Name;
    string Company;
    int Age;
public:    
    void Intro(){
        cout<< "Name - " << Name << std::endl;
        cout<< "Company - " << Company << std::endl;
        cout<< "Age - " << Age << std::endl;
    }
    // setter and getter
    void SetName(string name){
        Name = name;
    }
    string GetName(){
        return Name;
    }
    // constructor
    Employee(string name="Default", string company="TSMC", int age=12){
        Name = name;
        Company = company;
        Age = age;
    }

};

int main() {
    int number;
    Employee em1("test", "dd", 10);
    em1.Intro();
    
    return 0;
}