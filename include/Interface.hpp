#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include "Eleitor.hpp"
class Interface{
    private:

    public:
    void Voto();
    void Limpar_dados();
    void inicial();
    bool Logar(std::vector<Eleitor> &eleitores);
    void Cadastrar(std::vector<Eleitor>& eleitores);
    void Resultado();
    void ADM();
    void administrando();
};

#endif // INTERFACE_HPP