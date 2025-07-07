
#include <iostream>
#include <string>
#include <limits>
#include "Security.hpp"
#include "Eleitor.hpp"
#include "Interface.hpp"
#include "json_utils.hpp"
#include "Logger.hpp"

using namespace std;

std::string sessao_atual; // Variável global para armazenar sessão atual

/**
 * @brief Limpa a tela do console.
 *
 * Esta função utiliza o comando "clear" no Linux/Unix ou "cls" no Windows para limpar a tela do console.
 * É útil para manter a interface do usuário limpa e organizada, especialmente após a execução de ações
 */

void Interface::limpar_dados()
{
    system("clear || cls");
}

/**
 * @brief Inicializa o sistema de votação.
 *
 * Esta função exibe o menu inicial do sistema de votação brasileiro, permitindo que o usuário escolha entre cadastrar um eleitor, fazer login, ver resultados das eleições ou entrar como administrador.
 */
void Interface::inicial()
{
    // Carrega os eleitores do arquivo JSON
    // Se o arquivo não existir, ele será criado automaticamente
    vector<Eleitor> eleitores = carregarEleitores();

    int opcao = 0; // Variável para armazenar a opção escolhida pelo usuário

    while (1)
    {
        cout << "╔═══════════════════════════════════════════════╗" << endl;
        cout << "║ Bem vindo ao sistema de votacao brasileiro!   ║" << endl;
        cout << "╚═══════════════════════════════════════════════╝" << endl
             << endl;
        cout << "===========================================" << endl;
        cout << "| 1. Cadastro.                            |" << endl;
        cout << "| 2. Login.                               |" << endl;
        cout << "| 3. Resultado das Eleições.              |" << endl;
        cout << "| 4. Entrar como administrador            |" << endl;
        cout << "===========================================" << endl;
        cout << "Digite uma opcão: " << std::flush;

        cin >> opcao;

        // Limpa o buffer de entrada para evitar problemas com entradas subsequentes
        if (std::cin.fail())
        {
            Logger::log("Entrada inválida no menu inicial.");
            std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            limpar_dados();
            continue;
        }

        switch (opcao)
        {

        // Menu de cadastro
        case 1:

            limpar_dados();
            cadastrar_eleitor(eleitores);
            break;

        // Menu de login
        case 2:

            limpar_dados();
            if (logar(eleitores))
            {
                Logger::log("Eleitor " + sessao_atual + " logou no sistema.");
                limpar_dados();
                voto();
            }
            limpar_dados();
            break;

        // Menu de resultados das eleições
        case 3:

            limpar_dados();
            resultado_eleicoes();
            break;

        // Menu de administrador
        case 4:

            limpar_dados();
            adm();
            break;

        // Opção inválida
        default:
            limpar_dados();
            cout << "Opcao invalida!" << endl;
            Logger::log("Opção inválida no menu inicial.");
            system("pause");
            break;
        }
    }
}

/**
 * @brief Realiza o login do eleitor.
 *
 * Esta função solicita o nome e CPF do eleitor, verifica se os dados estão corretos e inicia a sessão do eleitor se o login for bem-sucedido.
 *
 * @param eleitores Vetor de eleitores cadastrados.
 *
 * @return true Se o login for bem-sucedido.
 * @return false Se o login falhar.
 */

bool Interface::logar(vector<Eleitor> &eleitores)
{
    string nome, cpf; // Variáveis para armazenar o nome e CPF do eleitor

    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Login                                         ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl
         << endl;
    cout << "Insira seu nome: ";
    getline(cin >> std::ws, nome);
    cout << "Insira seu CPF: ";
    getline(cin >> std::ws, cpf);

    if (nome.empty() || cpf.empty())
    {
        cout << "Nome ou CPF não podem ser vazios." << endl;
        system("pause");
        limpar_dados();
        return false; // Retorna falso se o nome ou CPF estiverem vazios
    }

    // Verifica se o nome e CPF correspondem a algum eleitor cadastrado
    for (const auto &eleitor : eleitores)
    {
        if (eleitor.getNome() == nome && eleitor.getCpf() == cpf)
        {
            cout << "Login realizado com sucesso!" << endl;
            sessao_atual = eleitor.getNumEleitor();
            system("pause");
            return true;
        }
    }

    cout << "Login falhou. Verifique seu nome e CPF." << endl;

    system("pause");
    limpar_dados();
    return false; // Retorna falso se o eleitor não for encontrado
}

