#include <bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int size;
    map<int, Node*>mp;
    
    LRUCache(int capacity)
    {
        // Write your code here
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* delNode){
        Node* prev = delNode->prev;
        Node* next = delNode->next;
        
        prev->next = next;
        next->prev = prev;
        
    }
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }
    
    int get(int key) {
        
        if(mp.find(key)!=mp.end()){
            Node* lastUsed = mp[key];
            mp.erase(key);
            deleteNode(lastUsed);
            addNode(lastUsed);
            mp[key] = head->next;
            
            return lastUsed->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            Node* existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        if(mp.size()==size){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        Node* node = new Node(key,value);
        addNode(node);
        mp[key] = head->next;
    }
};
