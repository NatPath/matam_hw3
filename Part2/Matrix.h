
#ifndef _MATRIX_H_
#define _MATRIX_H_



#include <iostream>
#include <exception>
#include "Vector.h"
#include "Auxiliaries.h"


namespace mtm{
    enum logical_operator {eq,neq,lt,gt,lte,gte};
    template <class T>
    class Matrix{
        Vector<T>* rows;
        Dimensions dim;

        T* flatten_matrix() const{
            int matrix_height=height();
            int matrix_width=width();
            int total_size=matrix_height*matrix_width;

            T* flat_matrix= new T[total_size];
            try{
                for (int i=0;i<matrix_height;i++){
                    for(int j=0;j<matrix_width;j++){
                        flat_matrix[i*matrix_width+j]=rows[i][j];
                    }
                }
            }
            catch(...){
                delete[] flat_matrix;
                throw;
            }
            return flat_matrix;
        };
        Matrix<bool> applyLogicalOperator(T compare, logical_operator operation) const{
            Matrix<bool> result(dim);
            Vector<bool> compared_row;
            for (int i = 0; i < height(); i++)
            {
                switch(operation){
                    case eq: compared_row = (rows[i] == compare); break;
                    case neq: compared_row = (rows[i] != compare); break;
                    case lt: compared_row = (rows[i] < compare); break;
                    case gt: compared_row = (rows[i] > compare); break;
                    case lte: compared_row = (rows[i] <= compare); break;
                    case gte: compared_row = (rows[i] >= compare); break;
                }
                for (int j = 0; j < width(); j++)
                {
                    //result.rows[i].getReference(j) = compared_row.get(j) ? 1 : 0;
                    result.rows[i][j] = compared_row[j] ? 1 : 0;
                }
            }
            return result;
        };

        

        public:
// can we put this part in another file?
        class AccessIllegalElement: public Exception {
            public:
            const char* what() const noexcept override{
                return "Mtm matrix error: An attempt to access an illegal element";
            }
        };
        class IllegalInitialization: public Exception {
            public:
            const char* what() const noexcept override{
                return "Mtm matrix error: Illegal initialization values";
            }
        };
        class DimensionMismatch: public Exception {
            Dimensions dim1;
            Dimensions dim2;
            public:
            DimensionMismatch(const Dimensions& dim1,const Dimensions& dim2) : dim1(dim1),dim2(dim2){};
            const char* what() {
                return std::string("Mtm matrix error: Dimensions mismatch: "+dim1.toString() + dim2.toString()).c_str();
            }
        };
        //Previous exeptions- inherited from runtime_error, it's a shame we can't use them..
        /*
        class AccessIllegalElement: public std::runtime_error {
            public:
            AccessIllegalElement():std::runtime_error("Mtm matrix error: An attempt to access an illegal element"){};
        };
        class IllegalInitialization: public std::runtime_error {
            public:
            IllegalInitialization():std::runtime_error("Mtm matrix error: Illegal initialization values"){};
            
        };
        class DimensionMismatch: public std::runtime_error {
            public:
            DimensionMismatch(Dimensions dim1, Dimensions dim2) :  std::runtime_error("Mtm matrix error: Dimensions mismatch: "+dim1.toString() + dim2.toString())
            {
            };
        };
        */
        Matrix<T>(Dimensions dim, T initialize = T()):dim(dim){
            if(dim.getCol()<=0||dim.getRow()<=0){
                throw IllegalInitialization();
            }
            rows = new Vector<T>[dim.getRow()];
            for(int i = 0; i<dim.getRow(); i++){
                rows[i] = Vector<T>(dim.getCol(),initialize);
            }
        };
        Matrix<T>(const Matrix<T>& mat):dim(mat.dim){
            rows = new Vector<T>[dim.getRow()];
            for (int i=0;i<dim.getRow();i++){
                rows[i]=mat.rows[i];
            }
        };
        ~Matrix<T>(){
            delete[] rows;
        };
        Matrix<T>& operator=(const Matrix<T>& mat){
            if(this==&mat){
                return *this;
            }
            Vector<T>* data_temp=new Vector<T>[mat.height()];
            try{
                for (int i=0;i<mat.height();i++){
                    data_temp[i]=mat.rows[i];
                }
                delete[] rows;
                this->dim = mat.dim;
                this->rows= data_temp;
            }
            catch(...){
                delete[] data_temp;
                throw;
            }
            return *this;
        };
        static Matrix<T> Diagonal(int dimension, T value){
            if (dimension<=0){
                throw IllegalInitialization();
            }
            Dimensions dim(dimension,dimension);
            Matrix<T> new_mat(dim);
            for (int i=0;i<dimension;i++){

                new_mat.rows[i]=Vector<T>::Diagonal(dimension,i,value);
            }
            return new_mat;
        };
        int width() const{
            return dim.getCol();
        };
        int height() const{
            return dim.getRow();
        };
        int size() const{
            return width()*height();
        };
        Matrix<T> transpose() const{

            Vector<T>* transposed_rows = Vector<T>::transpose(rows,height());
            Dimensions new_dim = Dimensions(width(),height());
            Matrix transposed = Matrix(new_dim);
            for (int i = 0; i < width(); i++)
            {
                transposed.rows[i] = transposed_rows[i];
            }

            delete[] transposed_rows;
            
            return transposed;
        };
  

