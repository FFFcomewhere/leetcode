#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

class LinkedNode {
public:
    int val;
    LinkedNode* next;
    LinkedNode(){
        val = 0;
        next = nullptr;
    }

    LinkedNode(int _val){
        val = _val;
        next = nullptr;
    }
};

class MyLinkedList {
private:
    int size;
    LinkedNode* head;
public:
    MyLinkedList() {
        size = 0;
        head = new LinkedNode(0);
    }


    int get(int index) {
        if(index<0 || index>=size){
            return -1;  
        }

        LinkedNode* cur = head;
        for(int i=0; i<=index;i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        index = max(0, index);
        size++;
        LinkedNode* prev = head;

        for(int i=0; i<index; i++){
            prev = prev->next;
        }

        LinkedNode* node = new LinkedNode(val);
        node->next = prev->next;
        prev->next = node;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size){
            return;
        }
        size--;

        LinkedNode* prev = head;
        for(int i=0; i<index; i++){
            prev = prev->next;
        }
        LinkedNode *p = prev->next;
        prev->next = prev->next->next;
        
        delete p;
    }

    void show(){
        LinkedNode* cur = head;
        for(;cur != nullptr;){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main(){
    MyLinkedList* temp;
    temp->addAtHead(1);
    temp->show();
    
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

/*
分析:

方法:

总结:

*/