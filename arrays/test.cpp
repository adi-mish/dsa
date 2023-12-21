#include <iostream>

int main() {
    int myArray[] {1,2,3,4,5};

    std::cout << "Array elements:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << myArray[i] << std::endl;
    }
        
    return 0;
}