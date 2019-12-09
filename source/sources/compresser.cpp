
#include "../headers/compresser.hpp"

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
using namespace compresser;
using namespace H5;


Compresser::Compresser(){

}

void Compresser::CompressFile(H5File file, int compressionLevel){
    hsize_t chunk_dims[1] = {20};
    DataSet* originalDataset = new DataSet(file.openDataSet("/Raw/Reads/Read_1209/Signal"));
    DataType dt = originalDataset->getDataType();
    DataSpace* dataSpace = new DataSpace(originalDataset->getSpace());
    hsize_t dims[dataSpace->getSimpleExtentNdims()];
    dataSpace->getSimpleExtentDims(dims);
    int buffer[dims[0]];
    DSetCreatPropList* plist = new  DSetCreatPropList;
    plist->setDeflate(0);
    plist->setChunk(1, chunk_dims);
    originalDataset->read(buffer,dt,*dataSpace,*dataSpace);

    H5File* failsito = new H5File("cuco.fast5",H5F_ACC_TRUNC);
    DataSet* dataSet = new DataSet(failsito->createDataSet("coquito",dt,*dataSpace,*plist));    
    dataSet->write(buffer,dt);

	

}