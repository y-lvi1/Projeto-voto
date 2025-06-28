#include "Security.hpp"
#include <iostream>
#include "Interface.hpp"
#include <string>
#include "Estrutura.hpp"
using namespace std;
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
        Cadastrar();
        break;
    case 2:
        Logar();
        break;
    case 3:
        Resultado();
        break;
    case 4:
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
        string nome, cpf, nasc;
        cout << "Bem-vindo ao cadastro de usuário!" << endl;
        cout << "Digite seu nome: "<< endl;
        getline(cin, nome);
        cout << "Digite seu CPF: "<< endl;
        getline(cin, cpf);
        cout << "Digite sua data de nascimento (DD/MM/AAAA): "<< endl;
        getline(cin, nasc);
        Cadastro Cadastro(nome, cpf, nasc);
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
        cout << "1. Cadastrar Candidato" << endl;
        cout << "2. Deletar Candidatos" << endl;
        cin >> Adm_opcao;
        switch (Adm_opcao) {
        case 1:
            // Cadastrar Candidato

            break;
        case 2:
            cout << "Deletar Candidatos" << endl;

            break;
        // Aqui você pode adicionar o código para administrar o sistema
        }
    }