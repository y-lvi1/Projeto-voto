#include "Security.hpp"
#include "picosha2.h"
#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <string>

Security::Security()
{
    std::ifstream file("hash.txt");
    if (!file.is_open())
    {
        std::cout << "Error: O arquivo hash.txt não pôde ser aberto!\n" << std::endl;
        Logger::log("Erro ao abrir o arquivo hash.txt");

        arquivo_aberto = false;
        return;
    }
    file >> hash_loaded;
    file.close();

    Logger::log("Arquivo hash.txt aberto com sucesso");

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
        Logger::log("Autenticação do administrador bem-sucedida");
        return true;
    }
    else
    {
        Logger::log("Falha na autenticação do administrador");
        return false;
    }
}