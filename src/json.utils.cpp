#include "json_utils.hpp"

void to_json(json& j, const Eleitor& e) {
    j = json{
        {"nome", e.getNome()},
        {"cpf", e.getCpf()},
        {"idade", e.getIdade()},
        {"num_eleitor", e.getNumEleitor()},
        {"votou_presidente", e.getVotouPresidente()},
        {"votou_governador", e.getVotouGovernador()}
    };
}

void from_json(const json& j, Eleitor& e) {
    std::string nome = j.at("nome").get<std::string>();
    std::string cpf = j.at("cpf").get<std::string>();
    int idade = j.at("idade").get<int>();
    std::string num_eleitor = j.at("num_eleitor").get<std::string>();
    bool votouPresidente = j.at("votou_presidente").get<bool>();
    bool votouGovernador = j.at("votou_governador").get<bool>();
    e = Eleitor(votouPresidente, votouGovernador, nome, cpf, idade, num_eleitor);
}

void to_json(json& j, const Candidato& c) {
    j = json{
        {"nome", c.getNome()},
        {"cpf", c.getCpf()},
        {"idade", c.getIdade()},
        {"num_eleitor", c.getNumEleitor()},
        {"numero", c.getNumero()},
        {"nome_urna", c.getNomeUrna()},
        {"partido", c.getPartido()},
        {"cargo", c.getCargo()},
        {"votos", c.getVotos()}
    };
}

void from_json(const json& j, Candidato& c) {
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

void salvarEleitores(const std::vector<Eleitor>& eleitores) {
    json j_array = eleitores;
    std::ofstream arquivo("eleitores.json");
    arquivo << j_array.dump(4);
}

std::vector<Eleitor> carregarEleitores() {
    std::ifstream arquivo("eleitores.json");
    if (!arquivo.is_open()) return {};
    json j;
    arquivo >> j;
    if (j.empty() || !j.is_array()) return {};
    return j.get<std::vector<Eleitor>>();
}

std::string gerar_titulo() {
    std::string num = "";
    num += std::to_string(rand() % 9 + 1);
    for (int i = 1; i < 12; ++i) {
        num += std::to_string(rand() % 10);
    }
    return num;
}

void salvarCandidatos(const std::vector<Candidato>& candidatos) {
    json j_array = candidatos;
    std::ofstream arquivo("candidatos.json");
    arquivo << j_array.dump(4);
}

std::vector<Candidato> carregarCandidatos() {
    std::ifstream arquivo("candidatos.json");
    if (!arquivo.is_open()) return {};
    json j;
    arquivo >> j;
    if (j.empty() || !j.is_array()) return {};
    return j.get<std::vector<Candidato>>();
}