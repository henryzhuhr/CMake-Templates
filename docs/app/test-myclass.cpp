#include <iostream>
// #include "myClass/myClass.h"
int main(int argc, char** argv)
{
    printf("got %d param",argc-1);

    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;

    return 0;
}