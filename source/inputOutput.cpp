
#include "inputOutput.hpp"
//#include "/home/osboxes/Desktop/myhdfstuff/HDF5-1.10.5-Linux/HDF_Group/HDF5/1.10.5/include/hdf5.h"

using namespace inputOutput;
using namespace H5;

bool VerifyArguments(int argc, char *argv[]){
    if (argc != 2){
      return false;
    }
    const char* multiThreading = argv[1];
    const char* compressionLevel = argv[2];

    if (multiThreading != "true" && multiThreading != "false") {
      return false;
    }

    if (compressionLevel != "1" && compressionLevel != "2"){
      return false;
    }

    return true;
}


Arguments CreateErrorArgument(){
    Arguments arg;
    Arguments * parg;
    parg = &arg;
    parg->isOk = false;
    parg->errorMessage = "Error en argumentos";
    return arg;
}

Arguments ProcessArguments(int argc, char *argv[]){
    if (!VerifyArguments(argc,argv)){
        return CreateErrorArgument();
    }

    Arguments arg;
    Arguments * parg;
    parg = &arg;
    parg->multiThreading = argv[1] == "true";
    parg->errorMessage = (int)argv[2];
    //H5::H5File hola;
    

    return arg;
}