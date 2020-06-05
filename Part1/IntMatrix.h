#ifndef _INTMATRIX_H_
#define _INTMATRIX_H_

#include <iostream>
#include "Auxiliaries.h"
#include "Vector.h"



namespace mtm{
    class IntMatrix{
        Vector<int>* rows;
        mtm::Dimensions dim;

        public:
        IntMatrix(Dimensions dim,int num=0);
        IntMatrix(const IntMatrix& mat);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& mat){
            delete[] rows;
            dim = mat.dim;
            rows= new Vector<int>[dim.getRow()];
            for (int i=0;i<dim.getRow();i++){
                rows[i]=mat.rows[i];
            }

            return *this;

        };
        static IntMatrix Identity(int dimension);
        int width() const;
        int height() const;
        int size() const;
        IntMatrix transpose() const;
        
    



        



        ///


        IntMatrix operator-() const;
        IntMatrix& operator-=(int to_remove);
        IntMatrix operator-(int to_remove);
        IntMatrix& operator+=(int to_add);
        IntMatrix operator+(int to_add);
        IntMatrix operator<<() const;
        IntMatrix operator()(int row,int col) const;

        
    };



}

#endif