        ///arithmetic operators
        Matrix<T> operator+(const Matrix<T>& to_add) const{
            if (dim!=to_add.dim){
                throw DimensionMismatch(dim,to_add.dim);
            }
            Matrix new_matrix=to_add;
            int matrix_height=height();
            for (int i=0;i<matrix_height;i++){
                new_matrix.rows[i]+=rows[i];
            }
            return new_matrix;
        };
        Matrix<T> operator-() const{
            Matrix new_matrix(dim);
            int matrix_height=height();
            for (int i=0;i<matrix_height;i++){
                new_matrix.rows[i]=-rows[i];            
            }
            return new_matrix;
        };
        Matrix<T> operator-(const Matrix<T>& to_subtract) const{
            if (dim!=to_subtract.dim){
                throw DimensionMismatch(dim,to_subtract.dim);
            }
            return *this+(-to_subtract);
        };

        template <class Y>
        friend Matrix<Y> operator+(const Matrix<Y>& matrix,Y to_add);
        template <class Y>
        friend Matrix<Y> operator+(Y to_add, const Matrix<Y>& matrix);//does not really need to be a friend
        template <class Y>
        friend Matrix<Y>& operator+=(Matrix<Y>& matrix,Y to_add);// i'm not sure if this function should be symetric also.. currently it seems like it fits to be a member function. 


        //logic operators
        Matrix<T> operator==(T compare) const{
            return applyLogicalOperator(compare,eq);
        };
        Matrix<T> operator!=(T compare) const{
            return applyLogicalOperator(compare,neq);
        };
        Matrix<T> operator<=(T compare) const{
            return applyLogicalOperator(compare,lte);
        };
        Matrix<T> operator<(T compare) const{
            return applyLogicalOperator(compare,lt);
        };
        Matrix<T> operator>=(T compare) const{
            return applyLogicalOperator(compare,gte);
        };
        Matrix<T> operator>(T compare) const{
            return applyLogicalOperator(compare,gt);
        };
        template <class Y>
        friend std::ostream& operator<<(std::ostream& os,const Matrix<Y>& to_print);

        T& operator()(int row,int col){
            if(row<0 || row>=height() || col<0 || col>=width()){
                throw AccessIllegalElement();
            }
            //return rows[row].getReference(col);    
            return rows[row][col];    

        };
        const T operator()(int row,int col) const{
            if(row<0 || row>=height() || col<0 || col>=width()){
                throw AccessIllegalElement();
            }
            //return rows[row].get(col);  
            return rows[row][col];  
        };


