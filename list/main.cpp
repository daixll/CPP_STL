#include <list>
#include "list.h"
#include <iostream>

int main(){
    std::list<int> l1;
    jiao::list<int> l2;

    l1.insert(l1.begin(), 1);
    l2.insert(l2.begin(), 1);

    return 0;
}