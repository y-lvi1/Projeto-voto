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

Security::Security()
{
    ifstream file("hash.txt"); // Tenta abrir o arquivo hash.txt

    // Verifica se o arquivo foi aberto com sucesso
    if (!file.is_open())
    {
        arquivo_aberto = false; // Define a variável arquivo_aberto como false se o arquivo não puder ser aberto
    }

    file >> hash_loaded; // Lê o hash do arquivo e armazena na variável hash_loaded
    file.close(); // Fecha o arquivo após a leitura
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada para evitar problemas com entradas subsequentes

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