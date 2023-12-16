#include <iostream>
#include "src/forward_list.hpp"
#include "src/list.hpp"
#include "src/deque.hpp"
#include "src/queue.hpp"
#include "src/stack.hpp"

int main(){
    //jiao::forward_list<int> fl1;
    //jiao::list<int> l1;
    //jiao::deque<int> dq1;
    //jiao::queue<int> q1;
    jiao::stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.pop();

    std::cout << s1.top() << std::endl;


    return 0;
}