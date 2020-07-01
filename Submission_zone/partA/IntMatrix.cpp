#include "IntMatrix.h"
#include "Vector.h"
#include "Auxiliaries.h"
#include <iostream>

namespace mtm{

    
    IntMatrix::IntMatrix(Dimensions dim,int num):dim(dim){
        rows = new Vector<int>[dim.getRow()];
        for(int i = 0; i<dim.getRow(); i++){
            rows[i] = Vector<int>(dim.getCol(),num);
        }
    }
    IntMatrix::IntMatrix(const IntMatrix& mat):dim(mat.dim){
        rows = new Vector<int>[dim.getRow()];
        for (int i=0;i<dim.getRow();i++){
            rows[i]=mat.rows[i];
        }
    }

    IntMatrix IntMatrix::transpose() const{
        Vector<int>* transposed_rows = Vector<int>::transpose(rows,height());
        Dimensions new_dim = Dimensions(width(),height());
        IntMatrix transposed = IntMatrix(new_dim);
        for (int i = 0; i < width(); i++)
        {
            transposed.rows[i] = transposed_rows[i];
        }

        delete[] transposed_rows;
        
        return transposed;
    }


    IntMatrix IntMatrix::Identity(int dimension){
        Dimensions dim(dimension,dimension);
        IntMatrix new_mat(dim);
        for (int i=0;i<dimension;i++){

            new_mat.rows[i]=Vector<int>::Diagonal(dimension,i,1);
        }
        return new_mat;
    }

    IntMatrix& IntMatrix::operator=(const IntMatrix& mat){
            if(this==&mat){
                return *this;
            }
            delete[] rows;
            this->dim = mat.dim;
            this->rows= new Vector<int>[mat.height()];
            for (int i=0;i<mat.height();i++){
                rows[i]=mat.rows[i];
            }

            return *this;

    }

    IntMatrix::~IntMatrix(){
        delete[] rows;
    }
    int IntMatrix::width() const{
        return dim.getCol();
    }
    int IntMatrix::height() const{
        return dim.getRow();
    }

    int IntMatrix::size() const{
        return width()*height();

    }

    int* IntMatrix::flatten_matrix() const{
        int matrix_height=height();
        int matrix_width=width();
        int total_size=matrix_height*matrix_width;

        int* flat_matrix= new int[total_size];
        for (int i=0;i<matrix_height;i++){
            for(int j=0;j<matrix_width;j++){
                flat_matrix[i*matrix_width+j]=rows[i][j];
            }
        }
        return flat_matrix;
    }

    int& IntMatrix::operator()(int row, int col){
        return rows[row][col];    
    }

    const int IntMatrix::operator()(int row,int col) const{
        return rows[row][col];  
     }


    std::ostream& operator<<(std::ostream& os,const IntMatrix& r){
        int* flattened = r.flatten_matrix();
        os<<printMatrix(flattened,r.dim);
        delete[] flattened;
        return os;
    }

    bool all(const IntMatrix& matrix) {
        for (IntMatrix::const_iterator i =matrix.begin(); i != matrix.end(); i++){
            if(*i==0){
                return false;
            }
        }
        return true;
        

    }

    bool any(const IntMatrix& matrix) {
        for (IntMatrix::const_iterator i =matrix.begin(); i != matrix.end(); i++){
            if(*i!=0){
                return true;
            }
        }
        return false;
    }

    

    IntMatrix IntMatrix::operator+(const IntMatrix& to_add) const{
        IntMatrix new_matrix=to_add;
        int matrix_height=height();
        for (int i=0;i<matrix_height;i++){
            new_matrix.rows[i]+=rows[i];
        }
        return new_matrix;
    }
    IntMatrix IntMatrix::operator-() const{
        IntMatrix new_matrix(dim);
        int matrix_height=height();
        for (int i=0;i<matrix_height;i++){
            new_matrix.rows[i]=-rows[i];            
        }
        return new_matrix;
                
    }
    IntMatrix IntMatrix::operator-(const IntMatrix& to_subtract) const{
        return *this+(-to_subtract);
    }

    IntMatrix operator+(const IntMatrix& matrix,int to_add){
        return matrix+IntMatrix(matrix.dim,to_add);
    }
    IntMatrix operator+(int to_add, const IntMatrix& matrix){
        return matrix+to_add;
    }
    IntMatrix& operator+=(IntMatrix& matrix, int to_add){
        matrix=matrix+to_add;
        return matrix;
    }

    // converts the boolean value from the generic Vector operator functions into integers
    IntMatrix IntMatrix::applyLogicalOperator(int compare, logical_operator operation) const{
        IntMatrix result(dim);
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
                result.rows[i][j] = compared_row[j] ? 1 : 0;
            }
        }
        return result;
    }

    
    IntMatrix IntMatrix::operator==(int compare) const{
       return applyLogicalOperator(compare,eq);
    }

    IntMatrix IntMatrix::operator!=(int compare) const{
       return applyLogicalOperator(compare,neq);
    }

    IntMatrix IntMatrix::operator<(int compare) const{
       return applyLogicalOperator(compare,lt);
    }

    IntMatrix IntMatrix::operator>(int compare) const{
       return applyLogicalOperator(compare,gt);
    }

    IntMatrix IntMatrix::operator<=(int compare) const{
       return applyLogicalOperator(compare,lte);
    }

    IntMatrix IntMatrix::operator>=(int compare) const{
       return applyLogicalOperator(compare,gte);
    }


//iterator zone
    IntMatrix::iterator IntMatrix::begin() {
        return iterator(this,0);

    }
    IntMatrix::iterator IntMatrix::end() {
        return iterator(this,size());
    }

    IntMatrix::iterator::iterator(IntMatrix* matrix,int index) : matrix(matrix),index(index)
    {}


    IntMatrix::iterator& IntMatrix::iterator::operator++(){
        ++index;
        return *this;
    }
    IntMatrix::iterator IntMatrix::iterator::operator++(int){
        iterator result=*this;
        ++*this;
        return result;
    } 
    
    int& IntMatrix::iterator::operator*() const{
        int row = index/(*matrix).width();
        int col = index%(*matrix).width();
        return (*matrix).rows[row][col];
    }

    bool IntMatrix::iterator::operator==(const iterator& to_compare) const{
        if (matrix==to_compare.matrix && index==to_compare.index){
            return true;
        }
        return false;
    }   

    bool IntMatrix::iterator::operator!=(const iterator& to_compare) const{
        return !(*this==to_compare);
    }
//const_iterator zone
    IntMatrix::const_iterator::const_iterator(const IntMatrix* matrix,int index) : matrix(matrix),index(index)
    {}

    IntMatrix::const_iterator IntMatrix::begin() const{
        return const_iterator(this,0);

    }
    IntMatrix::const_iterator IntMatrix::end() const{
        return const_iterator(this,size());
    }

    const int IntMatrix::const_iterator::operator*() const{
        int row = index/(*matrix).width();
        int col = index%(*matrix).width();
        //return (*matrix).rows[row].get(col);
        return (*matrix).rows[row][col];
    }

    IntMatrix::const_iterator& IntMatrix::const_iterator::operator++(){
        ++index;
        return *this;
    }
    IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int){
        const_iterator result=*this;
        ++*this;
        return result;
    } 

    bool IntMatrix::const_iterator::operator==(const const_iterator& to_compare) const{
        if (matrix==to_compare.matrix && index==to_compare.index){
            return true;
        }
        return false;
    }   

    bool IntMatrix::const_iterator::operator!=(const const_iterator& to_compare) const{
        return !(*this==to_compare);
    }

}