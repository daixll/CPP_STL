// 双端队列
#pragma once
#include "../list/list.h"

namespace jiao{

template <typename T>
class deque : private list<T>{

public:
    deque():list<T>(){};    // 直接调用父类的构造函数
    ~deque(){};             // 直接调用父类的析构函数

    void push_front(const T& val){
        list<T>::insert(list<T>::begin(), val);
    };
    void push_back(const T& val){
        list<T>::insert(list<T>::end()->next, val);
    };
    void pop_front(){
        list<T>::erase(list<T>::begin());
    };
    void pop_back(){
        list<T>::erase(list<T>::end());
    };

    int size(){
        return list<T>::size();
    };

    T& front() const{
        return list<T>::begin()->data;
    }
    T& back() const{
        return list<T>::end()->data;
    }
};

}   // namespace jiao