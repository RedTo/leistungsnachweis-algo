#include <iostream>

int main() {
    int i = 42;

    std::cout << "TEST " << i << std::endl;

    return 0;
}

int getTest(){
    int i = 42;
    for(int y = 1; y<10;y++) {
        i = 2 * i;
        i++;
    }
    return i;
}

