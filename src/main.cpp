#include "../includes/initialize.hpp"

int main()
{
    Initialize init;

    init.start();

    std::cout << "Pressione Enter para continuar...";
    std::cin.get();

    return 0;
}