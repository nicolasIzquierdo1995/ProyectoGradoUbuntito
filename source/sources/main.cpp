#include "../../HDF5-1.10.5-Linux/HDF_Group/HDF5/1.10.5/include/hdf5.h"
#include "../headers/inputOutput.hpp"
#include <iostream>
using namespace std;
using namespace inputOutput;

int main (int argc, char* argv[])
{
    InputOutput* io = new InputOutput();
    Arguments* args = io->ProcessArguments(argc, argv);

    std::cout << args->compressionLevel;
    //std::cout << args->multiThreading;
    //std::cout << args->isOk;
    //td::cout << args.file.getFileName();
    return 0;
}

