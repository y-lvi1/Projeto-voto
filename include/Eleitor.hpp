#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include "Cadastro.hpp"

extern std::string sessao_atual; // Variável global para armazenar sessão atual

/**
 * @file Eleitor.hpp
 * @brief Declaração da classe Eleitor.
 *
 * Esta classe representa um eleitor em uma eleição, contendo informações sobre se o eleitor já votou para presidente e governador.
 * É derivada da classe Cadastro, que contém informações básicas como nome, CPF, idade e número de eleitor.
 */

class Eleitor : public Cadastro
{
private:
    bool votouPresidente; // Indica se o eleitor já votou para presidente
    bool votouGovernador; // Indica se o eleitor já votou para governador

public:
    Eleitor();                                                                                                                  // Construtor padrão
    Eleitor(bool votouPresidente, bool votouGovernador, std::string nome, std::string cpf, int idade, std::string num_eleitor); // Construtor com parâmetros

    bool getVotouPresidente() const;     // Método para verificar se o eleitor já votou para presidente
    void setVotouPresidente(bool votou); // Método para definir se o eleitor já votou para presidente
    bool getVotouGovernador() const;     // Método para verificar se o eleitor já votou para governador
    void setVotouGovernador(bool votou); // Método para definir se o eleitor já votou para governador
};

#endif // ELEITOR_HPP