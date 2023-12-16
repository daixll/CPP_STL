#include "list.hpp"

namespace jiao{

template <typename T>
class stack : private list<T>{
public:
    stack():list<T>(){};    // 直接调用父类的构造函数
    ~stack(){};             // 直接调用父类的析构函数

    void push(const T& val){// 入栈
        list<T>::push_back(val);
    };                      // 只能从尾部插入

    void pop(){             // 出栈
        list<T>::pop_back();
    };                      // 只能从尾部删除

    void clear(){           // 清空栈
        list<T>::clear();
    };

    int size() const{       // 返回栈大小
        return list<T>::size();
    };

    T& top() const{         // 返回栈顶元素
        return list<T>::end()->data;
    }

};

}