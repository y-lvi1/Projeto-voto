#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP
#include "Cadastro.hpp"
#include <iostream>

class Candidato : public Cadastro {
private:
    int numero_candidato;
    std::string nome_urna;
    std::string partido;
    std::string cargo_disputado;
int votos = 0;
public:

    Candidato();
    Candidato(std::string nome, std::string cpf, int idade, std::string num_eleitor,
              int numero, std::string nome_urna, std::string partido, std::string cargo);

    std::string getNomeUrna() const;
    std::string getPartido() const;
    std::string getCargo() const;
    int getVotos() const;
    int getNumero() const;

    void setNome(const std::string nome);
    void setNumero(int numero);
    void setPartido(const std::string partido);
    void setCargo(const std::string cargo);
void setVotos(int votos);
    void registrar_voto();
    void mostrar_dados() const;
};
#endif
