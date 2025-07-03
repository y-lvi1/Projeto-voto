#include "Eleitor.hpp"

Eleitor::Eleitor() = default;

Eleitor::Eleitor(bool votou, std::string nome, std::string cpf, int idade, std::string num_eleitor)
    : Cadastro(nome, cpf, idade, num_eleitor), votou(votou) {}

bool Eleitor::getVotou() const {
    return votou;
}
void Eleitor::setVotou(bool votou){this->votou = votou;}