/**
 * @brief Exibe os dados do eleitor logado.
 *
 * Esta função exibe o nome e o número do título de eleitor do eleitor que está atualmente logado.
 *
 * @param eleitores Vetor de eleitores cadastrados.
 * @param sessao_atual Número do título de eleitor da sessão atual.
 */

void Interface::dados_logados(const std::vector<Eleitor> &eleitores, const std::string &sessao_atual)
{
    // Verifica quem está logado
    for (const auto &eleitor : eleitores)
    {
        if (eleitor.getNumEleitor() == sessao_atual)
        {
            cout << "Nome: " << eleitor.getNome() << endl;
            cout << "Titulo de eleitor: " << eleitor.getNumEleitor() << endl;
        }
    }
}

/**
 * @brief Inicia o processo de votação.
 *
 * Esta função exibe o menu de votação, permitindo que o eleitor vote, visualize a lista de candidatos ou saia do sistema.
 */

void Interface::voto()

{
    int opcao_voto; // Variável para armazenar a opção de voto escolhida pelo usuário

    // Loop infinito para manter o menu de votação ativo
    // O loop só será interrompido quando o usuário escolher a opção de sair
    // ou quando o programa for encerrado

    while (1)
    {
        cout << "╔═══════════════════════════════════════════════╗" << endl;
        cout << "║ Bem vindo ao sistema de votacao!              ║" << endl;
        cout << "╚═══════════════════════════════════════════════╝" << endl
             << endl;

        dados_logados(carregarEleitores(), sessao_atual); // Exibe os dados do eleitor logado

        cout << endl;
        cout << "===========================================" << endl;
        cout << "| 1. Votar                                 |" << endl;
        cout << "| 2. Vizualizar Lista de Candidatos        |" << endl;
        cout << "| 3. Sair                                  |" << endl;
        cout << "===========================================" << endl;
        cout << "Digite uma opção: " << std::flush;

        cin >> std::ws;
        cin >> opcao_voto;

        // Limpa o buffer de entrada para evitar problemas com entradas subsequentes
        if (std::cin.fail())
        {
            Logger::log("Entrada inválida no menu de votação.");
            std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            limpar_dados();
            continue;
        }

        switch (opcao_voto)
        {

        // Opção 1: Votar
        case 1:
            Logger::log("Eleitor " + sessao_atual + " iniciou o processo de votação.");
            limpar_dados();
            votando();
            break;

        // Opção 2: Visualizar lista de candidatos
        case 2:

            limpar_dados();
            mostrar_candidatos(carregarCandidatos());
            break;

        // Opção 3: Sair do sistema
        case 3:

            limpar_dados();
            cout << "Retornando ao menu inicial..." << endl;
            system("pause");
            limpar_dados();
            inicial();
            return;
            break;

        // Opção inválida
        default:
            limpar_dados();
            cout << "Opção inválida!" << endl;
            Logger::log("Opção inválida no menu de votação.");
            system("pause");
            break;
        }
    }
}

/**
 * @brief Exibe a lista de candidatos disponíveis para votação.
 *
 * Esta função permite que o usuário visualize os candidatos por cargo, por partido ou todos os candidatos.
 *
 * @param candidatos Vetor de candidatos cadastrados.
 */

