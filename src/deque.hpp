// 双端队列
#pragma once
#include "list.hpp"

namespace jiao{

template <typename T>
class deque : private list<T>{
// 私有继承 不会继承基类的成员函数
public:
    deque():list<T>(){};    // 直接调用父类的构造函数
    ~deque(){};             // 直接调用父类的析构函数

    void push_front(const T& val){
        list<T>::push_front(val);
    };
    void push_back(const T& val){
        list<T>::push_back(val);
    };
    void pop_front(){
        list<T>::pop_front();
    };
    void pop_back(){
        list<T>::pop_back();
    };

    void clear(){
        list<T>::clear();
    };
    int size() const{
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