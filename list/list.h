// 双向链表
#pragma once
namespace jiao{

template <typename T>
class list{

public:
    struct Node{
        T data;     // 数据域
        Node *prev; // 前驱指针域
        Node *next; // 后继指针域
    };

    list();     // 初始化链表
    ~list();    // 销毁链表

    void insert(Node* pos, const T& val);   // 在 pos 处插入元素
    void erase(Node* pos);                  // 删除 pos 处的元素

    void clear();
    int size();

    Node* begin() const;            // 返回链表第一个元素指针
    Node* end() const;              // 返回链表最后一个元素指针

private:
    Node* _head;        // 头指针（带头结点）
    Node* _tail;        // 尾指针（最后一个结点的下一个）
    int _size;          // 链表长度
};

template <typename T>
list<T>::list(){
    _head = new Node;
    _tail = new Node;
    _head->prev = nullptr;
    _head->next = _tail;
    _tail->prev = _head;
    _tail->next = nullptr;
    _size = 0;
}

template <typename T>
list<T>::~list(){
    clear();                    // 清空链表
    delete _head;               // 删除头指针
}

template <typename T>
void list<T>::insert(Node* pos, const T& val){
    Node* newNode = new Node;   // 创建新结点

    newNode->data = val;        // 新结点的数据域为 val
    newNode->next = pos;        // 新结点的指针域指向 pos
    newNode->prev = pos->prev;  // 新结点的前驱指针域指向 pos 的前驱
    
    pos->prev->next = newNode;  // pos 的前驱结点的后继指针域指向新结点
    pos->prev = newNode;        // pos 的前驱指针域指向新结点

    ++_size;                    // 链表长度加一
}

template <typename T>
void list<T>::erase(Node* pos){
    if(pos == nullptr) return ;     // pos 为空指针，直接返回
    if(_size == 0) return ;         // 链表为空，直接返回
    pos->prev->next = pos->next;    // pos 的前驱结点的后继指针域指向 pos 的后继结点
    pos->next->prev = pos->prev;    // pos 的后继结点的前驱指针域指向 pos 的前驱结点

    delete pos;                     // 删除 pos 结点
    --_size;                        // 链表长度减一
}


template <typename T>
void list<T>::clear(){

}

template <typename T>
int list<T>::size(){
    return _size;
}

template <typename T>
typename list<T>::Node* list<T>::begin() const{
    return _head->next;
}

template <typename T>
typename list<T>::Node* list<T>::end() const{
    return _tail->prev;
}



}   // namespace jiao