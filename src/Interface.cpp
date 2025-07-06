
#include <iostream>
#include <string>
#include <limits>
#include "Security.hpp"
#include "Eleitor.hpp"
#include "Interface.hpp"
#include "json_utils.hpp"

using namespace std;

std::string sessao_atual;

void Interface::limpar_dados()
{
    system("clear || cls");
}
void Interface::inicial()
{
    //Bem vindo ao sistema de votacao brasileiro!
    vector<Eleitor> eleitores = carregarEleitores();

    int opcao = 0;
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Bem vindo ao sistema de votacao brasileiro!   ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl << endl;
    cout << "===========================================" << endl;
    cout << "| 1. Cadastro.                            |" << endl;
    cout << "| 2. Login.                               |" << endl;
    cout << "| 3. Resultado das Eleições.              |" << endl;
    cout << "| 4. Entrar como administrador            |" << endl;
    cout << "===========================================" << endl;
    cout << "Digite uma opcão: " << std::flush;
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
        resultado_eleicoes();
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
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Login                                         ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl << endl;
    cout << "Insira seu nome: ";
    getline(cin >> std::ws, nome);
    cout << "Insira seu CPF: ";
    getline(cin >> std::ws, cpf);
    for (const auto &eleitor : eleitores)
    {
        if (eleitor.getNome() == nome && eleitor.getCpf() == cpf)
        {
            cout << "Login realizado com sucesso!" << endl;
            sessao_atual = eleitor.getNumEleitor();
            return true; // Interrompe o login
        }
        else
        {

            continue;
        }
    }
    cout << "Login falhou. Verifique seu nome e CPF." << endl;
    system("pause");
    limpar_dados();
    return false; // Retorna falso se o eleitor não for encontrado
}
void Interface::dados_logados(const std::vector<Eleitor> &eleitores, const std::string &sessao_atual)
{
    for (const auto &eleitor : eleitores)
    {
        if (eleitor.getNumEleitor() == sessao_atual)
        {
            cout << "Nome: " << eleitor.getNome() << endl;
            cout << "Titulo de eleitor: " << eleitor.getNumEleitor() << endl;
        }
    }
}
void Interface::voto()

