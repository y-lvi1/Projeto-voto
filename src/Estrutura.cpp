#include <iostream>
#include <cstdlib>
#include <ctime>
const int ano_atual = 2025;

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
// Dados do usuario
struct usuario{
    string nome;
    string cpf;
    string data_nasc;
    string num_eleitor;
    int idade;
};

//Cadastro do usuario no sistema
class Cadastro{
    private:
    usuario cadastrado;
    public:
    Cadastro(string nome, string cpf, string nasc){
        cadastrado.nome = nome;
        cadastrado.cpf = cpf;
        cadastrado.data_nasc = nasc;
        cadastrado.num_eleitor = num_eleitor();
    string ano = nasc.substr(nasc.size() - 4);
    int ano_nasc = stoi(ano);
         cadastrado.idade = ano_atual - ano_nasc;

    }
    //Getters do Cadastro
    string getNome() const {return cadastrado.nome;}
    string getCpf() const {return cadastrado.cpf;}
    string getNasc() const {return cadastrado.data_nasc;}
    int getIdade() const {return cadastrado.idade;}
//Setters cadastro
void setNome(const string Nome){cadastrado.nome = Nome;}
void setCpf(const string cpf){cadastrado.cpf = cpf;}
void setData_nasc(const string nascimento){cadastrado.data_nasc = nascimento;}

virtual void mostrar_dados(){
        cout << "Nome: " << cadastrado.nome << endl << "CPF: " << cadastrado.cpf << endl << "Idade: " << cadastrado.idade << endl << "Titulo de eleitor : " << cadastrado.num_eleitor;;
    }
};

//Dados candidato
class Candidato : public Cadastro{
    private:
    int numero_candidato;
    string nome_urna;
    string partido;
    string cargo_disputado;
    public:
    int votos = 0;
    Candidato(string nome, string cpf, string nasc, 
        int numero, string nome_urna, string partido, string cargo): Cadastro(nome, cpf, nasc){
        numero_candidato = numero;
        nome_urna = nome_urna;
        partido = partido;
        cargo_disputado = cargo;
    }

//Getters do Candidato
string getNomeUrna() const {return nome_urna;}
string getPartido() const {return partido;}
string getCargo() const {return cargo_disputado;}

//Setters do candidato
void setNome(const string Nome){nome_urna = Nome;}
void setNumero(const int numero){numero_candidato = numero;} 
void setPartido(const string Partido){partido = Partido;}
void setCargo(const string Cargo){cargo_disputado = Cargo;}

      void mostrar_dados() override{
        cout << "Nome: " << nome_urna << endl << "cargo disputado" << cargo_disputado << endl << "Numero do candidato: " << numero_candidato << endl << "Partido: " << partido << endl;
    }

    void registrar_voto(){
    votos++;
    }
    };

 //Dados eleitor   
class Eleitor : public Cadastro{
    private:
    bool Votou;
    public:
    Eleitor(bool voto, string nome, string cpf, string nasc) : Cadastro(nome, cpf, nasc){
    Votou = voto;
    }
//Get e set
    bool getVoto() const {return Votou;}
    void setVoto(const bool VotoApurado){Votou = VotoApurado;}

    void votar(Candidato& votacao){
        if (getVoto()){
          cout << "Usuário ja realizou o voto." << endl;
        }
        else{
         votacao.registrar_voto();
         Votou = true;
         cout << "Voto registrado." << endl;
        }
    }
};
