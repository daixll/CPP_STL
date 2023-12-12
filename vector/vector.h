#pragma once
#include <iostream>

namespace jiao{

template <typename T>
class vector{
    
public:
    vector();
    ~vector();

    // 重载 [] 运算符
    T& operator[](int index){
        if(index < 0 || index >= _size){
            std::cerr << "index out of range" << std::endl;
            exit(1);
        }
        return _head[index];
    }

    void insert(T* pos, const T& val);  // 在 pos 处插入元素
    void erase(T* pos);                 // 删除 pos 处的元素
    void push_front(const T& val);      // 在数组头部插入元素
    void push_back(const T& val);       // 在数组尾部插入元素
    void pop_front();                   // 删除数组头部元素
    void pop_back();                    // 删除数组尾部元素

    void clear();                       // 清空数组
    int  size() const;                  // 返回数组长度

    T*  begin() const;                  // 返回第一个元素指针
    T*  end() const;                    // 返回最后一个元素指针
    
private:
    T*  _head;                          // 头指针，指向连续内存空间的首地址
    int _size;                          // 数组元素个数
    int _max_size;                      // 数组容量

    void resize(const int new_size);    // 扩容
};

template <typename T>
vector<T>::vector(){
    _head = new T[666];                 // 申请 666 个 T 类型的连续内存空间
    _size = 0;                          // 数组元素个数初始化为 0
    _max_size = 666;                    // 数组容量初始化为 666
}

template <typename T>
vector<T>::~vector(){
    delete[] _head;                     // 释放内存空间
}

template <typename T>
void vector<T>::resize(const int new_size){
    T* new_head = new T[new_size];      // 申请 new_size 个 T 类型的连续内存空间
    for(int i=0; i < _size; i++)        // 将原数组的元素复制到新数组
        new_head[i] = _head[i];
    delete[] _head;                     // 释放原数组的内存空间
    _head = new_head;                   // 将新数组的首地址赋值给 _head
    _max_size = new_size;               // 更新数组容量
}

template <typename T>
void vector<T>::insert(T* pos, const T& val){
    if(_size == _max_size)              // 如果数组已满
        resize(2*_max_size);            // 扩容
    for(T* p = _head+_size; p > pos; p--)
        *p = *(p - 1);                  // 将 pos 之后的元素向后移动一位
    *pos = val;                         // 将 val 插入 pos 处
    _size++;                            // 数组元素个数加 1
}

template <typename T>
void vector<T>::erase(T* pos){
    for(T* p = pos; p < _head+_size-1; p++)
        *p = *(p + 1);                  // 将 pos 之后的元素向前移动一位
    _size--;                            // 数组元素个数减 1
}

template <typename T>
void vector<T>::clear(){
    _size = 0;                          // 将数组元素个数置为 0
    _max_size = 666;                    // 将数组容量置为 666
    delete[] _head;                     // 释放内存空间
    _head = new T[666];                 // 申请 666 个 T 类型的连续内存空间
}

template <typename T>
int vector<T>::size() const{
    return _size;                       // 返回数组元素个数
}

template <typename T>
T* vector<T>::begin() const{
    return _head;                       // 返回数组首地址
}

}   // namespace jiao