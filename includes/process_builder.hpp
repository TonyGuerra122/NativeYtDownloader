#pragma once

#include <boost/process.hpp>
#include <functional>
#include <string>
#include <iostream>
#include "../includes/os.hpp"

/**
 * Classe para construir e gerenciar processos.
 */
class ProcessBuilder
{
public:
    /**
     * Tipo de callback para lidar com o resultado do processo.
     * @param exitCode Código de saída do processo.
     * @param output Saída padrão capturada do processo.
     * @param success Indica se o processo foi concluído com sucesso.
     */
    using Callback = std::function<void(int, const std::string &, bool)>;

    /**
     * Inicia um processo e aguarda sua conclusão.
     * @param command Comando a ser executado.
     * @param onProcessExit Callback a ser executado após a conclusão do processo.
     */
    static void startAndAwaitProcess(const std::string &command, Callback onProcessExit);
};
