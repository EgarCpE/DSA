#include <iostream>
#include <string.h>

class student{
private: 

      std::string studentName; //declare string studentName
      int studentAge; //declare age 

public: //blue print
    //constructor
    student(std::string newName = "john doe", int newAge = 18){

        //methods for getting the student infos
        studentName = std::move(newName);
        studentAge = std::move(newAge);
    
    std::cout << "The constructor is called." << std::endl;

    };


    //deconstructor

    ~student(){

      std::cout << "The Deconstuctor is called." << std::endl;  
    }

    //copy constructor

    student (const student &copystudent){

        std::cout << "Copy constructor called" << std::endl;
        studentName = copystudent.studentName;
        studentAge = copystudent.studentAge;
    }

};

int main() {
  student student1("Roman", 28);
  student student2(student1);
  student student3;
  student3 = student2;


 return 0;

}
