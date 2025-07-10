#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP
#include "Cadastro.hpp"
#include <iostream>

/**
 * @file Candidato.hpp
 * @brief Declaração da classe Candidato.
 *
 * Esta classe representa um candidato em uma eleição, contendo informações como número do candidato, nome de urna, partido, cargo disputado e votos recebidos.
 * É derivada da classe Cadastro, que contém informações básicas como nome, CPF, idade e número de eleitor.
 */

class Candidato : public Cadastro
{
private:
    int numero_candidato;        // Número do candidato
    std::string nome_urna;       // Nome do candidato na urna
    std::string partido;         // Partido do candidato
    std::string cargo_disputado; // Cargo disputado pelo candidato
    int votos = 0;               // Votos recebidos pelo candidato

public:
    Candidato(); // Construtor padrão
    Candidato(std::string nome, std::string cpf, int idade, std::string num_eleitor,
              int numero, std::string nome_urna, std::string partido, std::string cargo); // Construtor com parâmetros

    std::string getNomeUrna() const; // Método para obter o nome do candidato na urna
    std::string getPartido() const;  // Método para obter o partido do candidato
    std::string getCargo() const;    // Método para obter o cargo disputado pelo candidato
    int getVotos() const;            // Método para obter o número de votos recebidos pelo candidato
    int getNumero() const;           // Método para obter o número do candidato

    void setNome(const std::string nome);       // Método para definir o nome do candidato
    void setNumero(int numero);                 // Método para definir o número do candidato
    void setPartido(const std::string partido); // Método para definir o partido do candidato
    void setCargo(const std::string cargo);     // Método para definir o cargo disputado pelo candidato
    void setVotos(int votos);                   // Método para definir o número de votos recebidos pelo candidato
    void registrar_voto();                      // Método para registrar um voto para o candidato
    void mostrar_dados() const;                 // Método para exibir os dados do candidato
};

#endif // CANDIDATO_HPP