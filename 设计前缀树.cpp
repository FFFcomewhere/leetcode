#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;


class Trie {
private:
    bool flag;  //是否为某个单词的结尾
    Trie* next[26] = {nullptr};


public:
    Trie() {
        flag = false;
    }
    
    void insert(string word) {
        //从根节点插入
        Trie* node = this;
        for(auto e:word){
            if(node->next[e-'a'] == nullptr){
                //新建节点
                node->next[e-'a'] = new Trie();
            }
            node = node->next[e-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto e:word){
            if(node->next[e-'a'] == nullptr){
                return false;
            }
            node = node->next[e-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto e:prefix){
            if(node->next[e-'a'] == nullptr){
                return false;
            }
            node = node->next[e-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


/*
分析:

方法:

总结:

*/