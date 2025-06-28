#include "Security.hpp"
#include <iostream>
#include "Interface.hpp"
#include <string>
using namespace std;
void Interface::inicial(){
    string opcao="";
    cout<<"Bem vindo ao sistema de votacao brasileiro!"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"1. Cadastro."<<endl;
    cout<<"2. Login."<<endl;
    cout<<"3. Resultado das Eleições."<<endl;
    cout<<"4. Entrar como administrador"<<endl;
    cin>>opcao;
    if(opcao == "1"){
        Cadastrar();
    }
    if(opcao == "2"){
        Logar();
    }
    if(opcao == "3"){
        Resultado();
    }
    if(opcao == "4"){
        ADM();
    }
    else{
        cout<<"Opcao invalida!"<<endl;
    }
}
    void Logar() {
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
    void Cadastrar() {
        
    }
    void Resultado(){

    }
    void ADM(){

    }
