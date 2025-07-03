#include "Security.hpp"
#include <iostream>
#include "Interface.hpp"
#include <string>
#include "json_utils.hpp"
#include "Eleitor.hpp"
using namespace std;
void Interface::Limpar_dados()
{
    system("clear || cls");
}
void Interface::inicial()
{
    vector<Eleitor> eleitores = carregarEleitores();
    int opcao = 0;
    cout << "Bem vindo ao sistema de votacao brasileiro!" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "1. Cadastro." << endl;
    cout << "2. Login." << endl;
    cout << "3. Resultado das Eleições." << endl;
    cout << "4. Entrar como administrador" << endl;
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        Limpar_dados();
        Cadastrar(eleitores);
        break;
    case 2:
        Limpar_dados();
        if(Logar(eleitores)){
            Limpar_dados();
            Voto();
        }
        Limpar_dados();
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
        cout << "Opcao invalida!" << endl;
        break;
        // Código se nenhuma das opções anteriores combinar
    }
}
bool Interface::Logar(vector<Eleitor> &eleitores)
{
    string nome, cpf;
    cout << "Insira nome" << endl;
    getline(cin >> std::ws, nome);
    cout << "Insira CPF" << endl;
    getline(cin >> std::ws, cpf);
    for (const auto &eleitor : eleitores)
    {
        if (eleitor.getNome() == nome && eleitor.getCpf() == cpf)
        {
            cout << "Login realizado com sucesso!" << endl;
            // Aqui você pode adicionar o código para logar o usuário
            return true; // Interrompe o login
        }else{
            cout << "Login falhou. Verifique seu nome e CPF." << endl;
            // Aqui você pode adicionar o código para tratar o caso de login falho
            return false;
        }
    }
    cout << "Eleitor nao encontrado." << endl;
    return false; // Retorna falso se o eleitor não for encontrado
}
void Interface::Voto()
{
    cout << "Bem-vindo ao sistema de votação!" << endl;
    cout << "1. Votar" << endl;
    cout << "2. Vizualizar Lista de Candidatos" << endl;
    // Aqui você pode adicionar o código para realizar a votação
    // Por exemplo, exibir candidatos, permitir que o usuário vote, etc.
    cout << "Votação realizada com sucesso!" << endl;
}
void Interface::Cadastrar(vector<Eleitor> &eleitores)
{
    string nome, cpf, num_eleitor;
    int idade;
    cout << "Bem-vindo ao cadastro de usuário!" << endl;
    cout << "Digite seu nome: " << std::flush << endl;
    getline(cin >> std::ws, nome);
    cout << "Digite seu CPF: " << std::flush << endl;
    getline(cin >> std::ws, cpf);
    cout << "Digite sua idade: " << std::flush << endl;
    cin >> idade;
    if (idade < 16)
    {
        cout << "Você deve ter pelo menos 18 anos para se cadastrar." << endl;
        return;
    }
    for (const auto &eleitor_existente : eleitores)
    {
        if (eleitor_existente.getCpf() == cpf)
        {
            std::cout << "\n>>> ERRO: Este CPF ja esta cadastrado. <<<" << std::endl;
            return; // Interrompe o cadastro
        }
    }
    num_eleitor = gerar_titulo();
    Eleitor e1(false, nome, cpf, idade, num_eleitor);
    eleitores.push_back(e1);
    salvarEleitores(eleitores);
    cout << "Cadastro realizado com sucesso!" << endl;
    // Aqui você pode adicionar o código para cadastrar o usuário
}
void Interface::Resultado()
{
    cout << "Exibindo resultados das eleições..." << endl;
    // Aqui você pode adicionar o código para exibir os resultados das eleições
}
void Interface::ADM()
{
    Security security;
    string senha;
    if (security.autenticate_admin())
    {
        cout << "Bem-vindo, administrador!" << endl;
        administrando();
    }
    else
    {
        cout << "Falha na autenticação do administrador." << endl;
    }
}
void Interface::administrando()
{
    int Adm_opcao;
    string nome, cpf, nasc, nome_urna, partido, cargo;
    cout << "1. Cadastrar Candidato" << endl;
    cout << "2. Deletar Candidatos" << endl;
    cin >> Adm_opcao;
    switch (Adm_opcao)
    {
    case 1:
        cout << "Cadastrar Candidato" << endl;
        break;
    case 2:
        cout << "Deletar Candidatos" << endl;
        break;
        // Aqui você pode adicionar o código para administrar o sistema
    }
}