#include "json_utils.hpp"

/**
 * @brief Ensina a serializar e desserializar objetos do tipo Eleitor e Candidato usando a biblioteca nlohmann::json.
 *
 * @param j O objeto JSON onde os dados serão armazenados ou lidos.
 * @param e O objeto Eleitor que será convertido para JSON ou preenchido a partir de
 *
 * Esta função define como os objetos Eleitor e Candidato serão convertidos para JSON.
 */

void to_json(json &j, const Eleitor &e)
{
    j = json{
        {"nome", e.getNome()},
        {"cpf", e.getCpf()},
        {"idade", e.getIdade()},
        {"num_eleitor", e.getNumEleitor()},
        {"votou_presidente", e.getVotouPresidente()},
        {"votou_governador", e.getVotouGovernador()}};
}

/**
 * @brief Desserializa um objeto Eleitor a partir de um JSON.
 *
 * @param j O objeto JSON que contém os dados do Eleitor.
 * @param e O objeto Eleitor que será preenchido com os dados do JSON.
 *
 * Esta função define como os objetos Eleitor serão lidos a partir de um JSON.
 */

void from_json(const json &j, Eleitor &e)
{
    std::string nome = j.at("nome").get<std::string>();
    std::string cpf = j.at("cpf").get<std::string>();
    int idade = j.at("idade").get<int>();
    std::string num_eleitor = j.at("num_eleitor").get<std::string>();
    bool votouPresidente = j.value("votou_presidente", false);
    bool votouGovernador = j.value("votou_governador", false);
    e = Eleitor(votouPresidente, votouGovernador, nome, cpf, idade, num_eleitor);
}

/**
 * @brief Ensina a serializar e desserializar objetos do tipo Candidato usando a biblioteca nlohmann::json.
 *
 * @param j O objeto JSON onde os dados serão armazenados ou lidos.
 * @param c O objeto Candidato que será convertido para JSON ou preenchido a partir de
 *
 * Esta função define como os objetos Candidato serão convertidos para JSON.
 */

void to_json(json &j, const Candidato &c)
{
    j = json{
        {"nome", c.getNome()},
        {"cpf", c.getCpf()},
        {"idade", c.getIdade()},
        {"num_eleitor", c.getNumEleitor()},
        {"numero", c.getNumero()},
        {"nome_urna", c.getNomeUrna()},
        {"partido", c.getPartido()},
        {"cargo", c.getCargo()},
        {"votos", c.getVotos()}};
}

/**
 * @brief Desserializa um objeto Candidato a partir de um JSON.
 *
 * @param j O objeto JSON que contém os dados do Candidato.
 * @param c O objeto Candidato que será preenchido com os dados do JSON.
 *
 * Esta função define como os objetos Candidato serão lidos a partir de um JSON.
 */

void from_json(const json &j, Candidato &c)
{
    std::string nome = j.at("nome").get<std::string>();
    std::string cpf = j.at("cpf").get<std::string>();
    int idade = j.at("idade").get<int>();
    std::string num_eleitor = j.at("num_eleitor").get<std::string>();
    int numero = j.at("numero").get<int>();
    std::string nome_urna = j.at("nome_urna").get<std::string>();
    std::string partido = j.at("partido").get<std::string>();
    std::string cargo = j.at("cargo").get<std::string>();
    int votos = j.at("votos").get<int>();

    c = Candidato(nome, cpf, idade, num_eleitor, numero, nome_urna, partido, cargo);
    c.setVotos(votos);
}

/**
 * @brief Salva uma lista de eleitores em um arquivo JSON.
 *
 * @param eleitores A lista de eleitores a ser salva.
 *
 * Esta função converte a lista de eleitores para JSON e salva em um arquivo chamado "eleitores.json".
 */

void salvarEleitores(const std::vector<Eleitor> &eleitores)
{
    json j_array = eleitores;
    std::ofstream arquivo("eleitores.json");
    arquivo << j_array.dump(4); // Formata o JSON com 4 espaços de indentação
}

/**
 * @brief Carrega uma lista de eleitores de um arquivo JSON.
 *
 * @return std::vector<Eleitor> A lista de eleitores carregada do arquivo.
 *
 * Esta função lê o arquivo "eleitores.json" e converte o conteúdo para uma lista de objetos Eleitor.
 * Se o arquivo não existir ou estiver vazio, retorna uma lista vazia.
 */

std::vector<Eleitor> carregarEleitores()
{
    std::ifstream arquivo("eleitores.json");
    if (!arquivo.is_open())
        return {};
    json j;
    arquivo >> j;
    if (j.empty() || !j.is_array())
        return {};
    return j.get<std::vector<Eleitor>>();
}

/**
 * @brief Gera um título de eleitor aleatório.
 *
 * @return std::string Um número de título de eleitor formatado como string.
 *
 * Esta função gera um número de título de eleitor com 12 dígitos, começando com um dígito não zero.
 */

std::string gerar_titulo()
{
    std::string num = "";
    num += std::to_string(rand() % 9 + 1);
    for (int i = 1; i < 12; ++i)
    {
        num += std::to_string(rand() % 10);
    }
    return num;
}

/**
 * @brief Salva uma lista de candidatos em um arquivo JSON.
 *
 * @param candidatos A lista de candidatos a ser salva.
 *
 * Esta função converte a lista de candidatos para JSON e salva em um arquivo chamado "candidatos.json".
 */

void salvarCandidatos(const std::vector<Candidato> &candidatos)
{
    json j_array = candidatos;
    std::ofstream arquivo("candidatos.json");
    arquivo << j_array.dump(4);
}

/**
 * @brief Carrega uma lista de candidatos de um arquivo JSON.
 *
 * @return std::vector<Candidato> A lista de candidatos carregada do arquivo.
 *
 * Esta função lê o arquivo "candidatos.json" e converte o conteúdo para uma lista de objetos Candidato.
 * Se o arquivo não existir ou estiver vazio, retorna uma lista vazia.
 */

std::vector<Candidato> carregarCandidatos()
{
    std::ifstream arquivo("candidatos.json");
    if (!arquivo.is_open())
        return {};
    json j;
    arquivo >> j;
    if (j.empty() || !j.is_array())
        return {};
    return j.get<std::vector<Candidato>>();
}