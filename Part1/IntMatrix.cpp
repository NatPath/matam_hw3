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
        rows= new Vector<int>[dim.getCol()];
        for (int i=0;i<dim.getRow();i++){
            rows[i]=mat.rows[i];
        }
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
        int m_height=height();
        int m_width=width();
        int total_size=m_height*m_width;

        int* flat_matrix=new int[total_size];
        for (int i=0;i<m_height;i++){
            for(int j=0;j<m_width;j++){
                flat_matrix[i*m_width+j]=rows[i][j];
            }
        }
        return flat_matrix;
    }

    std::ostream& operator<<(std::ostream& os,const IntMatrix& r){

        os<<printMatrix(r.flatten_matrix(),r.dim);
    }

}