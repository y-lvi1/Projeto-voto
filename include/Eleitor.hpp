#ifndef ELEITOR_HPP
#define ELEITOR_HPP

#include "Cadastro.hpp"

extern std::string sessao_atual;

class Eleitor : public Cadastro {
private:
    bool votou;

public:
    Eleitor();
    Eleitor(bool votou, std::string nome, std::string cpf, int idade, std::string num_eleitor);

    bool getVotou() const;
    void setVotou(bool votou);
};
#endif