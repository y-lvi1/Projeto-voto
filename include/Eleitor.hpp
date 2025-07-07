#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include "Cadastro.hpp"

extern std::string sessao_atual;

class Eleitor : public Cadastro
{
private:
    bool votouPresidente;
    bool votouGovernador;

public:
    Eleitor();
    Eleitor(bool votouPresidente, bool votouGovernador, std::string nome, std::string cpf, int idade, std::string num_eleitor);

    bool getVotouPresidente() const;
    void setVotouPresidente(bool votou);
    bool getVotouGovernador() const;
    void setVotouGovernador(bool votou);
};
#endif