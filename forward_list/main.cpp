#include "forward_list.h"
#include <forward_list>
#include <iostream>

jiao::forward_list<int> list1;
std::forward_list<int> list2;

void show(){
    std::cout << "\nlist jiao: ";
    for(auto it = list1.begin(); it; it=it->next)
        std::cout << it->data << " ";
    std::cout << "\nlist  std: ";
    for(auto it = list2.begin(); it != list2.end(); ++it)
        std::cout << *it << " ";
}

int main(){
    // 在链表头部插入元素
    for(int i=1; i<=5; ++i){
        list1.push_front(i);
        list2.push_front(i);
    }

    show();

    // 在链表第二个位置后插入元素
    auto it1 = list1.begin(); it1 = it1->next;
    auto it2 = list2.begin(); ++it2;
    list1.insert_after(it1, 6);
    list2.insert_after(it2, 6);

    show();

    // 删除链表头部元素
    list1.pop_front();
    list2.pop_front();

    show();

    return 0;
}