void Interface::mostrar_candidatos(const std::vector<Candidato> &candidatos)
{
    int opcao;      // Variável para armazenar a opção escolhida pelo usuário
    int cargo;      // Variável para armazenar o cargo escolhido pelo usuário
    string partido; // Variável para armazenar o partido escolhido pelo usuário

    while (1)
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

        cin >> opcao;

        // Limpa o buffer de entrada para evitar problemas com entradas subsequentes
        if (std::cin.fail())
        {
            Logger::log("Entrada inválida no menu de listagem de candidatos.");
            std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            limpar_dados();
            continue;
        }

        switch (opcao)
        {
        // Opção 1: Listar candidatos por cargo
        // O usuário pode escolher entre Presidente ou Governador
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

            // Limpa o buffer de entrada para evitar problemas com entradas subsequentes
            if (std::cin.fail())
            {
                Logger::log("Entrada inválida no menu de listagem por cargo.");
                std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                limpar_dados();
                continue;
            }

            limpar_dados();

            switch ((cargo))
            {

            // Se o usuário escolher Presidente, exibe os candidatos a presidente
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
                return;
                break;

            // Se o usuário escolher Governador, exibe os candidatos a governador
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
                return;
                break;

            // Se o usuário escolher Sair, retorna ao menu de listagem
            case 3:

                cout << "Retornando ao menu de listagem" << endl;
                system("pause");
                limpar_dados();
                break;

            // Se o usuário escolher uma opção inválida, exibe uma mensagem de erro
            default:
                cout << "Opção inválida!" << endl;
                system("pause");
                limpar_dados();
                break;
            }

            break;

        // Opção 2: Listar candidatos por partido
        // O usuário deve informar o nome do partido para listar os candidatos desse partido
        case 2:
            limpar_dados();

            cout << "╔═══════════════════════════════════════════════╗" << endl;
            cout << "║ Listar por partido                            ║" << endl;
            cout << "╚═══════════════════════════════════════════════╝" << endl;
            cout << "Digite o partido que deseja listar: " << std::flush;

            cin >> partido;

            if (std::cin.fail())
            {
                Logger::log("Entrada inválida no menu de listagem por partido.");
                std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                limpar_dados();
                return;
            }

            // Percorre a lista de candidatos e exibe os dados dos candidatos que pertencem ao partido informado
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
            return;
            break;

        // Opção 3: Listar todos os candidatos
        case 3:

            limpar_dados();

            cout << "Lista de todos os candidatos disponíveis. " << std::flush << endl;
            cout << "===========================================" << endl;
            cout << "| Presidentes                             |" << endl;
            cout << "=========================================== " << endl;

            // Percorre a lista de candidatos e exibe os dados dos candidatos que são presidentes
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

            // Percorre a lista de candidatos e exibe os dados dos candidatos que são governadores
            for (const auto &candidato : candidatos)
            {
                if (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador")
                {
                    candidato.mostrar_dados();
                    cout << endl;
                }
            }

            // Se não houver candidatos cadastrados, exibe uma mensagem informando que não há candidatos
            if (candidatos.empty())
            {
                cout << "Nenhum candidato cadastrado." << endl;
                return;
            }

            cout << endl;
            system("pause");
            limpar_dados();
            return;
            break;

        // Opção inválida
        default:

            cout << "Opção inválida" << endl;
            system("pause");
            limpar_dados();
            break;
        }
    }
}

/**
 * @brief Realiza o processo de votação.
 *
 * Esta função permite que o eleitor vote em um candidato específico, verificando se ele já votou para presidente ou governador.
 *
 * @param candidatos Vetor de candidatos disponíveis para votação.
 */

