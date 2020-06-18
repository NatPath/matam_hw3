#include "Matrix.h"
#include "Auxiliaries.h"
#include <iostream>
namespace mtm{
    int main(){
        Dimensions dim(3,3);
        std::cout<<dim.getRow();
        Matrix<int> mat(dim,3);
        return 0;
    }

}
int main(){
    mtm::main();
}