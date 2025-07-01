#include "Security.hpp"
#include <iostream>
#include "Interface.hpp"
#include <string>
#include "Estrutura.hpp"
using namespace std;
void Interface::Limpar_dados(){
    system("clear || cls");
}
void Interface::inicial(){
    int opcao=0;
    cout<<"Bem vindo ao sistema de votacao brasileiro!"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"1. Cadastro."<<endl;
    cout<<"2. Login."<<endl;
    cout<<"3. Resultado das Eleições."<<endl;
    cout<<"4. Entrar como administrador"<<endl;
    cin>>opcao;
    switch (opcao) {
    case 1:
        Limpar_dados();
        Cadastrar();
        break;
    case 2:
        Limpar_dados();
        Logar();
        break;
    case 3:
        Limpar_dados();
        Resultado();
        break;
    case 4:
        Limpar_dados();
        ADM();
        break;
    default:
        cout<<"Opcao invalida!"<<endl;
        break;
    // Código se nenhuma das opções anteriores combinar
}
}
    void Interface::Logar() {
        Security security;
        while (1)
        {
            if (security.autenticate_admin())
            {
        
            }
            else
            {

            }
        }
    }
    void Interface::Cadastrar() {
        std::string nome, cpf, nasc;
        cout << "Bem-vindo ao cadastro de usuário!" << endl;
        cout << "Digite seu nome: "<< std::flush << endl;
        getline(cin >> std::ws, nome);
        cout << "Digite seu CPF: "<< std::flush << endl;
        getline(cin >> std::ws, cpf);
        cout << "Digite sua data de nascimento (DD/MM/AAAA)(Sem /): "<< std::flush << endl;
        getline(cin >> std::ws, nasc);
        Cadastro Cadastro(nome, cpf, nasc);
        Cadastro.mostrar_dados();
        cout << endl;
        // Aqui você pode adicionar o código para cadastrar o usuário
    }
    void Interface::Resultado(){
        cout << "Exibindo resultados das eleições..." << endl;
        // Aqui você pode adicionar o código para exibir os resultados das eleições
    }
    void Interface::ADM(){
        Security security;
        string senha;
        if (security.autenticate_admin()) {
            cout << "Bem-vindo, administrador!" << endl;
            administrando();
        } else {
            cout << "Falha na autenticação do administrador." << endl;
        }
    }
    void Interface::administrando() {
        int Adm_opcao;
        string nome, cpf, nasc, nome_urna, partido, cargo;
        cout << "1. Cadastrar Candidato" << endl;
        cout << "2. Deletar Candidatos" << endl;
        cin >> Adm_opcao;
        switch (Adm_opcao) {
        case 1:
            cout << "Cadastrar Candidato" << endl;
            break;
        case 2:
            cout << "Deletar Candidatos" << endl;
            break;
        // Aqui você pode adicionar o código para administrar o sistema
        }
    }