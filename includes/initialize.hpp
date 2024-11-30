#pragma once

#include "../includes/yt_dlp.hpp"
#include <windows.h>
#include <iostream>


class Initialize
{
public:
    Initialize();
    void start();
private:
    Os os;
    YtDLP ytDlp;
    void configureLang();
};