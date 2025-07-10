#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#include <string>

/**
 * @file Cadastro.hpp
 * @brief Declaração da classe Cadastro.
 *
 * Esta classe representa um cadastro genérico, contendo informações básicas como nome, CPF, idade e número de eleitor.
 * É a classe base para outras classes que representam entidades específicas, como Eleitor e Candidato
 */

class Cadastro
{
protected:
    std::string nome;        // Variável para armazenar o nome do cadastro
    std::string cpf;         // Variável para armazenar o CPF do cadastro
    int idade;               // Variável para armazenar a idade do cadastro
    std::string num_eleitor; // Variável para armazenar o número do título de eleitor

public:
    Cadastro();                                                                      // Construtor padrão
    Cadastro(std::string nome, std::string cpf, int idade, std::string num_eleitor); // Construtor com parâmetros
    virtual ~Cadastro();                                                             // Destrutor virtual

    std::string getNome() const;       // Método para obter o nome do cadastro
    std::string getCpf() const;        // Método para obter o CPF do cadastro
    std::string getNumEleitor() const; // Método para obter o número do título de eleitor do cadastro
    int getIdade() const;              // Método para obter a idade do cadastro
};

#endif // CADASTRO_HPP