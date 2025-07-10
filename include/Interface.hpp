#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <vector>
#include "Eleitor.hpp"
#include "Candidato.hpp"

/**
 * @file Interface.hpp
 * @brief Declaração da classe Interface.
 *
 * Esta classe representa a interface do usuário para o sistema de votação, permitindo que eleitores votem, visualizem resultados e administradores gerenciem candidatos.
 * Contém métodos para exibir menus, cadastrar eleitores e candidatos, realizar votações e exibir resultados das eleições.
 */

/***** Esta classe em breve será desmembrada em várias classes menores para melhor organização e manutenção do código.*****/

class Interface
{
private:
public:
    void votando_presidente();                                                                                     // Inicia o processo de votação para presidente
    void votando_governador();                                                                                     // Inicia o processo de votação para governador
    void mostrar_candidatos(const std::vector<Candidato> &candidatos);                                             // Exibe a lista de candidatos disponíveis para votação
    void dados_logados(const std::vector<Eleitor> &eleitores, const std::string &sessao_atual);                    // Exibe os dados do eleitor logado
    void voto();                                                                                                   // Inicia o processo de votação, permitindo que o eleitor vote, visualize a lista de candidatos ou saia do sistema
    void limpar_dados();                                                                                           // Limpa os dados da tela
    void inicial();                                                                                                // Exibe o menu inicial do sistema de votação, permitindo que o usuário escolha entre cadastrar um eleitor, fazer login, ver resultados das eleições ou entrar como administrador
    bool logar(std::vector<Eleitor> &eleitores);                                                                   // Realiza o login do eleitor, verificando se o nome e CPF correspondem a algum eleitor cadastrado
    void cadastrar_eleitor(std::vector<Eleitor> &eleitores);                                                       // Cadastra um novo eleitor, solicitando nome, CPF, idade e número do título de eleitor
    void exibirResultadosPorCargo(const std::string &cargo, const std::vector<Candidato> &todos_candidatos) const; // Exibe os resultados dos candidatos por cargo, mostrando o nome, partido, número e votos recebidos
    void resultado_eleicoes();                                                                                     // Exibe os resultados das eleições, incluindo a lista de candidatos, o total de votos e o vencedor
    void adm();                                                                                                    // Exibe o menu de administração, permitindo que o administrador gerencie candidatos
    void menu_admin();                                                                                             // Exibe o menu de administração, permitindo que o administrador escolha entre listar, cadastrar ou deletar candidatos
    void listarCandidatos(const std::vector<Candidato> &candidatos) const;                                         // Lista todos os candidatos cadastrados, mostrando seus dados
    void cadastrarCandidato(std::vector<Candidato> &candidatos);                                                   // Cadastra um novo candidato, solicitando nome, CPF, idade, número do título de eleitor, número do candidato, nome de urna, partido e cargo disputado
    void deletarCandidato(std::vector<Candidato> &candidatos);                                                     // Deleta um candidato, solicitando o número do candidato a ser removido e removendo-o da lista de candidatos
};

#endif // INTERFACE_HPP