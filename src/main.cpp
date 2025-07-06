#include "Security.hpp"
#include <iostream>
#include "interface.hpp"
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    srand(time(nullptr));
    
    while (1)
    {
        Interface i;
        i.inicial();
    }

    return 0; //Apenas para evitar warning de retorno
}
