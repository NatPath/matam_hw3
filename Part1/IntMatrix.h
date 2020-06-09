#ifndef _INTMATRIX_H_
#define _INTMATRIX_H_

#include <iostream>
#include "Auxiliaries.h"
#include "Vector.h"



namespace mtm{
    class IntMatrix{
        Vector<int>* rows;
        Dimensions dim;

        private:
        int* flatten_matrix() const;
        public:
        IntMatrix(Dimensions dim,int num=0);
        IntMatrix(const IntMatrix& mat);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& mat);
        static IntMatrix Identity(int dimension);
        int width() const;
        int height() const;
        int size() const;
        IntMatrix transpose() const;
  

        ///


        IntMatrix operator+(const IntMatrix& to_add) const;
        IntMatrix operator-() const;
        IntMatrix operator-(const IntMatrix& to_subtract) const;

        friend IntMatrix operator+(const IntMatrix& matrix,int to_add);
        friend IntMatrix operator+(int to_add, const IntMatrix& matrix);//does not really need to be a friend
        friend IntMatrix& operator+=(IntMatrix& matrix,int to_add);

        friend std::ostream& operator<<(std::ostream& os,const IntMatrix& r);
        int& operator()(int row,int col);
        int operator()(int row,int col) const;

        bool any() const;
        bool all() const;
    };



}

#endif
