#include "../includes/yt_dlp.hpp"

YtDLP::YtDLP(Os os)
    : os(os) {}

bool YtDLP::isYtDlpPresent()
{
    bool success = false;

    try
    {
        // Chama o ProcessBuilder para executar o comando e capturar a saída
        ProcessBuilder::startAndAwaitProcess("yt-dlp --version", [&success](int exitCode, const std::string &result, bool isSuccess)
                                             {
            if (isSuccess)
            {
                std::cout << "Processo concluído com sucesso! Saída:\n" << result << std::endl;
                success = true;
            }
            else
            {
                std::cerr << "Erro ao executar o processo. Código de saída: " << exitCode
                        << "\nErro: " << result << std::endl;
                success = false;
            } });
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao verificar o yt-dlp: " << e.what() << std::endl;
        success = false;
    }

    return success;
}

void YtDLP::checkAndInstallYtDLP()
{
    if (isYtDlpPresent())
    {
        return;
    }

    std::string command;

    if (os == Os::LINUX)
    {
        command = "curl -L https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp -o /usr/local/bin/yt-dlp && chmod a+rx /usr/local/bin/yt-dlp";
    }
    else
    {
        command = "curl -L https://github.com/yt-dlp/yt-dlp/releases/latest/download/yt-dlp.exe -o yt-dlp.exe";
    }

    std::cout << "Iniciando a instalação do yt-dlp" << std::endl;

    bool success = false;

    try
    {
        ProcessBuilder::startAndAwaitProcess(command, [&success](int exitCode, const std::string &result, bool isSuccess)
                                             {
            if (isSuccess)
                {
                    std::cout << "Processo concluído com sucesso! Saída:\n" << result << std::endl;
                    success = true;
                }
                else
                {
                    std::cerr << "Erro ao executar o processo. Código de saída: " << exitCode
                            << "\nErro: " << result << std::endl;
                    success = false;
                } });
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao instalar o yt-dlp: " << e.what() << std::endl;
        success = false;
    }
}