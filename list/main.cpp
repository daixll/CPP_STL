#include <list>
#include "list.h"
#include <iostream>

int main(){
    std::list<int> l1;
    jiao::list<int> l2;

    l2.insert(l2.begin(), 888);
    l2.insert(l2.begin(), 999);
    l2.erase(l2.begin());

    std::cout << l2.begin()->data << "\n";

    return 0;
}