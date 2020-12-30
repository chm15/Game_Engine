#include <iostream>
#include "Public/component.h"
#include "Public/velocity.h"


int main() {
    Position c1;
    Position c2;
    Velocity v1;
    std::cout << c1.classID << std::endl;
    std::cout << c2.classID << std::endl;
    std::cout << v1.classID << std::endl;
    std::cout << c2.classID << std::endl;

    return 0;
}
