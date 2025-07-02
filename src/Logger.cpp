#include "Logger.hpp"
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

/**
 * @brief Registra uma mensagem no arquivo de log com data e hora.
 * 
 * @param mensagem A mensagem a ser registrada no log.
 * 
 * Esta função abre o arquivo "auditoria.log" em modo de anexação, escreve a mensagem com a data e hora atuais, e fecha o arquivo.
 * Se o arquivo não puder ser aberto, uma mensagem de erro é exibida no console.
 * A data e hora são formatadas no padrão "YYYY-MM-DD HH:MM:SS".
 * Se a conversão de tempo falhar, uma mensagem de data inválida é registrada.
 */

void Logger::log(const std::string &mensagem)
{
    std::ofstream arquivo_log("auditoria.log", std::ios::app);

    if (!arquivo_log.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de log." << std::endl;
        return;
    }

    auto agora = std::chrono::system_clock::now();
    std::time_t horario_atual = std::chrono::system_clock::to_time_t(agora);
    tm* tempo_local = localtime(&horario_atual);

    if (tempo_local != nullptr)
    {
        arquivo_log << "[" << std::put_time(tempo_local, "%Y-%m-%d %H:%M:%S") << "] " << mensagem << std::endl;
    }
    else
    {
        arquivo_log << "[data invalida] " << mensagem << std::endl;
    }

    arquivo_log.close();
}