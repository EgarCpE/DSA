#include <iostream>
#include <string>
#include "searchingAlgo.h"

class Student {
private:
    std::string studentName;
    int studentAge;

public:
    // Constructor
    Student(std::string newName = "John Doe", int newAge = 18) {
        studentName = newName;
        studentAge = newAge;
        std::cout << "Constructor was called" << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor was called" << std::endl;
    }

    // Copy Constructor
    Student(const Student &copyStudent) {
        std::cout << "Copy Constructor Called" << std::endl;
        studentName = copyStudent.studentName;
        studentAge = copyStudent.studentAge;
    }

    // Display attributes
    void printDetails() {
        std::cout << this->studentName << " "
                  << this->studentAge << std::endl;
    }
};

int main() {

    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] = {
        "Dane", "Angela", "Andrew", "Ralph", "Jarel"
    };
    int ageList[j] = {
        15, 16, 18, 19, 16
    };

    // Create Student objects
    for (int i = 0; i < j; i++) {
        Student *ptr = new Student(namesList[i], ageList[i]);
        studentList[i] = *ptr;

        delete ptr;
    }

    // Display students
    std::cout << "\nStudent List:\n";

    for (int i = 0; i < j; i++) {
        studentList[i].printDetails();
    }


    // LINEAR SEARCH - ARRAY

    int data[] = {10, 20, 30, 40, 50};
    int arrSize = 5;

    std::cout << "\nLinear Search Array:\n";

    linearSearchArr(data, arrSize, 30);
    linearSearchArr(data, arrSize, 100);


    // LINEAR SEARCH - LINKED LIST


    Node<int>* head = new Node<int>(10);
    head->next = new Node<int>(20);
    head->next->next = new Node<int>(30);
    head->next->next->next = new Node<int>(40);
    head->next->next->next->next = new Node<int>(50);

    std::cout << "\nLinear Search Linked List:\n";

    linearSearchLL(head, 30);
    linearSearchLL(head, 100);


    // BINARY SEARCH - LINKED LIST


    std::cout << "\nBinary Search Linked List:\n";

    binarySearchLL(head, 40);
    binarySearchLL(head, 100);


    // DELETE LINKED LIST

    Node<int>* current = head;

    while (current != nullptr) {
        Node<int>* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}