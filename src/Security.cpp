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
        std::cout << "Error: O arquivo hash.txt não pôde ser aberto!\n" << std::endl;
        arquivo_aberto = false;
        return;
    }
    file >> hash_loaded;
    return;
}

bool Security::autenticate_admin()
{
    std::string user_input;
    std::string hash_input;

    std::cin >> user_input;
    hash_input = picosha2::hash256_hex_string(user_input);

    if (hash_input == hash_loaded)
    {
        return true;
    }
    else
    {
        return false;
    }
}