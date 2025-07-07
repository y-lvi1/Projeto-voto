#include "Security.hpp"
#include <iostream>
#include "interface.hpp"
#include <ctime>

// Escolher o console para UTF-8 no Windows
// Isso é necessário para garantir que os caracteres especiais sejam exibidos corretamente
#ifdef _WIN32
#include <windows.h>
#endif

// Função principal do programa
// Inicializa a interface e chama o método inicial
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    srand(time(nullptr)); // Semente para números aleatórios, garantindo que cada execução gere resultados diferentes

    Interface i; // Cria uma instância da classe Interface
    i.inicial(); // Chama o método inicial da interface, que exibe o menu principal

    return 0; // Apenas para evitar warning de retorno
}