{
    int opcao_voto;
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Bem vindo ao sistema de votacao!              ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl << endl;
    dados_logados(carregarEleitores(), sessao_atual);
    cout << endl;
    cout << "===========================================" << endl;
    cout << "| 1. Votar                                 |" << endl;
    cout << "| 2. Vizualizar Lista de Candidatos        |" << endl;
    cout << "| 3. Sair                                  |" << endl;
    cout << "===========================================" << endl;
    cout << "Digite uma opção: " << std::flush;
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
    case 3:
        limpar_dados();
        cout << "Retornando ao menu inicial..." << endl;
        system("pause");
        limpar_dados();
        inicial();
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
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Listagem de candidatos:                       ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl;
    cout << "==========================================" << endl;
    cout << "| 1. Listar por cargo                    |" << endl;
    cout << "| 2. Listar por partido                  |" << endl;
    cout << "| 3. Listar todos os candidatos          |" << endl;
    cout << "==========================================" << endl;   
    cout << "Digite uma opção: " << std::flush;
    int opcao;
    int cargo;
    string partido;
    cin >> opcao;
    switch (opcao)
    {
    case 1:
        limpar_dados();
        cout << "╔═══════════════════════════════════════════════╗" << endl;
        cout << "║ Listar por cargo                              ║" << endl;
        cout << "╚═══════════════════════════════════════════════╝" << endl;
        cout << "===========================================" << endl;
        cout << "| 1. Presidente                           |" << endl;
        cout << "| 2. Governador                           |" << endl;
        cout << "| 3. Sair                                 |" << endl;
        cout << "===========================================" << endl;
        cout << "Digite uma opção: " << std::flush;
        cin >> cargo;
        limpar_dados();
        switch ((cargo))
        {
        case 1:
            for (const auto &candidato : candidatos)
            {
                if (candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente")
                {
                    candidato.mostrar_dados();
                    cout << endl;
                }
            }
            system("pause");
            limpar_dados();
            voto();
            break;
        case 2:
            for (const auto &candidato : candidatos)
            {
                if (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador")
                {
                    candidato.mostrar_dados();
                    cout << endl;
                }
            }
            system("pause");
            limpar_dados();
            voto();
            break;
        case 3:
            cout << "Retornando ao menu de votacao" << endl;
            system("pause");
            limpar_dados();
            voto();
            return;
        default:
            cout << "Opção inválida!" << endl;
            system("pause");
            limpar_dados();
            break;
        }

        system("pause");
        break;
    case 2:
        limpar_dados();
        cout << "╔═══════════════════════════════════════════════╗" << endl;
        cout << "║ Listar por partido                            ║" << endl;
        cout << "╚═══════════════════════════════════════════════╝" << endl;
        cout << "Digite o partido que deseja listar: " << std::flush;
        cin >> partido;
        for (const auto &candidato : candidatos)
        {
            if (candidato.getPartido() == partido)
            {
                candidato.mostrar_dados();
                cout << endl;
            }
        }
        system("pause");
        limpar_dados();
        voto();
        break;
    case 3:
        limpar_dados();
        cout << "Lista de todos os candidatos disponíveis. " << std::flush << endl;
        cout << "===========================================" << endl;
        cout << "| Presidentes                             |" << endl;
        cout << "=========================================== " << endl;
        for (const auto &candidato : candidatos)
        {
            if (candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente")
            {
                candidato.mostrar_dados();
                cout << endl;
            }
        }
        cout << "===========================================" << endl;
        cout << "| Governadores:                           |" << endl;
        cout << "===========================================" << endl;
        for (const auto &candidato : candidatos)
        {
            if (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador")
            {
                candidato.mostrar_dados();
                cout << endl;
            }
        }
        if (candidatos.empty())
        {
            cout << "Nenhum candidato cadastrado." << endl;
        }
        cout << endl;
        system("pause");
        limpar_dados();
        voto();

        break;
    default:
        cout << "Opção inválida" << endl;
        system("pause");
        limpar_dados();
        voto();
        return;
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
        system("pause");
        limpar_dados();
        return;
    }
    if (eleitores.empty())
    {
        cout << "Nenhum eleitor cadastrado." << endl;
        return;
    }

    cout << "Digite o número do candidato que deseja votar: " << std::flush << endl;
    cin >> numero_voto;

    for (auto &candidato : candidatos)
    {
        if (candidato.getNumero() == numero_voto)
        {
            for (auto &eleitor : eleitores)
            {
                if (eleitor.getNumEleitor() == sessao_atual)
                {
                    if ((candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente") && eleitor.getVotouPresidente() == true)
                    {
                        cout << "Você já votou para presidente!" << endl;
                        system("pause");
                        limpar_dados();
                        voto();
                    }

                    if ((candidato.getCargo() == "Governador" || candidato.getCargo() == "governador") && eleitor.getVotouGovernador() == true)
                    {
                        cout << "Você já votou para governador!" << endl;
                        system("pause");
                        limpar_dados();
                        voto();
                    }

                    candidato.mostrar_dados();
                    cout << endl;
                    cout << "Confirmar voto?" << endl;
                    cout << "1. Sim" << endl;
                    cout << "2. Não" << endl;
                    int confirmar;
                    cin >> confirmar;
                    if (confirmar == 1)
                    {
                        if (candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente")
                        {
                            eleitor.setVotouPresidente(true);
                        }
                        else if (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador")
                        {
                            eleitor.setVotouGovernador(true);
                        }
                        salvarEleitores(eleitores);
                        candidato.registrar_voto();
                        salvarCandidatos(candidatos);
                        cout << "Voto registrado com sucesso!" << endl;
                        cout << "Retornando ao menu de votação" << endl;
                        system("pause");
                        limpar_dados();
                        voto();
                    }
                    else if (confirmar == 2)
                    {
                        cout << "Voto cancelado." << endl;
                        cout << "Retornando ao menu de votação" << endl;
                        system("pause");
                        limpar_dados();
                        voto();
                        system("pause");
                    }
                    return;
                }
            }
        }
    }
}

void Interface::resultado_eleicoes()
{
    vector<Candidato> candidatos = carregarCandidatos();
    cout << "=========================================" << endl;
    cout << "|     RESULTADO DAS ELEIÇÕES            |" << endl;
    cout << "=========================================" << endl;

    if (candidatos.empty())
    {
        cout << "Nenhum candidato cadastrado." << endl;
        return;
    }

    int total_votos_presidente = 0;
    int total_votos_governador = 0;

    for (const auto &candidato : candidatos)
    {
        if (candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente")
        {
            total_votos_presidente += candidato.getVotos();
        }
        else if (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador")
        {
            total_votos_governador += candidato.getVotos();
        }
    }

    if (total_votos_presidente == 0 && total_votos_governador == 0)
    {
        cout << "\nNenhum voto foi registado nesta eleição." << endl;
        return;
    }
    sort(candidatos.begin(), candidatos.end(), [](const Candidato &a, const Candidato &b)
         { return a.getVotos() > b.getVotos(); });

    cout << "\n--- VOTAÇÃO POR CANDIDATO PARA PRESIDENTE ---\n\n\n";

    cout << left << setw(25) << "Candidato (Urna)"
         << setw(15) << "Partido"
         << setw(10) << "Votos"
         << "Percentual (%)" << endl;
    cout << "------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    for (const auto &candidato : candidatos)
    {
        if (candidato.getCargo() != "Presidente" && candidato.getCargo() != "presidente")
            continue; // Ignora candidatos que não são presidentes

        double percentual = (static_cast<double>(candidato.getVotos()) / total_votos_presidente) * 100.0;

        cout << left << setw(25) << candidato.getNomeUrna()
             << setw(15) << candidato.getPartido()
             << setw(10) << candidato.getVotos()
             << percentual << "%" << endl;
    }

    cout << "\n--- RESUMO DA VOTACAO ---\n"
         << endl;
    cout << "Total de Votos Apurados: " << total_votos_presidente << endl;

    cout << "\n-----------------------------------------" << endl;

    if (!candidatos.empty() && candidatos[0].getVotos() > 0)
    {
        cout << "VENCEDOR(A): " << candidatos[0].getNomeUrna()
             << " (" << candidatos[0].getPartido() << ")" << endl;
    }
    else
    {
        cout << "Não houve vencedor." << endl;
    }
    cout << "-----------------------------------------" << endl;

    sort(candidatos.begin(), candidatos.end(), [](const Candidato &a, const Candidato &b)
         { return a.getVotos() > b.getVotos(); });

    cout << "\n\n--- VOTAÇÃO POR CANDIDATO PARA GOVERNADOR ---\n\n";

    cout << left << setw(25) << "Candidato (Urna)"
         << setw(15) << "Partido"
         << setw(10) << "Votos"
         << "Percentual (%)" << endl;
    cout << "------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);

    for (const auto &candidato : candidatos)
    {
        if (candidato.getCargo() != "Governador" && candidato.getCargo() != "governador")
            continue;

        double percentual = (static_cast<double>(candidato.getVotos()) / total_votos_governador) * 100.0;

        cout << left << setw(25) << candidato.getNomeUrna()
             << setw(15) << candidato.getPartido()
             << setw(10) << candidato.getVotos()
             << percentual << "%" << endl;
    }

    cout << "\n--- RESUMO DA VOTACAO ---\n"
         << endl;
    cout << "Total de Votos Apurados: " << total_votos_governador << endl;

    cout << "\n-----------------------------------------" << endl;

    if (!candidatos.empty() && candidatos[0].getVotos() > 0)
    {
        cout << "VENCEDOR(A): " << candidatos[0].getNomeUrna()
                << " (" << candidatos[0].getPartido() << ")" << endl;
    }
    else
    {
        cout << "Não houve vencedor." << endl;
    }
    cout << "-----------------------------------------" << endl;

    system("pause");
    limpar_dados();
}


void Interface::cadastrar_eleitor(vector<Eleitor> &eleitores)
{
    string nome, cpf, num_eleitor;
    int idade;
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Cadastro de Eleitor                           ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl << endl;
    cout << "Digite seu nome: " << std::flush;
    getline(cin >> std::ws, nome);
    cout << "Digite seu CPF: " << std::flush;
    getline(cin >> std::ws, cpf);
    cout << "Digite sua idade: " << std::flush;
    cin >> idade;
    if (idade < 16)
    {
        cout << "Você deve ter pelo menos 16 anos para se cadastrar." << endl;
        return;
    }
    for (const auto &eleitor_existente : eleitores)
    {
        if (eleitor_existente.getCpf() == cpf)
        {
            std::cout << "\n>>> ERRO: Este CPF já está cadastrado. <<<" << std::endl;
            cout << "Por favor, verifique os dados e tente novamente." << endl;
            system("pause");
            return; // Interrompe o cadastro
        }
    }
    num_eleitor = gerar_titulo();
    Eleitor e1(false, false, nome, cpf, idade, num_eleitor);
    eleitores.push_back(e1);
    salvarEleitores(eleitores);
    limpar_dados();
    cout << "Cadastro realizado com sucesso!" << endl;
    cout << "Seu número de título de eleitor: " << num_eleitor << endl;
    cout << "Agora você pode votar!" << endl;
    system("pause");
    limpar_dados();
}

void Interface::adm()
{
    Security security;
    string senha;

    cout << "Digite a senha do administrador: ";

    if (security.autenticate_admin())
    {
        limpar_dados();
        menu_admin();
    }
    else
    {
        cout << "Falha na autenticação do administrador." << endl;
    }
}
void Interface::menu_admin()
{
    vector<Candidato> candidatos = carregarCandidatos();

    int Adm_opcao;
    cout << "Bem-vindo ao menu de administração!\n" << endl;
    cout << "Digite uma opção:\n" << endl;
    cout << "1. Cadastrar Candidato" << endl;
    cout << "2. Deletar Candidato" << endl;
    cout << "3. Sair" << endl;
    cin >> Adm_opcao;
    switch (Adm_opcao)
    {
    case 1:
        limpar_dados();
        cadastrarCandidato(candidatos);
        system("pause");
        limpar_dados();
        menu_admin();
        break;
    case 2:
        limpar_dados();
        deletarCandidato(candidatos);
        break;
    case 3:
        cout << "Retornando ao menu inicial..." << endl;
        system("pause");
        limpar_dados();
        inicial();
        break;
    }
}

void Interface::listarCandidatos(const std::vector<Candidato> &candidatos) const
{
    std::cout << "\n--- Lista de Candidatos Cadastrados ---\n";
    if (candidatos.empty())
    {
        std::cout << "Nenhum candidato cadastrado no momento.\n";
        return;
    }

    std::cout << std::left << std::setw(10) << "Número"
              << std::setw(30) << "Nome na Urna"
              << std::setw(20) << "Partido" << std::endl;
    std::cout << "------------------------------------------------------------\n";

    for (const auto &candidato : candidatos)
    {
        std::cout << std::left << std::setw(10) << candidato.getNumero()
                  << std::setw(30) << candidato.getNomeUrna()
                  << std::setw(20) << candidato.getPartido() << std::endl;
    }
    std::cout << "------------------------------------------------------------\n";
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
    cout << "Digite o número de eleitor do candidato: ";
    getline(cin >> std::ws, num_eleitor);
    cout << "Digite o número do candidato: ";
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

    limpar_dados();
}

void Interface::deletarCandidato(std::vector<Candidato> &candidatos)
{
    if (candidatos.empty())
    {
        std::cout << "\nNão há candidatos para deletar." << std::endl;
        limpar_dados();
        menu_admin();
    }

    listarCandidatos(candidatos);

    int numero_para_deletar;
    std::cout << "\nDigite o número do candidato que deseja deletar: ";
    std::cin >> numero_para_deletar;

    if (std::cin.fail())
    {
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        limpar_dados();
        menu_admin();
    }

    int index_encontrado = -1;

    for (long long unsigned int i = 0; i < candidatos.size(); ++i)
    {
        if (candidatos[i].getNumero() == numero_para_deletar)
        {
            index_encontrado = i;
            break;
        }
    }

    if (index_encontrado == -1)
    {
        std::cout << "\nCandidato com o número " << numero_para_deletar << " Não foi encontrado." << std::endl;
        limpar_dados();
        menu_admin();
    }

    std::cout << "\nCandidato encontrado:" << std::endl;
    std::cout << "Nome na Urna: " << candidatos[index_encontrado].getNomeUrna() << std::endl;
    std::cout << "Partido: " << candidatos[index_encontrado].getPartido() << std::endl;

    char confirmacao;

    std::cout << "\nTem certeza que deseja deletar este candidato? [S/N]: ";
    std::cin >> confirmacao;

    if (confirmacao == 'S' || confirmacao == 's')
    {

        candidatos.erase(candidatos.begin() + index_encontrado);

        salvarCandidatos(candidatos);

        std::cout << "\nCandidato deletado com sucesso!" << std::endl;

        limpar_dados();
        menu_admin();
    }
    else
    {
        std::cout << "\nOperação cancelada pelo utilizador." << std::endl;
        limpar_dados();
        menu_admin();
    }
}