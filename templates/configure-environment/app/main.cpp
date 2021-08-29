#include <iostream>
std::string SayHello()
{
#ifdef IS_LINUX
    return std::string("Hello from platform Linux");
#elif IS_WINDOWS
    return std::string("Hello from platform Windows");
#elif IS_MACOS
    return std::string("Hello from platform MacOS");
#else
    return std::string("Hello from an unknown platform");
#endif
}

int main()
{
    std::cout << "Hello world" << std::endl;
    printf("This program is %d-bit\n", sizeof(void*) * 8);
    std::cout << std::endl;
    std::cout << SayHello() << std::endl;

    return 0;
}