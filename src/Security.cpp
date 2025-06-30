#include "Security.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "picosha2.h"

Security::Security()
{
    std::ifstream file("hash.txt");
    if (!file.is_open())
    {
        std::cout << "Error: O arquivo hash.txt não pôde ser aberto!" << std::endl;
        return;
    }
    file >> hash_loaded;
    return;
}

bool Security::autenticate_admin()
{
    std::string user_input;
    std::string hash_input;

    std::cout << "Digite a senha de administrador: ";
    std::cin >> user_input;
    hash_input = picosha2::hash256_hex_string(user_input);

    if (hash_input == hash_loaded)
    {
        std::cout << "Autenticação bem-sucedida!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Senha incorreta!" << std::endl;
        return false;
    }
}