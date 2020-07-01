#ifndef _INTMATRIX_H_
#define _INTMATRIX_H_

#include <iostream>
#include "Auxiliaries.h"
#include "Vector.h"



namespace mtm{
    enum logical_operator {eq,neq,lt,gt,lte,gte};
    class IntMatrix{
        Vector<int>* rows;
        Dimensions dim;

        private:
        /**
         * flatten_matrix:
         *  A method which returns a pointer to a single array of the elements of the matrix.
         *  In the order they are ment to be printed.
         * */
        int* flatten_matrix() const;

        /**
         * applyLogicalOperator:
         * A wrapper function for comparing with all boolean operators.
         * Returns a fitting Matrix<bool> indicating the comparision between the matrix the method is applied on,
         * the "compare" argument and "operation" (the logical operator given as argument)
         * */
        IntMatrix applyLogicalOperator(int compare, logical_operator operation) const;

        public:
        explicit IntMatrix(Dimensions dim,int num=0);
        IntMatrix(const IntMatrix& mat);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& mat);
        static IntMatrix Identity(int dimension);
        int width() const;
        int height() const;
        int size() const;
        IntMatrix transpose() const;
  

        ///arithmetic operators
        IntMatrix operator+(const IntMatrix& to_add) const;
        IntMatrix operator-() const;
        IntMatrix operator-(const IntMatrix& to_subtract) const;

        friend IntMatrix operator+(const IntMatrix& matrix,int to_add);

        //logic operators
        IntMatrix operator==(int compare) const;
        IntMatrix operator!=(int compare) const;
        IntMatrix operator<=(int compare) const;
        IntMatrix operator<(int compare) const;
        IntMatrix operator>=(int compare) const;
        IntMatrix operator>(int compare) const;

        friend std::ostream& operator<<(std::ostream& os,const IntMatrix& to_print);

        int& operator()(int row,int col);
        const int operator()(int row,int col) const;


        class iterator;  
        iterator begin() ;
        iterator end() ;
        
        class const_iterator;  
        const_iterator begin() const;
        const_iterator end() const;
    };
    IntMatrix operator+(int to_add, const IntMatrix& matrix);
    IntMatrix& operator+=(IntMatrix& matrix,int to_add); 

    bool any(const IntMatrix& matrix);
    bool all(const IntMatrix& matrix);

    class IntMatrix::iterator{
        friend class IntMatrix;
        
        IntMatrix* matrix;
        int index;

        public:
        iterator(IntMatrix* matrix,int index);

        iterator operator++(int); // postfix
        iterator& operator++(); // prefix
        int& operator*() const;
        bool operator==(const iterator& to_compare) const;
        bool operator!=(const iterator& to_compare) const;

    };
    class IntMatrix::const_iterator{
        friend class IntMatrix;
        
        const IntMatrix* matrix;
        int index;

        public:
        const_iterator(const IntMatrix* matrix,int index);

        const_iterator operator++(int); // postfix
        const_iterator& operator++(); // prefix
        const int operator*() const;
        bool operator==(const const_iterator& to_compare) const;
        bool operator!=(const const_iterator& to_compare) const;

    };

}

#endif
