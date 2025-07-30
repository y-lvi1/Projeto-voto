#include "Security.hpp"
#include "Interface.hpp"
#include "picosha2.h"
#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

/**
 * @brief Construtor da classe Security.
 * 
 * Este construtor tenta abrir o arquivo "hash.txt" para carregar o hash da senha do administrador.
 * Se o arquivo não puder ser aberto, exibe uma mensagem de erro e define a variável `arquivo_aberto` como `false`.
 * Se o arquivo for aberto com sucesso, lê o hash e o armazena na variável `hash_loaded`.
 */

Security::Security() : arquivo_aberto(false) // Inicializa como falso por segurança
{
    std::ifstream arquivo;

    arquivo.exceptions(std::ifstream::failbit | std::ifstream::badbit); // Configura para lançar exceções em caso de falha ou erro

    try {
        arquivo.open("hash.txt");
        arquivo >> hash_loaded;
        
        this->arquivo_aberto = true;  // Define arquivo_aberto como true se o arquivo foi aberto com sucesso
        Logger::log("Hash de segurança do admin carregado com sucesso.");

    } catch (const std::ifstream::failure& e) {
        std::cerr << "ERRO CRITICO: Não foi possível ler o arquivo 'hash.txt'." << std::endl;
        std::cerr << "Erro: " << e.what() << std::endl;
        Logger::log("Falha ao ler o arquivo hash.txt: " + std::string(e.what()));
    }
}

/**
 * @brief Autentica o administrador do sistema.
 * 
 * Esta função solicita a senha do administrador, calcula o hash SHA-256 da senha fornecida e compara com o hash armazenado.
 * Se os hashes coincidirem, a autenticação é bem-sucedida; caso contrário, falha.
 * 
 * @return true se a autenticação for bem-sucedida, false caso contrário.
 */

bool Security::autenticate_admin()
{
    string user_input; // Variável para armazenar a entrada do usuário
    string hash_input; // Variável para armazenar o hash da entrada do usuário

    cin >> user_input;

    if (std::cin.fail())
        {
            Logger::log("Entrada inválida no menu de votação.");
            std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            limpar_dados();
            return false; // Retorna false se a entrada for inválida
        }

    hash_input = picosha2::hash256_hex_string(user_input); // Calcula o hash SHA-256 da entrada do usuário

    // Verifica se a autenticação foi bem-sucedida comparando o hash da entrada do usuário com o hash armazenado
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