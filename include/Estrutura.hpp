#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP

namespace usuario{
    string num_eleitor();
    struct usuario;
    class cadastro;
    class Candidato : public Cadastro;
    class Eleitor : public Cadastro;
}
#endif //