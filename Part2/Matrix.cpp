#include "Matrix.h"
#include "Auxiliaries.h"
#include <iostream>
#include <stdexcept>

using namespace mtm;
void testMakeMatrices(){
    int n=13;
    int m=37;
    Dimensions dim1(n,m);
    Dimensions dim2(m,n);

    int intial_int_1=5;
    int intial_int_2=12;

    try{
        Matrix<int> int_mat1(dim1,intial_int_1);
        Matrix<int> int_mat2(dim1,intial_int_2);
        Matrix<int> int_mat3(dim1);
        Matrix<int> int_mat4(dim2);
        Matrix<int> int_mat5=int_mat4;


        Matrix<std::string> string_mat1(dim1,"hello");
        Matrix<std::string> string_mat2(dim1," ");
        Matrix<std::string> string_mat3(dim1,"world");
        Matrix<std::string> string_mat4(dim1);
        Matrix<std::string> string_mat5=string_mat1;
        Matrix<std::string> string_mat_op(dim2,"oops");


        string_mat4=string_mat5+std::string(" ")+string_mat3;
        std::cout<<string_mat4<<std::endl;
        try{
            string_mat_op=string_mat_op;
            string_mat_op=string_mat_op+string_mat4;
        }catch(std::exception e){
            std::cout<<e.what()<<std::endl;
        }

        

        Matrix<float> float_mat = Matrix<float>::Diagonal(n,23.4f);
        const Matrix<float> const_float_mat = Matrix<float>::Diagonal(n,0.6f);
        float_mat=float_mat+const_float_mat;
        std::cout<<float_mat<<std::endl;


    }
    catch(std::exception e){
        std::cout<<e.what();
    }
    


}
void testDiagonalMatrices(){
    int n=6;
    Matrix<int> int_mat = Matrix<int>::Diagonal(6,42);

}
int main(){
    testMakeMatrices();

}