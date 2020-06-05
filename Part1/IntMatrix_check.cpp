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


}
using namespace mtm;
int main(){
    Dimensions dim(3,3);
    create_and_print_matrix(dim,2);

    check_identity_creation(12);
}