void Interface::votando()
{
    int numero_voto_presidente; // Variável para armazenar o número do candidato escolhido pelo eleitor

    vector<Candidato> candidatos = carregarCandidatos(); // Carrega os candidatos do arquivo JSON
    vector<Eleitor> eleitores = carregarEleitores();     // Carrega os eleitores do arquivo JSON

    Logger::log("Iniciando o processo de votação.");

    // Verifica se não há candidatos ou eleitores cadastrados
    // Se não houver candidatos, exibe uma mensagem informando que não há candidatos cadastrados
    if (candidatos.empty())
    {
        Logger::log("Nenhum candidato cadastrado.");
        cout << "Nenhum candidato cadastrado." << endl;
        system("pause");
        limpar_dados();
        return;
    }
    if (eleitores.empty())
    {
        Logger::log("Nenhum eleitor cadastrado.");
        cout << "Nenhum eleitor cadastrado." << endl;
        system("pause");
        return;
    }
    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Votação                                       ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl
         << endl;
    cout << "Digite o número do candidato para presidente: " << std::flush;

    Logger::log("Eleitor " + sessao_atual + " iniciou o processo de votação para presidente.");

    cin >> numero_voto_presidente;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida no processo de votação para presidente.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    // Verifica se o número do voto é válido
    // Percorre a lista de candidatos e verifica se o número do voto corresponde ao número de algum candidato
    if (numero_voto_presidente <= 0)
    {
        Logger::log("Número de voto inválido.");
        cout << "Número de voto inválido. Por favor, tente novamente." << endl;
        system("pause");
        limpar_dados();
        return;
    }

    for (auto &candidato : candidatos)
    {
        // Se o número do voto corresponde ao número do candidato, verifica se o eleitor já votou para presidente ou governador
        if (candidato.getNumero() == numero_voto_presidente && (candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente"))
        {
            // Verifica se o eleitor já votou para presidente
            // Se o eleitor já votou, exibe uma mensagem informando que ele já votou e retorna ao menu de votação
            for (auto &eleitor : eleitores)
            {
                if (eleitor.getNumEleitor() == sessao_atual)
                {
                    if ((candidato.getCargo() == "Presidente" || candidato.getCargo() == "presidente") && eleitor.getVotouPresidente() == true)
                    {
                        Logger::log("Eleitor " + sessao_atual + " já votou para presidente.");
                        cout << "Você já votou para presidente!" << endl;
                        system("pause");
                        limpar_dados();
                        continue;
                    }

                    candidato.mostrar_dados();
                    cout << endl;
                    cout << "Confirmar voto?" << endl;
                    cout << "1. Sim" << endl;
                    cout << "2. Não" << endl;

                    int confirmar_presidente;

                    cin >> confirmar_presidente;

                    if (std::cin.fail())
                    {
                        Logger::log("Entrada inválida no menu de confirmação de voto para presidente.");
                        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        limpar_dados();
                        return;
                    }

                    // Se o eleitor confirmar o voto, registra o voto do candidato e atualiza o status de votação do eleitor
                    if (confirmar_presidente == 1)
                    {

                        eleitor.setVotouPresidente(true);
                        salvarEleitores(eleitores);   // Salva as alterações no arquivo JSON de eleitores
                        candidato.registrar_voto();   // Registra o voto do candidato
                        salvarCandidatos(candidatos); // Salva as alterações no arquivo JSON de candidatos

                        Logger::log("Eleitor " + sessao_atual + " confirmou o voto para presidente.");
                        cout << "Voto registrado com sucesso!" << endl;
                        system("pause");
                        limpar_dados();
                    }

                    // Se o eleitor não confirmar o voto, exibe uma mensagem de cancelamento
                    else if (confirmar_presidente == 2)
                    {
                        Logger::log("Eleitor " + sessao_atual + " cancelou o voto para presidente.");
                        cout << "Voto cancelado." << endl;
                        cout << "Retornando ao menu de votação" << endl;
                        system("pause");
                        limpar_dados();
                    }
                    return;
                }
            }
        }
    }

    cout << "Digite o número de candidato para governador: ";

    Logger::log("Eleitor " + sessao_atual + " iniciou o processo de votação para governador.");

    int numero_voto_governador; // Variável para armazenar o número do candidato escolhido pelo eleitor para governador

    cin >> numero_voto_governador;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida no processo de votação para governador.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    // Verifica se o número do voto é válido
    if (numero_voto_governador <= 0)
    {
        Logger::log("Número de voto inválido.");
        cout << "Número de voto inválido. Por favor, tente novamente." << endl;
        system("pause");
        limpar_dados();
        return;
    }

    // Percorre a lista de candidatos e verifica se o número do voto corresponde ao número de algum candidato para governador
    for (auto &candidato : candidatos)
    {
        // Se o número do voto corresponde ao número do candidato, verifica se o eleitor já votou para governador
        if (candidato.getNumero() == numero_voto_governador && (candidato.getCargo() == "Governador" || candidato.getCargo() == "governador"))
        {
            for (auto &eleitor : eleitores)
            {
                if (eleitor.getNumEleitor() == sessao_atual)
                {
                    if ((candidato.getCargo() == "Governador" || candidato.getCargo() == "governador") && eleitor.getVotouGovernador() == true)
                    {
                        Logger::log("Eleitor " + sessao_atual + " já votou para governador.");

                        cout << "Você já votou para governador!" << endl;
                        system("pause");
                        limpar_dados();
                        break;
                    }

                    // Se o eleitor não votou para o cargo do candidato, exibe os dados do candidato e pergunta se o eleitor deseja confirmar o voto
                    candidato.mostrar_dados();
                    cout << endl;
                    cout << "Confirmar voto?" << endl;
                    cout << "1. Sim" << endl;
                    cout << "2. Não" << endl;

                    int confirmar_governador;

                    cin >> confirmar_governador;

                    if (std::cin.fail())
                    {
                        Logger::log("Entrada inválida no menu de confirmação de voto para governador.");
                        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        limpar_dados();
                        return;
                    }

                    // Se o eleitor confirmar o voto, registra o voto do candidato e atualiza os dados do eleitor
                    if (confirmar_governador == 1)
                    {
                        candidato.registrar_voto();       // Registra o voto do candidato
                        salvarCandidatos(candidatos);     // Salva as alterações no arquivo JSON de candidatos
                        eleitor.setVotouGovernador(true); // Atualiza o status de votação do eleitor para governador
                        salvarEleitores(eleitores);       // Salva as alterações no arquivo JSON de eleitores

                        Logger::log("Eleitor " + sessao_atual + " confirmou o voto para governador.");

                        cout << "Voto registrado com sucesso!" << endl;
                        system("pause");
                        limpar_dados();
                        return;
                    }
                    else
                    {
                        Logger::log("Eleitor " + sessao_atual + " cancelou o voto para governador.");
                        cout << "Voto não confirmado." << endl;
                        cout << "Retornando ao menu de votação" << endl;
                        system("pause");
                        limpar_dados();
                        return;
                    }

                    system("pause");
                    limpar_dados();
                    return;
                }
            }
        }
    }
}

/**
 * @brief Exibe os resultados da votação por cargo.
 *
 * Esta função exibe os resultados da votação para um cargo específico, mostrando os candidatos, seus votos e percentuais.
 * * A função também exibe o vencedor do cargo.
 *
 * @param cargo O cargo para o qual os resultados serão exibidos (ex: "Presidente", "Governador").
 * @param todos_candidatos Vetor de todos os candidatos cadastrados.
 */

void Interface::exibirResultadosPorCargo(const string &cargo, const vector<Candidato> &todos_candidatos) const
{
    cout << "\n\n--- VOTACAO POR CANDIDATO PARA " << cargo << " ---\n\n";

    vector<Candidato> candidatos_do_cargo; // Vetor para armazenar os candidatos do cargo específico

    // Filtra os candidatos do cargo específico
    // Percorre a lista de todos os candidatos e adiciona os candidatos do cargo especificado
    for (const auto &candidato : todos_candidatos)
    {
        if (candidato.getCargo() == cargo)
        {
            candidatos_do_cargo.push_back(candidato);
        }
    }

    // Se não houver candidatos para o cargo, exibe uma mensagem informando que não há candidatos
    if (candidatos_do_cargo.empty())
    {
        Logger::log("Nenhum candidato concorreu a este cargo: " + cargo);
        cout << "Nenhum candidato concorreu a este cargo." << endl;
        return;
    }

    int total_votos_cargo = 0;
    // Percorre a lista de candidatos do cargo e soma os votos de cada candidato
    for (const auto &candidato : candidatos_do_cargo)
    {
        total_votos_cargo += candidato.getVotos();
    }

    // Se não houver votos registrados para o cargo, exibe uma mensagem informando que não há votos
    if (total_votos_cargo == 0)
    {
        Logger::log("Nenhum voto registrado para o cargo: " + cargo);
        cout << "Nenhum voto registado para este cargo." << endl;
        return;
    }

    // Ordena os candidatos do cargo por número de votos em ordem decrescente
    sort(candidatos_do_cargo.begin(), candidatos_do_cargo.end(), [](const Candidato &a, const Candidato &b)
         { return a.getVotos() > b.getVotos(); });

    // Exibe o cabeçalho da tabela de resultados
    cout << left << setw(25) << "Candidato (Urna)"
         << setw(15) << "Partido"
         << setw(10) << "Votos"
         << "Percentual (%)" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << fixed << setprecision(2);

    Logger::log("Exibindo resultados para o cargo: " + cargo);

    // Percorre a lista de candidatos do cargo e exibe os dados de cada candidato
    // Calcula o percentual de votos de cada candidato e exibe uma barra gráfica representando o percentual
    for (const auto &candidato : candidatos_do_cargo)
    {
        double percentual = (static_cast<double>(candidato.getVotos()) / total_votos_cargo) * 100.0; // Calcula o percentual de votos
        int tam_barra = static_cast<int>(percentual / 5);                                            // Converte o percentual em comprimento da barra (5% por caractere)
        string barra_grafica(tam_barra, '#');                                                        // Cria a barra gráfica com o número de caracteres correspondente ao percentual

        // Exibe os dados do candidato, incluindo nome, partido, votos e percentual
        cout << left << setw(25) << candidato.getNomeUrna()
             << setw(15) << candidato.getPartido()
             << setw(10) << candidato.getVotos()
             << percentual << "%" << endl;
        cout << "[" << barra_grafica << "]" << endl;
    }

    // Exibe o resumo da votação para o cargo
    cout << "\n--- RESUMO DA VOTACAO PARA " << cargo << " ---\n";
    cout << "Total de Votos Apurados: " << total_votos_cargo << endl;
    cout << "-----------------------------------------" << endl;

    // Exibe o vencedor do cargo, que é o candidato com mais votos
    cout << "VENCEDOR(A): " << candidatos_do_cargo[0].getNomeUrna() //
         << " (" << candidatos_do_cargo[0].getPartido() << ")" << endl;
    cout << "-----------------------------------------" << endl;

    Logger::log("Resultados exibidos com sucesso para o cargo: " + cargo);
}

/**
 * @brief Exibe o resultado das eleições.
 *
 * Esta função exibe os resultados das eleições, incluindo a lista de candidatos, o total de votos e o vencedor.
 */

void Interface::resultado_eleicoes()
{
    // Carrega os dados apenas uma vez
    vector<Candidato> candidatos = carregarCandidatos();

    cout << "\n\n=========================================" << endl;
    cout << "      RESULTADO OFICIAL DAS ELEICOES" << endl;
    cout << "=========================================" << endl;

    Logger::log("Exibindo resultados das eleições.");

    // Verifica se não há candidatos cadastrados
    if (candidatos.empty())
    {
        Logger::log("Nenhum candidato cadastrado.");
        cout << "Nenhum candidato cadastrado." << endl;
        system("pause");
        limpar_dados();
        return;
    }

    exibirResultadosPorCargo("Presidente", candidatos); // Exibe os resultados para o cargo de Presidente
    exibirResultadosPorCargo("Governador", candidatos); // Exibe os resultados para o cargo de Governador

    system("pause");
    limpar_dados();
}

/**
 * @brief Cadastra um novo eleitor no sistema.
 *
 * Esta função solicita os dados do eleitor, verifica se o CPF já está cadastrado e, se não estiver, cria um novo objeto Eleitor e o adiciona à lista de eleitores.
 *
 * @param eleitores Vetor de eleitores cadastrados.
 */

void Interface::cadastrar_eleitor(vector<Eleitor> &eleitores)
{
    string nome, cpf, num_eleitor; // Variáveis para armazenar os dados do eleitor
    int idade;                     // Variável para armazenar a idade do eleitor

    Logger::log("Iniciando cadastro de eleitor.");

    cout << "╔═══════════════════════════════════════════════╗" << endl;
    cout << "║ Cadastro de Eleitor                           ║" << endl;
    cout << "╚═══════════════════════════════════════════════╝" << endl
         << endl;
    cout << "Digite seu nome: " << std::flush;
    getline(cin >> std::ws, nome);
    cout << "Digite seu CPF: " << std::flush;
    getline(cin >> std::ws, cpf);
    cout << "Digite sua idade: " << std::flush;

    cin >> idade;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida no cadastro de eleitor.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    // Verifica se o eleitor tem mais de 16 anos, pois é necessário ter pelo menos 16 anos para se cadastrar
    if (idade < 16)
    {
        cout << "Você deve ter pelo menos 16 anos para se cadastrar." << endl;
        Logger::log("Tentativa de cadastro de eleitor com idade menor que 16 anos: " + nome + " - CPF: " + cpf);
        system("pause");
        limpar_dados();
        return;
    }

    // Verifica se o CPF já está cadastrado
    for (const auto &eleitor_existente : eleitores)
    {
        if (eleitor_existente.getCpf() == cpf)
        {
            Logger::log("Tentativa de cadastro com CPF já existente: " + cpf);
            std::cout << "\n>>> ERRO: Este CPF já está cadastrado. <<<" << std::endl;
            cout << "Por favor, verifique os dados e tente novamente." << endl;
            system("pause");
            return;
        }
    }

    // Gera um número de título de eleitor único
    // O número é gerado através da função gerar_titulo() definida em json_utils.hpp
    num_eleitor = gerar_titulo();
    Eleitor e1(false, false, nome, cpf, idade, num_eleitor); // Cria um novo objeto Eleitor com os dados fornecidos
    eleitores.push_back(e1);                                 // Adiciona o novo eleitor ao vetor de eleitores
    salvarEleitores(eleitores);                              // Salva os eleitores no arquivo JSON

    Logger::log("Cadastro de eleitor realizado com sucesso: " + nome + " - CPF: " + cpf);

    limpar_dados();
    cout << "Cadastro realizado com sucesso!\n"
         << endl;
    cout << "Seu número de título de eleitor: " << num_eleitor << endl;
    cout << "\nAgora você pode votar!" << endl;
    system("pause");
    limpar_dados();
}

/**
 * @brief Autentica o administrador do sistema.
 *
 * Esta função solicita a senha do administrador e verifica se a autenticação é bem-sucedida.
 * Se a autenticação for bem-sucedida, chama o menu do administrador.
 */

void Interface::adm()
{
    Security security; // Cria um objeto Security para autenticação
    string senha;      // Variável para armazenar a senha do administrador

    Logger::log("Tentativa de autenticação do administrador.");

    cout << "Digite a senha do administrador: ";

    // Verifica se a senha é válida
    // A senha é definida na classe Security, que deve ser implementada em outro arquivo
    if (security.autenticate_admin())
    {
        limpar_dados();
        menu_admin();
    }
    else
    {
        cout << "Falha na autenticação do administrador." << endl;
        Logger::log("Falha na autenticação do administrador.");
        system("pause");
        limpar_dados();
        return;
    }
}

/**
 * @brief Exibe o menu do administrador.
 *
 * Esta função exibe o menu do administrador, permitindo que ele cadastre ou delete candidatos.
 * O menu continua ativo até que o administrador escolha sair.
 */

void Interface::menu_admin()
{
    vector<Candidato> candidatos = carregarCandidatos(); // Carrega os candidatos do arquivo JSON

    int adm_opcao; // Variável para armazenar a opção escolhida pelo administrador

    Logger::log("Menu do administrador iniciado.");

    while (1)
    {
        cout << "Bem-vindo ao menu do administrador!\n"
             << endl;
        cout << "Digite uma opção:\n"
             << endl;
        cout << "1. Cadastrar Candidato" << endl;
        cout << "2. Deletar Candidato" << endl;
        cout << "3. Sair" << endl;

        cin >> adm_opcao;

        if (std::cin.fail())
        {
            Logger::log("Entrada inválida no menu do administrador.");
            std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("pause");
            limpar_dados();
            continue;
        }

        switch (adm_opcao)
        {

        // Opção 1: Cadastrar Candidato
        case 1:
            limpar_dados();
            cadastrarCandidato(candidatos);
            break;

        // Opção 2: Deletar Candidato
        case 2:
            limpar_dados();
            deletarCandidato(candidatos);
            break;

        // Opção 3: Sair do menu do administrador
        case 3:
            Logger::log("Administrador saiu do menu.");

            limpar_dados();
            cout << "Retornando ao menu inicial..." << endl;
            system("pause");
            return;
            break;

        // Opção inválida
        default:
            limpar_dados();
            cout << "Opção inválida, digite novamente!" << endl;
            system("pause");
            break;
        }
    }
}

/**
 * @brief Lista os candidatos cadastrados.
 *
 * Esta função exibe uma lista formatada de todos os candidatos cadastrados no sistema.
 * Se não houver candidatos, exibe uma mensagem informando que não há candidatos cadastrados.
 *
 * @param candidatos Vetor de candidatos cadastrados.
 */

void Interface::listarCandidatos(const std::vector<Candidato> &candidatos) const
{
    std::cout << "\n--- Lista de Candidatos Cadastrados ---\n";

    // Verifica se a lista de candidatos está vazia
    if (candidatos.empty())
    {
        std::cout << "Nenhum candidato cadastrado no momento.\n";
        return;
    }

    // Exibe o cabeçalho da tabela de candidatos
    std::cout << std::left << std::setw(10) << "Número"
              << std::setw(30) << "Nome na Urna"
              << std::setw(20) << "Partido" << std::endl;
    std::cout << "------------------------------------------------------------\n";

    // Percorre a lista de candidatos e exibe os dados formatados
    for (const auto &candidato : candidatos)
    {
        std::cout << std::left << std::setw(10) << candidato.getNumero()
                  << std::setw(30) << candidato.getNomeUrna()
                  << std::setw(20) << candidato.getPartido() << std::endl;
    }
    std::cout << "------------------------------------------------------------\n";
}

/**
 * @brief Cadastra um novo candidato no sistema.
 *
 * Esta função solicita os dados do candidato, verifica se o número do candidato já está cadastrado e, se não estiver, cria um novo objeto Candidato e o adiciona à lista de candidatos.
 *
 * @param candidatos Vetor de candidatos cadastrados.
 */

void Interface::cadastrarCandidato(vector<Candidato> &candidatos)
{
    string nome, cpf, num_eleitor, nome_urna, partido, cargo; // Variáveis para armazenar os dados do candidato
    int idade, numero_candidato;                              // Variáveis para armazenar a idade e o número do candidato

    Logger::log("Iniciando cadastro de candidato.");

    cout << "Cadastrar Candidato" << endl;
    cout << "Digite o nome do candidato: ";
    getline(cin >> std::ws, nome);
    cout << "Digite o CPF do candidato: ";
    getline(cin >> std::ws, cpf);
    cout << "Digite a idade do candidato: ";
    cin >> idade;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida no cadastro de candidato.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    cout << "Digite o número de eleitor do candidato: ";
    getline(cin >> std::ws, num_eleitor);
    cout << "Digite o número do candidato: ";
    cin >> numero_candidato;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida no cadastro de candidato.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    cout << "Digite o nome de urna do candidato: ";
    getline(cin >> std::ws, nome_urna);
    cout << "Digite o partido do candidato: ";
    getline(cin >> std::ws, partido);
    cout << "Digite o cargo disputado pelo candidato: ";
    getline(cin >> std::ws, cargo);

    Candidato c1(nome, cpf, idade, num_eleitor, numero_candidato, nome_urna, partido, cargo); // Cria um novo objeto Candidato com os dados fornecidos
    candidatos.push_back(c1);                                                                 // Adiciona o novo candidato ao vetor de candidatos
    salvarCandidatos(candidatos);                                                             // Salva os candidatos no arquivo JSON

    Logger::log("Cadastro de candidato realizado com sucesso: " + nome + " - CPF: " + cpf + " - Número: " + std::to_string(numero_candidato));

    cout << "\nCandidato cadastrado com sucesso!" << endl;

    system("pause");
    limpar_dados();
}

/**
 * @brief Deleta um candidato do sistema.
 *
 * Esta função permite que o administrador delete um candidato específico, solicitando o número de eleitor do candidato a ser deletado.
 * Se o candidato for encontrado, ele é removido da lista e os dados são salvos no arquivo JSON.
 *
 * @param candidatos Vetor de candidatos cadastrados.
 */

void Interface::deletarCandidato(std::vector<Candidato> &candidatos)
{

    Logger::log("Iniciando processo de deleção de candidato.");

    // Verifica se a lista de candidatos está vazia
    if (candidatos.empty())
    {
        std::cout << "\nNão há candidatos para deletar." << std::endl;
        Logger::log("Tentativa de deleção de candidato sem candidatos cadastrados.");
        system("pause");
        limpar_dados();
        return;
    }

    listarCandidatos(candidatos); // Exibe a lista de candidatos cadastrados

    string numero_para_deletar; // Variável para armazenar o número do eleitor do candidato a ser deletado

    std::cout << "\nDigite o número de eleitor do candidato que deseja deletar: ";
    std::cin >> numero_para_deletar;

    // Verifica se a entrada do usuário é válida
    if (std::cin.fail())
    {
        Logger::log("Entrada inválida ao tentar deletar candidato.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    int index_encontrado = -1; // Variável para armazenar o índice do candidato encontrado

    // Percorre a lista de candidatos para encontrar o candidato com o número de eleitor fornecido
    for (long long unsigned int i = 0; i < candidatos.size(); ++i)
    {
        if (candidatos[i].getNumEleitor() == numero_para_deletar)
        {
            Logger::log("Candidato encontrado para deleção: " + candidatos[i].getNomeUrna() + " - Número: " + std::to_string(candidatos[i].getNumero()));
            index_encontrado = i; // Armazena o índice do candidato encontrado
            break;
        }
    }

    // Se o candidato não for encontrado, exibe uma mensagem informando que o candidato não foi encontrado
    if (index_encontrado == -1)
    {
        Logger::log("Candidato não encontrado para deleção: Número " + numero_para_deletar);
        std::cout << "\nCandidato com o número " << numero_para_deletar << " Não foi encontrado." << std::endl;
        system("pause");
        limpar_dados();
        return;
    }

    std::cout << "\nCandidato encontrado:" << std::endl;
    std::cout << "Nome na Urna: " << candidatos[index_encontrado].getNomeUrna() << std::endl;
    std::cout << "Partido: " << candidatos[index_encontrado].getPartido() << std::endl;

    char confirmacao; // Variável para armazenar a confirmação do usuário

    std::cout << "\nTem certeza que deseja deletar este candidato? [S/N]: ";
    std::cin >> confirmacao;

    if (std::cin.fail())
    {
        Logger::log("Entrada inválida ao tentar deletar candidato.");
        std::cout << "Entrada inválida. Operacão cancelada." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        limpar_dados();
        return;
    }

    // Verifica se a entrada do usuário é válida
    if (confirmacao == 'S' || confirmacao == 's')
    {

        candidatos.erase(candidatos.begin() + index_encontrado); // Remove o candidato encontrado da lista

        salvarCandidatos(candidatos); // Salva as alterações no arquivo JSON de candidatos

        std::cout << "\nCandidato deletado com sucesso!" << std::endl;

        Logger::log("Candidato deletado com sucesso: " + candidatos[index_encontrado].getNomeUrna() + " - Número: " + std::to_string(candidatos[index_encontrado].getNumero()));

        system("pause");
        limpar_dados();
        return;
    }

    // Se o usuário não confirmar a exclusão, exibe uma mensagem de cancelamento
    else
    {
        std::cout << "\nOperação cancelada pelo utilizador." << std::endl;

        Logger::log("Operação de deleção de candidato cancelada pelo usuário.");

        system("pause");
        limpar_dados();
        return;
    }
}