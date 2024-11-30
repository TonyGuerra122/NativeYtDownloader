#include "../includes/process_builder.hpp"

void ProcessBuilder::startAndAwaitProcess(const std::string &command, Callback onProcessExit)
{
    namespace bp = boost::process;

    try
    {
        bp::ipstream pipeStream;
        bp::child process(command, bp::std_out > pipeStream);

        std::string output;
        std::string line;

        while (std::getline(pipeStream, line))
        {
            output += line + "\n";
        }

        process.wait();
        int exitCode = process.exit_code();
        bool success = exitCode == 0;

        if (onProcessExit)
        {
            onProcessExit(exitCode, output, success);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao executar o processo: " << e.what() << std::endl;
        if (onProcessExit)
        {
            onProcessExit(-1, e.what(), false);
        }
    }
}
