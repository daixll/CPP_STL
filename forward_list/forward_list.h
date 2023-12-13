// 单向链表
#pragma once
namespace jiao{

template <typename T>
class forward_list{

public:
    struct Node{
        T data;         // 数据域
        Node *next;     // 指针域
    };

    forward_list();     // 初始化链表
    ~forward_list();    // 销毁链表

    void insert_after(Node* pos, const T& val); // 在 pos 后面插入元素
    void erase_after(Node* pos);    // 删除 pos 后面的元素
    void push_front(const T& val);  // 在链表头部插入元素
    void push_back(const T& val);   // 在链表尾部插入元素
    void pop_front();               // 删除链表头部元素
    void pop_back();                // 删除链表尾部元素

    void clear();                   // 清空链表    
    int  size() const;              // 返回链表长度

    Node* begin() const;            // 第一个元素指针
    Node* end() const;              // 最后一个元素指针
private:
    Node* _head;                    // 头指针（带头结点）
    Node* _tail;                    // 尾指针（最后一个元素）
    int   _size;                    // 链表长度
};

template <typename T>
forward_list<T>::forward_list(){
    _head = new Node;               // 创建头结点
    _head->next = nullptr;          // 头结点无后继
    _tail = _head;                  // 尾指针指向头指针
    _size = 0;                      // 链表长度为 0
}

template <typename T>
forward_list<T>::~forward_list(){
    clear();                        // 清空链表
    delete _head;                   // 删除头指针
}

template <typename T>
void forward_list<T>::insert_after(Node* pos, const T& val){
    Node* newNode = new Node;       // 创建新结点

    newNode->data = val;            // 新结点的数据域为 val
    newNode->next = pos->next;      // 新结点的指针域指向 pos 的下一个结点
    pos->next = newNode;            // pos 的指针域指向新结点
    
    if(pos == _tail)                // 如果 pos 是尾指针
        _tail = newNode;            // 尾指针指向新结点
    ++_size;                        // 链表长度加 1
}

template <typename T>
void forward_list<T>::erase_after(Node* pos){
    if(pos == nullptr) return ;     // 如果 pos 为空，直接返回
    if(pos->next == nullptr) return;// 如果 pos 的下一个结点为空，直接返回
    
    Node* del = pos->next;          // 要删除的结点
    
    pos->next = del->next;          // pos 的指针域指向要删除结点的下一个结点
    
    if(del == _tail)                // 如果要删除的结点是尾指针
        _tail = pos;                // 尾指针指向 pos
    delete del;                     // 删除结点
    --_size;                        // 链表长度减 1
}

template <typename T>
void forward_list<T>::push_front(const T& val){
    insert_after(_head, val);       // 在头指针后面插入元素
}

template <typename T>
void forward_list<T>::push_back(const T& val){
    insert_after(_tail, val);       // 在尾指针后面插入元素
}

template <typename T>
void forward_list<T>::pop_front(){
    erase_after(_head);             // 删除头指针后面的结点
}

template <typename T>
void forward_list<T>::pop_back(){
    Node* pos = _head;              // 从头指针开始遍历
    while(pos->next != _tail)       // 直到找到尾指针的前一个结点
        pos = pos->next;
    erase_after(pos);               // 删除其后面的结点
}

template <typename T>
int forward_list<T>::size() const{
    return _size;
}

template <typename T>
void forward_list<T>::clear(){
    while(_size > 0)                // 链表长度大于 0
        erase_after(_head);         // 删除头指针后面的结点
    _head->next = nullptr;          // 头指针指向空
    _size = 0;                      // 链表长度为 0
}

template <typename T>
typename forward_list<T>::Node* forward_list<T>::begin() const{
    return _head->next;             // 返回头指针的下一个结点
}

template <typename T>
typename forward_list<T>::Node* forward_list<T>::end() const{
    return _tail;                   // 返回尾指针
}

}