#ifndef ESTRUTURA_HPP
#define ESTRUTURA_HPP
#include <string>

const int ano_atual = 2025;

std::string num_eleitor(); // Geração do título de eleitor

struct usuario
{
    std::string nome;
    std::string cpf;
    std::string data_nasc;
    std::string num_eleitor;
    int idade;
};

class Cadastro
{
private:
    usuario cadastrado;

public:
    Cadastro(std::string nome, std::string cpf, std::string nasc);

    std::string getNome() const;
    std::string getCpf() const;
    std::string getNasc() const;
    int getIdade() const;

    void setNome(const std::string Nome);
    void setCpf(const std::string cpf);
    void setData_nasc(const std::string nascimento);
    virtual void mostrar_dados();
};

class Candidato : public Cadastro
{
private:
    int numero_candidato;
    std::string nome_urna;
    std::string partido;
    std::string cargo_disputado;

public:
    int votos = 0;
    Candidato(std::string nome, std::string cpf, std::string nasc,
              int numero, std::string nome_urna, std::string partido, std::string cargo);

    std::string getNomeUrna() const;
    std::string getPartido() const;
    std::string getCargo() const;

    void setNome(const std::string Nome);
    void setNumero(const int numero);
    void setPartido(const std::string Partido);
    void setCargo(const std::string Cargo);

    void mostrar_dados() override;
    void registrar_voto();
};

class Eleitor : public Cadastro
{
private:
    bool Votou;

public:
    Eleitor(bool voto, std::string nome, std::string cpf, std::string nasc);
    bool getVoto() const;
    void setVoto(const bool VotoApurado);
    void votar(Candidato &votacao);
};
#endif