        class iterator;  
        iterator begin(){
            return iterator(this,0);
        } ;
        iterator end(){
            return iterator(this,size());
        } ;
        
        class const_iterator;  
        const_iterator begin() const{
            return const_iterator(this,0);

        };
        const_iterator end() const{
            return const_iterator(this,size());
        };

        template <typename applyable>
        Matrix<T> apply(applyable func) const{
           Matrix<T> new_matrix(dim);
           const_iterator i=begin();
           iterator j=new_matrix.begin();
           for (; i != end(); i++, j++){
                *j = func(*i);
           }
           return new_matrix;
        }
    };

    template <class T>
    bool any(const Matrix<T>& matrix){
        for (typename Matrix<T>::const_iterator i = matrix.begin(); i != matrix.end(); i++){
            if(*i){
                return true;
            }
        }
        return false;
    }

    template <class T>
    bool all(const Matrix<T>& matrix){
        for (typename Matrix<T>::const_iterator i =matrix.begin(); i != matrix.end(); i++){
            if(!(*i)){
                return false;
            }
        }
        return true;
    }

    template <class T>
     std::ostream& operator<<(std::ostream& os,const Matrix<T>& to_print) {
         /*
            os<<printMatrix(os,to_print.begin(),to_print.end(),to_print.width());
            return os;
        */
       return printMatrix(os,to_print.begin(),to_print.end(),to_print.width());
            
    }

    template <class T>
    Matrix<T> operator+(const Matrix<T>& matrix,T to_add){
        return matrix+Matrix<T>(matrix.dim,to_add);
    }

    template <class T>
    Matrix<T> operator+(T to_add, const Matrix<T>& matrix){
        return matrix+to_add;
    }

    template <class T>
    Matrix<T>& operator+=(Matrix<T>& matrix,T to_add){
        matrix=matrix+to_add;
        return matrix;
    } 

    template <class T>
    class Matrix<T>::iterator{
        friend class Matrix;
        
        Matrix<T>* matrix;
        int index;

        public:
        iterator(Matrix<T>* matrix,int index):matrix(matrix),index(index){};

        iterator operator++(int){
            iterator result=*this;
            ++*this;
            return result;
        };
        // postfix
        iterator& operator++(){ 
            ++index;
            return *this;
        }; 
        T& operator*() const {
            if(index >= matrix->size()){
                throw Matrix::AccessIllegalElement();
            }
            int row = index/(*matrix).width();
            int col = index%(*matrix).width();
            //return (*matrix).rows[row].getReference(col);
            return (*matrix).rows[row][col];
        };
        bool operator==(const iterator& to_compare) const {
            if (matrix==to_compare.matrix && index==to_compare.index){
                return true;
            }
            return false;
        };
        bool operator!=(const iterator& to_compare) const {
            return !(*this==to_compare);
        };
        

    };
    template <class T>
    class Matrix<T>::const_iterator{
        friend class Matrix<T>;
        
        const Matrix<T>* matrix;
        int index;

        public:
        const_iterator(const Matrix<T>* matrix,int index):matrix(matrix),index(index){};
        // postfix
        const_iterator operator++(int){ 
            const_iterator result=*this;
            ++*this;
            return result;
            
        }; 
        // prefix
        const_iterator& operator++(){
            ++index;
            return *this;
        }; 
        const T operator*() const{

            if(index >= matrix->size()){
                throw Matrix::AccessIllegalElement();
            }
            int row = index/(*matrix).width();
            int col = index%(*matrix).width();
            //return (*matrix).rows[row].get(col);
            return (*matrix).rows[row][col];
        };
        bool operator==(const const_iterator& to_compare) const{
            if (matrix==to_compare.matrix && index==to_compare.index){
                return true;
            }
            return false;
        };
        bool operator!=(const const_iterator& to_compare) const{
            return !(*this==to_compare);
        };

    };

}

#endif