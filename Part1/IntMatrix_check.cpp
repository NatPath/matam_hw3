#include "IntMatrix.h"
#include "Auxiliaries.h"
#include <iostream>

namespace mtm{
    void check_identity_creation(int n){ 
        IntMatrix a=IntMatrix::Identity(n);
        std::cout<<a;
    }

    void create_and_print_matrix(Dimensions dim,int num){
        IntMatrix a(dim,num);
        Dimensions dim2(5,5);
        IntMatrix b(dim2,num);
        a=b;
        std::cout<<a;

        
        
    }

    void check_transpose(Dimensions dim,int num){
        IntMatrix a(dim,num);
        const IntMatrix c(dim,9);
        a(1,2) = 1;
        a(3,2) = 3;
        a(4,0) = c(0,0);
        IntMatrix b = a.transpose();
        std::cout<<a<<std::endl;
        std::cout<<b;

    }


}
using namespace mtm;
int main(){
    Dimensions dim(5,3);
    create_and_print_matrix(dim,2);

    check_identity_creation(12);
    check_transpose(dim,2);
}