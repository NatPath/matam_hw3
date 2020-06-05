#include "IntMatrix.h"
#include "Vector.h"
#include "Auxiliaries.h"

namespace mtm{

    IntMatrix::IntMatrix(Dimensions dim,int num=0):dim(dim){
        rows = new Vector<int>[dim.getRow()];
        for(int i = 0; i<dim.getRow(); i++){
            rows[i] = Vector<int>(num,dim.getCol());
        }
    }
    IntMatrix::IntMatrix(const IntMatrix& mat):dim(mat.dim){
        rows= new Vector<int>[dim.getRow()];
        for (int i=0;i<dim.getRow();i++){
            rows[i]=mat.rows[i];
        }
    }




    IntMatrix::IntMatrix Identity(int dimension){
        Dimensions dim(dimension,dimension);
        IntMatrix new_mat = IntMatrix(dim);
        for (int i=0;i<dimension;i++){

            new_mat.rows[i]=Vector<int>::Identity(dimension,i);
        }

    }


    IntMatrix::~IntMatrix(){
        delete[] rows;
    }

}