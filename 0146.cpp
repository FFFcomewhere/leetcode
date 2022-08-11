#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//自己实现链表 哈希链表
class Node
{
public:
    int key, value;
    Node *next;
    Node *prev;
    Node(){
        key = 0;
        value = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(int key, int value)
    {
        key = key;
        value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleList
{
private:
    Node *head;
    Node *tail; //头尾虚节点
    int size;

public:
    DoubleList()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    //队尾添加节点
    void addLast(Node *node)
    {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    //删除节点
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    //删除首节点,并返回该节点
    Node *removeFirst()
    {
        if (head->next == nullptr)
        {
            return nullptr;
        }
        Node *first = head->next;
        remove(first);
        return first;
    }

    //返回链表长度
    int Size()
    {
        return size;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> h;
    DoubleList list;
    int capacity;

    //将已有元素变为最近使用
    void makeRecently(int key)
    {
        Node *node = h[key];
        list.remove(node);
        list.addLast(node);
    }

    //添加元素为最近使用
    void addRecently(int key, int value)
    {
        Node *node = new Node(key, value);
        list.addLast(node);
        h.emplace(key, node);
    }

    //删除元素
    void deleteKey(int key)
    {
        Node *node = h[key];
        list.remove(node);
    }

    //删除最久未使用元素
    void removeLeastRecently()
    {
        Node *node = list.removeFirst();
        h.erase(node->key);
        delete node;
    }

public:
    LRUCache(int capacity)
    {
        capacity = capacity;
    }

    int get(int key)
    {
        if (!h.count(key))
        {
            return -1;
        }

        makeRecently(key);
        return h[key]->value;
    }

    void put(int key, int value)
    {
        //包含重复元素
        if (h.count(key))
        {
            deleteKey(key);
            addRecently(key, value);
            return;
        }

        if (capacity == list.Size())
        {
            //删除最久未使用元素
            removeLeastRecently();
        }

        addRecently(key, value);
    }
};



//使用链表库
struct DLinkNode
{
    int key;
    int value;
    DLinkNode *prev;
    DLinkNode *next;
    DLinkNode()
    {
        this->key = 0;
        this->value = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }

    DLinkNode(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache
{
private:
    unordered_map<int, DLinkNode *> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int capacity;

    void addTohead(DLinkNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkNode *node)
    {
        removeNode(node);
        addTohead(node);
    }

    DLinkNode *removeTail()
    {
        DLinkNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        // 使用伪头部和伪尾部节点
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        // 如果 key 存在，先通过哈希表定位，再移到头部
        DLinkNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            // 如果 key 不存在，创建一个新的节点
            DLinkNode *node = new DLinkNode(key, value);
            // 添加进哈希表
            cache[key] = node;
            // 添加至双向链表的头部
            addTohead(node);
            ++size;
            if (size > capacity)
            {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkNode *removed = removeTail();
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else
        {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};

/*
分析:

方法:

总结:

*/