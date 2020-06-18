#include "Matrix.h"
#include "Auxiliaries.h"
#include <iostream>
namespace mtm{
    int main(){
        Dimensions dim(3,3);
        Matrix<int> mat(dim,3);
        std::cout<<mat<<std::endl;
        return 0;
    }

}
int main(){
    mtm::main();
}