#include "Security.hpp"
#include <iostream>
#include "Interface.hpp"
#include <string>
#include "json_utils.hpp"
#include "Eleitor.hpp"

using namespace std;

std::string sessao_atual;

void Interface::limpar_dados()
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
        limpar_dados();
        cadastrar_eleitor(eleitores);
        break;
    case 2:
        limpar_dados();
        if (logar(eleitores))
        {
            limpar_dados();
            voto();
        }
        limpar_dados();
        break;
    case 3:
        limpar_dados();
        resultado();
        break;
    case 4:
        limpar_dados();
        adm();
        break;
    default:
        cout << "Opcao invalida!" << endl;
        break;
        // Código se nenhuma das opções anteriores combinar
    }
}
bool Interface::logar(vector<Eleitor> &eleitores)
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
            sessao_atual = eleitor.getNumEleitor();
            // Aqui você pode adicionar o código para logar o usuário
            return true; // Interrompe o login
        }
        else
        {
            // Aqui você pode adicionar o código para tratar o caso de login falho
            continue;
        }
    }
    cout << "Login falhou. Verifique seu nome e CPF." << endl;
    return false; // Retorna falso se o eleitor não for encontrado
}
void Interface::dados_logados(const std::vector<Eleitor> &eleitores, const std::string &sessao_atual){
    for(const auto &eleitor : eleitores){
        if(eleitor.getNumEleitor() == sessao_atual){
            cout << "Nome: " << eleitor.getNome() << endl;
            cout << "Titulo de eleitor: " << eleitor.getNumEleitor() << endl;
        }
    }
}
void Interface::voto()

{
    int opcao_voto;
    cout << "Bem-vindo ao sistema de votação!" << endl;
    dados_logados(carregarEleitores(), sessao_atual);
    cout << endl;
    cout << "1. Votar" << endl;
    cout << "2. Vizualizar Lista de Candidatos" << endl;
    cin >> std::ws;
    cin >> opcao_voto;
    switch (opcao_voto)
    {
        case 1:
            limpar_dados();
            // Vote aqui
            votando();
            break;
        case 2:
        limpar_dados();
        mostrar_candidatos(carregarCandidatos());
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
    }
    // Aqui você pode adicionar o código para realizar a votação
    // Por exemplo, exibir candidatos, permitir que o usuário vote, etc.
    cout << "Votação realizada com sucesso!" << endl;
}
void Interface::mostrar_candidatos(const std::vector<Candidato> &candidatos)
{
    cout << "1.Listar por cargo" << endl;
    cout << "2.Listar por partido" << endl;
    cout << "3.Listar todos os candidatos" << endl;
    int opcao;
    string cargo;
    string partido;
    cin >> opcao;
    switch(opcao){
        case 1:
        cout << "Digite o cargo que deseja listar: " << std::flush << endl;
        cin >> cargo;
        for(const auto &candidato : candidatos)
        {
            if(candidato.getCargo() == cargo)
            {
                candidato.mostrar_dados();
                cout << endl;
            }
        }
        system("pause");
        break;
        case 2:
        cout << "Digite o partido que deseja listar: " << std::flush << endl;
        cin >> partido;
        for(const auto &candidato : candidatos)
        {
            if (candidato.getPartido() == partido)
            {
                candidato.mostrar_dados();
                cout << endl;
            }
        }
        system("pause");
        break;
        case 3:
        cout << "Lista de todos os candidatos disponiveis: " << std::flush << endl;
        for(const auto &candidato : candidatos){
            candidato.mostrar_dados();
            cout << endl;
            system("pause");
        }
    }

}
void Interface::votando()
{
    int numero_voto;

    vector<Candidato> candidatos = carregarCandidatos();
    vector<Eleitor> eleitores = carregarEleitores();

    if (candidatos.empty())
    {
        cout << "Nenhum candidato cadastrado." << endl;
        return;
    }
    if (eleitores.empty())
    {
        cout << "Nenhum eleitor cadastrado." << endl;
        return;
    }

    cout << "Digite o numero do candidato que deseja votar: "<< std::flush << endl;
    cin >> numero_voto;

    for (auto &candidato : candidatos)
    {
        if (candidato.getNumero() == numero_voto)
        {
            // Verifica se o eleitor já votou
            for (auto &eleitor : eleitores)
            {
                if (eleitor.getNumEleitor() == sessao_atual)
                {
                    eleitor.setVotou(true); // Marca o eleitor como tendo votado
                    salvarEleitores(eleitores); // Salva a alteração no arquivo
                    cout << "Eleitor " << eleitor.getNome() << " votou no candidato ";
                    return;
                }
            }
            // Registra o voto
            //candidato.registrar_voto();
            cout << "Voto registrado com sucesso!" << endl;
            return;
        }
    }
    
    /*cout << "Lista de Candidatos:" << endl;
    for (const auto &candidato : candidatos)
    {
        cout << "Nome: " << candidato.getNome() << ", Numero: " << candidato.getNumero() << ", Partido: " << candidato.getPartido() << endl;
    }
    int numero_voto;
    cout << "Digite o numero do candidato que deseja votar: ";
    cin >> numero_voto;

    bool voto_valido = false;
    for (auto &candidato : candidatos)
    {
        if (candidato.getNumero() == numero_voto)
        {
            candidato.registrar_voto();
            voto_valido = true;
            cout << "Voto registrado com sucesso!" << endl;
            break;
        }
    }
    if (!voto_valido)
    {
        cout << "Voto invalido. Tente novamente." << endl;
    }*/
}
void Interface::cadastrar_eleitor(vector<Eleitor> &eleitores)
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
void Interface::resultado()
{
    cout << "Exibindo resultados das eleições..." << endl;
    // Aqui você pode adicionar o código para exibir os resultados das eleições
}
void Interface::adm()
{
    Security security;
    string senha;

    cout << "Digite a senha do administrador: ";

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
    vector<Candidato> candidatos = carregarCandidatos();

    int Adm_opcao;
    cout << "Bem-vindo ao menu de administração!" << endl;
    cout << "1. Cadastrar Candidato" << endl;
    cout << "2. Deletar Candidato" << endl;
    cin >> Adm_opcao;
    switch (Adm_opcao)
    {
    case 1:
        cadastrarCandidato(candidatos);
        break;
    case 2:
        cout << "Deletar Candidatos" << endl;
        break;
        // Aqui você pode adicionar o código para administrar o sistema
    }
}

void Interface::cadastrarCandidato(vector<Candidato> &candidatos)
{
    string nome, cpf, num_eleitor, nome_urna, partido, cargo;
    int idade, numero_candidato;
    cout << "Cadastrar Candidato" << endl;
    cout << "Digite o nome do candidato: ";
    getline(cin >> std::ws, nome);
    cout << "Digite o CPF do candidato: ";
    getline(cin >> std::ws, cpf);
    cout << "Digite a idade do candidato: ";
    cin >> idade;
    cout << "Digite o numero de eleitor do candidato: ";
    getline(cin >> std::ws, num_eleitor);
    cout << "Digite o numero do candidato: ";
    cin >> numero_candidato;
    cout << "Digite o nome de urna do candidato: ";
    getline(cin >> std::ws, nome_urna);
    cout << "Digite o partido do candidato: ";
    getline(cin >> std::ws, partido);
    cout << "Digite o cargo disputado pelo candidato: ";
    getline(cin >> std::ws, cargo);

    Candidato c1(nome, cpf, idade, num_eleitor, numero_candidato, nome_urna, partido, cargo);
    candidatos.push_back(c1);
    salvarCandidatos(candidatos);

    cout << "Candidato cadastrado com sucesso!" << endl;
}