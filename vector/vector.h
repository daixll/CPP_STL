#pragma once

namespace jiao{

template <typename T>
class vector{
    
public:
    vector();
    ~vector();

    void insert(T* pos, const T& val);  // 在 pos 处插入元素
    void push_back(const T& val);       // 在数组尾部插入元素

    T*  begin() const;  // 返回第一个元素指针
    T*  end() const;    // 返回最后一个元素指针
    
private:
    T*  _head;          // 头指针,指向连续内存空间的首地址
    int _size;          // 数组元素个数
    int _max_size;      // 数组容量
};

}

namespace jiao{

template <typename T>
vector<T>::vector(){
    _head = new T[666]; // 申请 666 个 T 类型的连续内存空间
    _size = 0;          // 数组元素个数初始化为 0
    _max_size = 666;    // 数组容量初始化为 666
}

template <typename T>
vector<T>::~vector(){}
}