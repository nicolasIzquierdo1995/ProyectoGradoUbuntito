
#include "../headers/utils.hpp"

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
using namespace utils;
using namespace H5;


Utils::Utils(){
}

DataSet Utils::GetDataset(H5File file, string path, string name){
    Group group = file.openGroup(path);
    hsize_t objCount =  group.getNumObjs();
    string groupArray [objCount];
    for (int i = 0; i < objCount; i++){
        groupArray[i] = file.getObjnameByIdx(i);
    }
};