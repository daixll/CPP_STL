#include "vector.h"
#include <vector>
#include <iostream>

int main(){
    jiao::vector<int> v1;
    std::vector<int> v2;

    v1.insert(v1.begin(), 1);
    v1.insert(v1.begin()+1, 2);
    v1.insert(v1.begin()+2, 3);

    v2.insert(v2.begin(), 1);
    v2.insert(v2.begin()+1, 2);
    v2.insert(v2.begin()+2, 3);

    for(int i=0; i < 3; i++)
        std::cout<<v1[i]<<" ";
         
    std::cout<<"\n";
    for(auto i: v2)
        std::cout<<i<<" ";
    std::cout<<"\n";

    

    return 0;
}