#include "Eleitor.hpp"

// Construtor padrão (requisito da biblioteca json)
Eleitor::Eleitor() = default;

// Construtor com parâmetros
// Inicializa os atributos do eleitor, incluindo se já votou para presidente e governador
Eleitor::Eleitor(bool votouPresidente, bool votouGovernador, std::string nome, std::string cpf, int idade, std::string num_eleitor)
    : Cadastro(nome, cpf, idade, num_eleitor), votouPresidente(votouPresidente), votouGovernador(votouGovernador) {}

bool Eleitor::getVotouPresidente() const { return votouPresidente; }            // Getter para verificar se o eleitor votou para presidente
bool Eleitor::getVotouGovernador() const { return votouGovernador; }            // Getter para verificar se o eleitor votou para governador
void Eleitor::setVotouPresidente(bool votou) { this->votouPresidente = votou; } // Setter para definir se o eleitor votou para presidente
void Eleitor::setVotouGovernador(bool votou) { this->votouGovernador = votou; } // Setter para definir se o eleitor votou para governador