#include "../includes/initialize.hpp"

Initialize::Initialize()
    : ytDlp(this->os)
{
#ifdef _WIN64
    this->os = Os::WINDOWS;
#elif _WIN32
    this->os = Os::WINDOWS;
#elif __linux__
    this->os = Os::LINUX;
#else
    throw std::runtime_error("Sistema operacional não suportado.");
#endif
}

void Initialize::start()
{
    configureLang();

    this->ytDlp.checkAndInstallYtDLP();

    std::cout << "Inicializando o App..." << std::endl;
}

void Initialize::configureLang()
{
    if (this->os == Os::LINUX)
    {
        if (setlocale(LC_ALL, "pt_BR.UTF-8") == nullptr)
        {
            std::cerr << "Falha ao configurar o idioma no Linux." << std::endl;
        }
        else
        {
            std::cout << "Idioma configurado para Português (Brasil) no Linux." << std::endl;
        }
    }
    else if (this->os == Os::WINDOWS)
    {
        SetConsoleOutputCP(CP_UTF8);
    }
    else
    {
        std::cerr << "Sistema operacional não suportado para configuração de idioma." << std::endl;
    }
}