#include <iostream>
#include <cstdlib>
#include <ctime>
const int ano_atual = 2025;

using namespace std;

string num_eleitor(){
    srand(time(nullptr));
    string num = "";
    num += to_string(rand() % 9 + 1);
    for (int i = 1; i < 12; ++i)
        num += to_string(rand() % 10);
    return num;
};

struct usuario{
    string nome;
    string genero;
    string cpf;
    string data_nasc;
    string num_eleitor;
    int idade;
};

class Cadastro{
    private:
    usuario cadastrado;
    public:
    Cadastro(string nome, string cpf, string genero, string nasc){
        cadastrado.nome = nome;
        cadastrado.genero = genero;
        cadastrado.cpf = cpf;
        cadastrado.data_nasc = nasc;
        cadastrado.num_eleitor = num_eleitor();
    string ano = nasc.substr(nasc.size() - 4);
    int ano_nasc = stoi(ano);
         cadastrado.idade = ano_atual - ano_nasc;

    }
    
    void mostrar_dados(){
        cout << "Nome: " << cadastrado.nome << endl << "CPF: " << cadastrado.cpf << endl << "Idade: " << cadastrado.idade << endl << "Titulo de eleitor : " << cadastrado.num_eleitor;;
    }
};

class Candidato : public Cadastro{
    private:
    int numero_candidato;
    string nome_urna;
    string partido;
    string cargo_disputado;
    public:
    Candidato(string nome, string cpf, string genero, string nasc, 
        int numero, string nome_urna, string partido, string cargo): Cadastro(nome, cpf, genero, nasc){
        numero_candidato = numero;
        nome_urna = nome_urna;
        partido = partido;
        cargo_disputado = cargo;
    }
    };

class Eleitor : public Cadastro{
    private:
    bool Votou;
    bool ativo;
};

int main() {
 Cadastro teste("Yuri", "685.492.031-32", "Masculino", "06072004");
 teste.mostrar_dados();
}