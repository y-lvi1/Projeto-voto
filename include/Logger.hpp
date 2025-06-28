#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

// Utilizando namespace pois não há necessidade de ficar instanciando objetos dessa classe

namespace Logger
{

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

    void log(const std::string &mensagem);
}

#endif // LOGGER_HPP