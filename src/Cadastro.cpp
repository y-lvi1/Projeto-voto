#include "Cadastro.hpp"

// Construtor default (requisito da biblioteca json)
Cadastro::Cadastro() = default;

// Construtor com parâmetros
Cadastro::Cadastro(std::string nome, std::string cpf, int idade, std::string num_eleitor) : nome(nome), cpf(cpf), idade(idade), num_eleitor(num_eleitor) {}

// Destrutor
Cadastro::~Cadastro() = default;

std::string Cadastro::getNome() const { return nome; }              // Getter para o nome
std::string Cadastro::getCpf() const { return cpf; }                // Getter para o CPF
std::string Cadastro::getNumEleitor() const { return num_eleitor; } // Getter para o número do eleitor
int Cadastro::getIdade() const { return idade; }                    // Getter para a idade