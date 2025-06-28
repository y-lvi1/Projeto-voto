#include "Security.hpp"
#include <iostream>
#include "interface.hpp"
int main()
{
    while(1){
    Interface interface;
    interface.inicial();
    }
    //*EXEMPLO DE USO DA CLASSE SECURITY*//
    
    /*
    Security security;
    while (1)
    {
        if (security.autenticate_admin())
        {
            std::cout << "Acesso concedido." << std::endl;
        }
        else
        {
            std::cout << "Acesso negado." << std::endl;
        }
    }
    return 0;
    */
}
