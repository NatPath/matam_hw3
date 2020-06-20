#include "Matrix.h"
#include "Auxiliaries.h"
#include <iostream>
#include <stdexcept>

using namespace mtm;
void print(std::string str){
    std::cout<<str<<std::endl;
}
void testMakeMatrices(){
    print("testing Matrix making");
    int n=4;
    int m=3;
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
        }catch(Exception e){
            std::cout<<e.what()<<std::endl;
        }

        

        Matrix<float> float_mat = Matrix<float>::Diagonal(n,23.4f);
        const Matrix<float> const_float_mat = Matrix<float>::Diagonal(n,0.6f);
        float_mat=float_mat+const_float_mat;
        std::cout<<float_mat<<std::endl;


    }
    catch(Exception e){
        std::cout<<e.what()<<std::endl;
    }
}
void testTranspose(){
    print("testing transpose");
    int n=13;
    int m=12;
    Dimensions dim1(n,m);
    Dimensions dim2(m,n);
    
    Matrix<std::string> string_mat1(dim1,"M");
    Matrix<std::string> string_mat2(dim2,"W");
    try{
        string_mat1=string_mat1+string_mat2;
    }catch(Exception e){
        std::cout<<e.what()<<std::endl;
    }
    string_mat1(0,1)=std::string("0");

    std::cout<<string_mat1<<std::endl;

    string_mat1=string_mat1.transpose();

    std::cout<<string_mat1<<std::endl;

    try{
        string_mat1=string_mat1+string_mat2;
        std::cout<<string_mat1<<std::endl;
    }catch(Exception e){
        std::cout<<e.what()<<std::endl;
    }

    



}
int main(){
    testMakeMatrices();
    testTranspose();

}