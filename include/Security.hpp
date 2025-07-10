#ifndef SECURITY_HPP
#define SECURITY_HPP

#include <string>

/**
 * @file Security.hpp
 * @brief Declaração da classe Security.
 *
 * Esta classe é responsável pela autenticação de administradores no sistema de votação.
 * Ela verifica se o arquivo de autenticação está aberto e se a senha fornecida corresponde à senha armazenada.
 */

class Security
{
private:
    std::string hash_loaded; // Armazena o hash da senha carregada do arquivo

public:
    bool arquivo_aberto = true; // Indica se o arquivo de autenticação está aberto

    Security(); // Construtor da classe Security

    bool autenticate_admin(); // Método para autenticar o administrador
};

#endif // SECURITY_HPP
