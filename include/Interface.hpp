#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <vector>
#include "Eleitor.hpp"
#include "Candidato.hpp"

class Interface
{
private:
public:
    void votando();
    void mostrar_candidatos(const std::vector<Candidato> &candidatos);
    void dados_logados(const std::vector<Eleitor> &eleitores, const std::string &sessao_atual);
    void voto();
    void limpar_dados();
    void inicial();
    bool logar(std::vector<Eleitor> &eleitores);
    void cadastrar_eleitor(std::vector<Eleitor> &eleitores);
    void resultado();
    void adm();
    void administrando();
    void cadastrarCandidato(std::vector<Candidato> &candidatos);
};

#endif // INTERFACE_HPP