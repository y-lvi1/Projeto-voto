#ifndef JSON_UTILS_HPP
#define JSON_UTILS_HPP

#include "Eleitor.hpp"
#include "Candidato.hpp"
#include "json.hpp"
#include <fstream>
#include <vector>
#include <cstdlib>

using json = nlohmann::json;

void to_json(json &j, const Eleitor &e);
void from_json(const json &j, Eleitor &e);

void to_json(json &j, const Candidato &c);
void from_json(const json &j, Candidato &c);

void salvarEleitores(const std::vector<Eleitor> &eleitores);
std::vector<Eleitor> carregarEleitores();

std::string gerar_titulo();

void salvarCandidatos(const std::vector<Candidato> &candidatos);
std::vector<Candidato> carregarCandidatos();

#endif