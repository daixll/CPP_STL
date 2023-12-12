#include <deque>
#include "deque.h"
#include <iostream>

int main(){
    std::deque<int> dq1;
    jiao::deque<int> dq2;

    dq2.push_front(1);
    dq2.push_back(2);

    std::cout << dq2.size() << "   ";
    std::cout << dq2.front() << " ";
    std::cout << dq2.back() << "\n";

    dq2.pop_back();

    std::cout << dq2.size() << "   ";
    std::cout << dq2.front() << " ";
    std::cout << dq2.back() << "\n";

    dq2.pop_back();

    std::cout << dq2.size() << "   ";
    std::cout << dq2.front() << " ";
    std::cout << dq2.back() << "\n";    

    return 0;
}