
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include "Auxiliaries.h"
#include "Vector.h"



namespace mtm{
    enum logical_operator {eq,neq,lt,gt,lte,gte};
    template <class T>
    class Matrix{
        Vector<int>* rows;
        Dimensions dim;

        private:
        int* flatten_matrix() const;
        Matrix<T> applyLogicalOperator(int compare, logical_operator operation) const;

        public:
        Matrix<T>(Dimensions dim,int num=0);
        Matrix<T>(const Matrix<T>& mat);
        ~Matrix<T>();
        Matrix<T>& operator=(const Matrix<T>& mat);
        static Matrix<T> Identity(int dimension);
        int width() const;
        int height() const;
        int size() const;
        Matrix<T> transpose() const;
  

        ///arithmetic operators
        Matrix<T> operator+(const Matrix<T>& to_add) const;
        Matrix<T> operator-() const;
        Matrix<T> operator-(const Matrix<T>& to_subtract) const;

        friend Matrix<T> operator+(const Matrix<T>& matrix,int to_add);
        friend Matrix<T> operator+(int to_add, const Matrix<T>& matrix);//does not really need to be a friend
        friend Matrix<T>& operator+=(Matrix<T>& matrix,int to_add);// i'm not sure if this function should be symetric also.. currently it seems like it fits to be a member function. 


        //logic operators
        Matrix<T> operator==(int compare) const;
        Matrix<T> operator!=(int compare) const;
        Matrix<T> operator<=(int compare) const;
        Matrix<T> operator<(int compare) const;
        Matrix<T> operator>=(int compare) const;
        Matrix<T> operator>(int compare) const;

        friend std::ostream& operator<<(std::ostream& os,const Matrix<T>& r);

        int& operator()(int row,int col);
        int operator()(int row,int col) const;


        class iterator;  
        iterator begin() ;
        iterator end() ;
        
        class const_iterator;  
        const_iterator begin() const;
        const_iterator end() const;
    };

    bool any(const Matrix<T>& matrix);
    bool all(const Matrix<T>& matrix);

    class Matrix::iterator{
        friend class Matrix;
        
        Matrix<T>* matrix;
        int index;

        public:
        iterator(Matrix<T>* matrix,int index);

        iterator operator++(int); // postfix
        iterator& operator++(); // prefix
        int& operator*() const;
        bool operator==(const iterator& to_compare) const;
        bool operator!=(const iterator& to_compare) const;

    };
    class Matrix<T>::const_iterator{
        friend class Matrix<T>;
        
        const Matrix<T>* matrix;
        int index;

        public:
        const_iterator(const Matrix<T>* matrix,int index);

        const_iterator operator++(int); // postfix
        const_iterator& operator++(); // prefix
        int operator*() const;
        bool operator==(const const_iterator& to_compare) const;
        bool operator!=(const const_iterator& to_compare) const;

    };

}

#endif