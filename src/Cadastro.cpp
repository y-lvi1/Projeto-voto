#include "Cadastro.hpp"
#include <stdexcept>

// Construtor default (requisito da biblioteca json)
Cadastro::Cadastro() = default;

// Construtor com parâmetros
Cadastro::Cadastro(std::string nome, std::string cpf, int idade, std::string num_eleitor) : nome(nome), cpf(cpf), idade(idade), num_eleitor(num_eleitor) { 
    if (nome.empty() || cpf.empty()) {
        throw std::invalid_argument("Nome e CPF não podem estar vazios.");
    }
    if (idade <= 0) {
        throw std::invalid_argument("Idade deve ser maior que zero.");
    }}
// Destrutor
Cadastro::~Cadastro() = default;

std::string Cadastro::getNome() const { return nome; }              // Getter para o nome
std::string Cadastro::getCpf() const { return cpf; }                // Getter para o CPF
std::string Cadastro::getNumEleitor() const { return num_eleitor; } // Getter para o número do eleitor
int Cadastro::getIdade() const { return idade; }                    // Getter para a idade