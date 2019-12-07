
#include "../headers/inputOutput.hpp"

#include <iostream>
using namespace std;
using namespace inputOutput;
using namespace H5;


InputOutput::InputOutput(){

}

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


Arguments* CreateErrorArgument(){
    Arguments arg;
    Arguments * parg;
    parg = &arg;
    parg->isOk = false;
    parg->errorMessage = "Error en argumentos";
    return parg;
}

Arguments* InputOutput::ProcessArguments(int argc, char* argv[]){


    std::cout << argv[0];
    std::cout << argv[1];
    std::cout << argv[2];

    if (!VerifyArguments(argc,argv)){
        return CreateErrorArgument();
    }

    // Arguments arg;
    Arguments * parg = new Arguments();
    // parg = &arg;
    parg->multiThreading = argv[1] == "true";
    parg->compressionLevel = atoi(argv[2]);
    parg->isOk = true;
    H5File file(argv[0], H5F_ACC_SWMR_WRITE);
    parg->file = file;
    std::cout << parg->multiThreading;
    std::cout << parg->compressionLevel;
    std::cout << parg->isOk;
    return parg;
}