#include "world.h"
#include <iostream>

int World()
{
    std::cout << "world!" << std::endl;
    
    return 0;
}

int Factorial(int n) {
    int res = 1;
    for (int i=1; i<=n; i++) {
        res *= i;
    }
    return res;
}