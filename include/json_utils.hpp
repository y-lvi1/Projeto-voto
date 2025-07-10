#ifndef JSON_UTILS_HPP
#define JSON_UTILS_HPP

#include "Eleitor.hpp"
#include "Candidato.hpp"
#include "json.hpp"
#include <fstream>
#include <vector>
#include <cstdlib>

using json = nlohmann::json; // Alias para o tipo json da biblioteca nlohmann::json

/**
 * @brief Ensina a serializar e desserializar objetos do tipo Eleitor e Candidato usando a biblioteca nlohmann::json.
 *
 * @param j O objeto JSON onde os dados serão armazenados ou lidos.
 * @param e O objeto Eleitor que será convertido para JSON ou preenchido a partir de
 *
 * Esta função define como os objetos Eleitor e Candidato serão convertidos para JSON.
 */

void to_json(json &j, const Eleitor &e);

/**
 * @brief Desserializa um objeto Eleitor a partir de um JSON.
 *
 * @param j O objeto JSON que contém os dados do Eleitor.
 * @param e O objeto Eleitor que será preenchido com os dados do JSON.
 *
 * Esta função define como os objetos Eleitor serão lidos a partir de um JSON.
 */

void from_json(const json &j, Eleitor &e);

/**
 * @brief Ensina a serializar e desserializar objetos do tipo Candidato usando a biblioteca nlohmann::json.
 *
 * @param j O objeto JSON onde os dados serão armazenados ou lidos.
 * @param c O objeto Candidato que será convertido para JSON ou preenchido a partir de
 *
 * Esta função define como os objetos Candidato serão convertidos para JSON.
 */

void to_json(json &j, const Candidato &c);

/**
 * @brief Desserializa um objeto Candidato a partir de um JSON.
 *
 * @param j O objeto JSON que contém os dados do Candidato.
 * @param c O objeto Candidato que será preenchido com os dados do JSON.
 *
 * Esta função define como os objetos Candidato serão lidos a partir de um JSON.
 */

void from_json(const json &j, Candidato &c);

/**
 * @brief Salva uma lista de eleitores em um arquivo JSON.
 *
 * @param eleitores A lista de eleitores a ser salva.
 *
 * Esta função converte a lista de eleitores para JSON e salva em um arquivo chamado "eleitores.json".
 */

void salvarEleitores(const std::vector<Eleitor> &eleitores);

/**
 * @brief Carrega uma lista de eleitores de um arquivo JSON.
 *
 * @return std::vector<Eleitor> A lista de eleitores carregada do arquivo.
 *
 * Esta função lê o arquivo "eleitores.json" e converte o conteúdo para uma lista de objetos Eleitor.
 * Se o arquivo não existir ou estiver vazio, retorna uma lista vazia.
 */

std::vector<Eleitor> carregarEleitores();

/**
 * @brief Gera um título de eleitor aleatório.
 *
 * @return std::string Um número de título de eleitor formatado como string.
 *
 * Esta função gera um número de título de eleitor com 12 dígitos, começando com um dígito não zero.
 */

std::string gerar_titulo();

/**
 * @brief Salva uma lista de candidatos em um arquivo JSON.
 *
 * @param candidatos A lista de candidatos a ser salva.
 *
 * Esta função converte a lista de candidatos para JSON e salva em um arquivo chamado "candidatos.json".
 */

void salvarCandidatos(const std::vector<Candidato> &candidatos);

/**
 * @brief Carrega uma lista de candidatos de um arquivo JSON.
 *
 * @return std::vector<Candidato> A lista de candidatos carregada do arquivo.
 *
 * Esta função lê o arquivo "candidatos.json" e converte o conteúdo para uma lista de objetos Candidato.
 * Se o arquivo não existir ou estiver vazio, retorna uma lista vazia.
 */

std::vector<Candidato> carregarCandidatos();

#endif