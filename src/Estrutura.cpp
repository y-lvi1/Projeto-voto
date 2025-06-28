#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Estrutura.hpp"
using namespace std;

// Gerador do titulo de eleitor
string num_eleitor(){
    srand(time(nullptr));
    string num = "";
    num += to_string(rand() % 9 + 1);
    for (int i = 1; i < 12; ++i)
        num += to_string(rand() % 10);
    return num;
}
//Cadastro do usuario no sistema
Cadastro::Cadastro(string nome, string cpf, string nasc)    {
    cadastrado.nome = nome;
    cadastrado.cpf = cpf;
    cadastrado.data_nasc = nasc;
    cadastrado.num_eleitor = num_eleitor();

    string ano = nasc.substr(nasc.size() - 4);
    int ano_nasc = stoi(ano);
    cadastrado.idade = ano_atual - ano_nasc;
}
    //Getters do Cadastro
    string Cadastro::getNome() const {return cadastrado.nome;}
    string Cadastro::getCpf() const {return cadastrado.cpf;}
    string Cadastro::getNasc() const {return cadastrado.data_nasc;}
    int Cadastro::getIdade() const {return cadastrado.idade;}
//Setters cadastro
void Cadastro::setNome(const string Nome){cadastrado.nome = Nome;}
void Cadastro::setCpf(const string cpf){cadastrado.cpf = cpf;}
void Cadastro::setData_nasc(const string nascimento){cadastrado.data_nasc = nascimento;}

void Cadastro::mostrar_dados(){
        cout << "Nome: " << cadastrado.nome << endl << "CPF: " << cadastrado.cpf << endl << 
        "Idade: " << cadastrado.idade << endl << "Titulo de eleitor : " << cadastrado.num_eleitor;;
    }
//Dados candidato
Candidato::Candidato(string nome, string cpf, string nasc, 
        int numero, string nome_urn, string partid, string cargo): Cadastro(nome, cpf, nasc){
        numero_candidato = numero;
        nome_urna = nome_urn;
        partido = partid;
        cargo_disputado = cargo;
    }
void Candidato::mostrar_dados(){ 
cout << "Nome: " << nome_urna << endl << "cargo disputado" << 
cargo_disputado << endl << "Numero do candidato: " << numero_candidato << endl << "Partido: " << partido << endl;}
//Getters do Candidato
string Candidato::getNomeUrna() const {return nome_urna;}
string Candidato::getPartido() const {return partido;}
string Candidato::getCargo() const {return cargo_disputado;}

//Setters do candidato
void Candidato::setNome(const string Nome){nome_urna = Nome;}
void Candidato::setNumero(const int numero){numero_candidato = numero;} 
void Candidato::setPartido(const string Partido){partido = Partido;}
void Candidato::setCargo(const string Cargo){cargo_disputado = Cargo;}

    void Candidato::registrar_voto(){
    votos++;
    }

 //Dados eleitor   
Eleitor::Eleitor(bool voto, string nome, string cpf, string nasc) : Cadastro(nome, cpf, nasc){
    Votou = voto;
    }

//Get e set
    bool Eleitor::getVoto() const {return Votou;}
    void Eleitor::setVoto(const bool VotoApurado){Votou = VotoApurado;}

    void Eleitor::votar(Candidato& votacao){
        if (getVoto()){
          cout << "Usuário ja realizou o voto." << endl;
        }
        else{
         votacao.registrar_voto();
         Votou = true;
         cout << "Voto registrado." << endl;
        }
    }
