#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#include <string>

class Cadastro{
protected:
    std::string nome;
    std::string cpf;
    int idade;
    std::string num_eleitor;
public:
    Cadastro();
    Cadastro(std::string nome, std::string cpf, int idade, std::string num_eleitor);
    virtual ~Cadastro();

    std::string getNome() const;
    std::string getCpf() const;
    std::string getNumEleitor() const;
    int getIdade() const;
};
#endif