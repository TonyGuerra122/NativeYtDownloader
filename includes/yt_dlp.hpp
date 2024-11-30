#pragma once

#include "../includes/os.hpp"
#include "../includes/process_builder.hpp"

class YtDLP
{
private:
    Os os;
    static bool isYtDlpPresent();

public:
    explicit YtDLP(Os os);
    void checkAndInstallYtDLP();
};