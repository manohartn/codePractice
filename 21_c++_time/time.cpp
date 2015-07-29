#include <ctime>
#include <iostream>
#include <unistd.h>

int
main(int, const char**)
{
    time_t now = time(0);
        sleep(3);
    time_t after = time(0);

    std::cout << after - now << std::endl; 

     return 0;
}
