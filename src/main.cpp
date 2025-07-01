#include "Security.hpp"
#include "json_utils.hpp"
#include <ctime>
#include <iostream>

int main()
{
    /*srand(time(0));
    std::vector<Eleitor> lista;
    Eleitor e1(false, "yuri", "12345678900", 20, gerar_titulo());
    // Voto, nome, cpf, idade, titulo de eleitor
    lista.push_back(e1);
    salvarEleitores(lista);

    auto carregados = carregarEleitores();
    for (const auto& e : carregados) {
        std::cout << "Nome: " << e.getNome() << ", CPF: " << e.getCpf() << ", Idade: " << e.getIdade()
        << ", Num Eleitor: " << e.getNumEleitor()<< ", Já votou: " << (e.jaVotou() ? "Sim" : "Não") << "\n";
    }

    Candidato c1("bosonaro", "98765432100", 45, gerar_titulo(), 22, "Bolsonabo", "PSL", "Presidento");

    // Nome, cpf, idade, titulo de eleitor, numero, nome na urna, partido, cargo

    c1.registrar_voto();
    c1.mostrar_dados();*/
    

    //*EXEMPLO DE USO DA CLASSE SECURITY*//
    
    /*
    Security security;
    while (1)
    {
        if (security.autenticate_admin())
        {
            std::cout << "Acesso concedido." << std::endl;
        }
        else
        {
            std::cout << "Acesso negado." << std::endl;
        }
    }
    return 0;
    */
}
