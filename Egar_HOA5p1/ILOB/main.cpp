#include <iostream>
#include "queue_ll.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue(&front, &back, 'J');
      std::cout<< front -> data << " " << back-> data <<std::endl;  

    enqueue(&front, &back, 'A');
      std::cout<< front -> data << " " << back-> data <<std::endl; 
      
    dequeue(&front, &back);
      std::cout << front -> data << " " << back -> data <<std::endl;

    std:: cout << "Queue list \n";
    
    display(front);
       std::cout << "Front value: " << Front(front) << std::endl;

  return 0;
}