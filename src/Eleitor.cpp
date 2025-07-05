#include "Eleitor.hpp"

Eleitor::Eleitor() = default;

Eleitor::Eleitor(bool votouPresidente, bool votouGovernador, std::string nome, std::string cpf, int idade, std::string num_eleitor)
    : Cadastro(nome, cpf, idade, num_eleitor), votouPresidente(votouPresidente), votouGovernador(votouGovernador) {}

bool Eleitor::getVotouPresidente() const {
    return votouPresidente;
}
bool Eleitor::getVotouGovernador() const {
    return votouGovernador;
}
void Eleitor::setVotouPresidente(bool votou){this->votouPresidente = votou;}
void Eleitor::setVotouGovernador(bool votou){this->votouGovernador = votou;}