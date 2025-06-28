#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP
#include <string>
namespace usuario{
    struct usuario;
    std::string num_eleitor();
}
class Cadastro{};
class Candidato : public Cadastro{};
class Eleitor : public Cadastro{};
#endif