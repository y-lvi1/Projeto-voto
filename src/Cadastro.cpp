#include "Cadastro.hpp"

Cadastro::Cadastro() = default;

Cadastro::Cadastro(std::string nome, std::string cpf, int idade, std::string num_eleitor): nome(nome), cpf(cpf), idade(idade), num_eleitor(num_eleitor) {}

Cadastro::~Cadastro() = default;

std::string Cadastro::getNome() const { return nome; }
std::string Cadastro::getCpf() const { return cpf; }
std::string Cadastro::getNumEleitor() const { return num_eleitor; }
int Cadastro::getIdade() const { return idade; }
