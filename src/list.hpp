// 双向链表
#pragma once
namespace jiao{

template <typename T>
class list{

public:
    struct Node{
        T     data;         // 数据域
        Node* prev;         // 前驱指针域
        Node* next;         // 后继指针域
    };

    list();                 // 初始化链表
    ~list();                // 销毁链表

    void insert(Node* pos, const T& val);   // 在 pos 处插入元素
    void erase(Node* pos);                  // 删除 pos 处的元素
    void push_front(const T& val);          // 在链表头部插入元素
    void push_back(const T& val);           // 在链表尾部插入元素
    void pop_front();                       // 删除链表头部元素
    void pop_back();                        // 删除链表尾部元素

    void clear();           // 清空链表
    int  size() const;      // 返回链表长度

    Node* begin() const;    // 第一个元素指针
    Node* end() const;      // 最后一个元素指针
private:
    Node* _head;            // 头指针（带头结点）
    Node* _tail;            // 尾指针（最后一个元素的下一个）
    int   _size;            // 链表长度
};

template <typename T>
list<T>::list(){
    _head = new Node;       // 创建头结点
    _tail = new Node;       // 创建尾结点
    _head->prev = nullptr;  // 头结点无前驱
    _head->next = _tail;    // 头结点后驱为尾结点
    _tail->prev = _head;    // 尾结点前驱为头结点
    _tail->next = nullptr;  // 尾结点无后继
    _size = 0;              // 链表长度为 0
}

template <typename T>
list<T>::~list(){
    clear();                // 清空链表
    delete _head;           // 删除头指针
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
    if(pos == nullptr)  return ;    // pos 为空指针，直接返回
    if(pos == _head)    return ;    // pos 为头结点，直接返回
    if(pos == _tail)    return ;    // pos 为尾结点，直接返回
    if(_size == 0)      return ;    // 链表为空，直接返回

    pos->prev->next = pos->next;    // pos 的前驱结点的后继指针域指向 pos 的后继结点
    pos->next->prev = pos->prev;    // pos 的后继结点的前驱指针域指向 pos 的前驱结点

    delete pos;                     // 删除 pos 结点
    --_size;                        // 链表长度减一
}


template <typename T>
void list<T>::push_front(const T& val){
    insert(_head->next, val);       // 在头结点的后面插入元素
}

template <typename T>
void list<T>::push_back(const T& val){
    insert(_tail->prev, val);       // 在尾结点的前面插入元素
}

template <typename T>
void list<T>::pop_front(){
    erase(_head->next);             // 删除头结点的后继结点
}

template <typename T>
void list<T>::pop_back(){
    erase(_tail->prev);             // 删除尾结点的前驱结点
}

template <typename T>
void list<T>::clear(){
    while(_size > 0)                // 链表长度大于 0
        erase(_head->next);         // 删除头结点的后继结点
}

template <typename T>
int list<T>::size() const{
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