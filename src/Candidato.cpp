#include "Candidato.hpp"

// Construtor default (requisito da biblioteca json)
Candidato::Candidato() = default;

// Construtor com parâmetros
//  Inicializa os atributos do candidato, incluindo o número de votos como 0
Candidato::Candidato(std::string nome, std::string cpf, int idade, std::string num_eleitor,
                     int numero, std::string nome_urna, std::string partido, std::string cargo)
    : Cadastro(nome, cpf, idade, num_eleitor), numero_candidato(numero),
      nome_urna(nome_urna), partido(partido), cargo_disputado(cargo), votos(0) {}

std::string Candidato::getNomeUrna() const { return nome_urna; }    // Getter para o nome de urna
std::string Candidato::getPartido() const { return partido; }       // Getter para o partido
std::string Candidato::getCargo() const { return cargo_disputado; } // Getter para o cargo disputado
int Candidato::getNumero() const { return numero_candidato; }       // Getter para o número do candidato
int Candidato::getVotos() const { return votos; }                   // Getter para o número de votos

void Candidato::setNome(const std::string nome) { this->nome = nome; }               // Setter para o nome
void Candidato::setNumero(int numero) { this->numero_candidato = numero; }           // Setter para o número do candidato
void Candidato::setPartido(const std::string partido) { this->partido = partido; }   // Setter para o partido
void Candidato::setCargo(const std::string cargo) { this->cargo_disputado = cargo; } // Setter para o cargo disputado
void Candidato::setVotos(int votos) { this->votos = votos; }                         // Setter para o número de votos

void Candidato::registrar_voto() { votos++; } // Incrementa o número de votos do candidato

/**
 * @brief Exibe os dados do candidato formatados.
 *
 * Mostra o nome de urna, partido, número do candidato e cargo disputado.
 * Utiliza uma tabela formatada para melhor visualização.
 */

void Candidato::mostrar_dados() const
{
  std::cout << "╔═══════════════════════════════════════════════╗\n"
            << "║ Dados do Candidato                            ║\n"
            << "╚═══════════════════════════════════════════════╝\n"
            << "Nome: " << nome_urna << "\n"
            << "Partido: " << partido << "\n"
            << "Numero: " << numero_candidato << "\n"
            << "Cargo: " << cargo_disputado << "\n"
            << "________________________________________________\n";
}
