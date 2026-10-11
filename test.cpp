#include "crossarray.h"
#include <iostream>
int main(){
    sjtu::CrossArray ca(2);
    int a[] = {1,2,3};
    ca.InsertArrays(a,3);
    int b[] = {4,5};
    ca.InsertArrays(b,2);
    std::cout<<ca.At(0,1) <<' '<< ca.At(1,0) <<'\n';
    int add[] = {9,9};
    ca.AppendArrays(add,0,2);
    std::cout<<ca.At(0,3) <<'\n';
    sjtu::CrossArray ca2 = ca;
    std::cout<< ca2.At(0,0) <<' '<< ca2.At(1,1) <<'\n';
    std::cout<< (ca.WhichGreater(ca2).At(0,0)) <<'\n';
    return 0;
}
