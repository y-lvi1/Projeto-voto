#include "Candidato.hpp"
Candidato::Candidato() = default;

Candidato::Candidato(std::string nome, std::string cpf, int idade, std::string num_eleitor,
                     int numero, std::string nome_urna, std::string partido, std::string cargo)
    : Cadastro(nome, cpf, idade, num_eleitor), numero_candidato(numero),
      nome_urna(nome_urna), partido(partido), cargo_disputado(cargo), votos(0) {}

std::string Candidato::getNomeUrna() const { return nome_urna; }
std::string Candidato::getPartido() const { return partido; }
std::string Candidato::getCargo() const { return cargo_disputado; }
int Candidato::getNumero() const { return numero_candidato; }
int Candidato::getVotos() const { return votos; }

void Candidato::setNome(const std::string nome) { this->nome = nome; }
void Candidato::setNumero(int numero) { this->numero_candidato = numero; }
void Candidato::setPartido(const std::string partido) { this->partido = partido; }
void Candidato::setCargo(const std::string cargo) { this->cargo_disputado = cargo; }
void Candidato::setVotos(int votos){this->votos = votos;}

void Candidato::registrar_voto() { votos++; }

void Candidato::mostrar_dados() const {
    std::cout << "Nome de urna: " << nome_urna << "\n"
              << "Partido: " << partido << "\n"
              << "Cargo: " << cargo_disputado << "\n"
              << "Número: " << numero_candidato << "\n";
}
