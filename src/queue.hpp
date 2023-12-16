#pragma once
#include "list.hpp"

namespace jiao{

template <typename T>
class queue : private list<T>{
public:
    queue():list<T>(){};    // 直接调用父类的构造函数
    ~queue(){};             // 直接调用父类的析构函数

    void push(const T& val){// 入队
        list<T>::push_back(val);
    };                      // 只能从尾部插入

    void pop(){             // 出队
        list<T>::pop_front();
    };                      // 只能从头部删除

    void clear(){           // 清空队列
        list<T>::clear();
    };

    int size() const{       // 返回队列大小
        return list<T>::size();
    };

    T& front() const{       // 返回队头元素
        return list<T>::begin()->data;
    }

    T& back() const{        // 返回队尾元素
        return list<T>::end()->data;
    }
};

}   // namespace jiao