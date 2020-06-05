#ifndef _INTMATRIX_H_
#define _INTMATRIX_H_

#include <iostream>
#include "Auxiliaries.h"
#include "vector.h"



namespace mtm{
    class IntMatrix{
        Vector<int>* rows;
        Dimensions dim;
        IntMatrix(Dimensions dim,int num=0);
        IntMatrix(const IntMatrix& mat);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& mat);
        










        ///

        IntMatrix operator<<(std::) const;
        IntMatrix operator()(int row,int col) const;

        
    };

}

#endif
