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
        Vector<int>* transposed_rows = Vector<int>::transpose(rows,dim.getRow());
        Dimensions new_dim = Dimensions(dim.getCol(),dim.getRow());
        IntMatrix transposed = IntMatrix(new_dim);
        for (int i = 0; i < dim.getCol(); i++)
        {
            transposed.rows[i] = transposed_rows[i];
        }

        delete[] transposed_rows;
        
        return transposed;
    }


    //prev: IntMatrix::IntMatrix Identity(int dimension){
    IntMatrix IntMatrix::Identity(int dimension){
        Dimensions dim(dimension,dimension);
        IntMatrix new_mat(dim);
        for (int i=0;i<dimension;i++){

            new_mat.rows[i]=Vector<int>::Identity(dimension,i);
        }
        return new_mat;
    }

    IntMatrix& IntMatrix::operator=(const IntMatrix& mat){
            if(this==&mat){
                return *this;
            }
            delete[] rows;
            this->dim = mat.dim;
            this->rows= new Vector<int>[dim.getRow()];
            for (int i=0;i<dim.getRow();i++){
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
        return rows[row].getReference(col);    
    }

    int IntMatrix::operator()(int row,int col) const{
        return rows[row].get(col);  
     }


    std::ostream& operator<<(std::ostream& os,const IntMatrix& r){
        int* flattened = r.flatten_matrix();
        os<<printMatrix(flattened,r.dim);
        delete[] flattened;
        return os;
    }

    bool IntMatrix::all() const{
        for(int i = 0; i < dim.getRow();i++){
            if(rows[i].findMember(0)){
                return false;
            }

        }
        return true;  
    }

    bool IntMatrix::any() const{
        for(int i = 0; i < dim.getRow();i++){
            if(rows[i].findOtherThan(0)){
                return false;
            }

        }
        return true;  
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
    IntMatrix IntMatrix::operator-(const IntMatrix& to_add) const{
        return *this+(-to_add);
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

}