#ifndef MEMTABLE_H
#define MEMTABLE_H


#include<iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
using std::string, std::vector;


class Node{
    public:
    string key;
    string val;
    int height;
    Node * left;
    Node * right;
    Node(string key, string value);
 };

class KVPair {
    public:
    string key;
    string val;
    KVPair(string key, string value);
    string getKey();
    string getValue();
    string printKVPair();
};



class Memtable{
    public:
    Node * root;
    int size;
    Memtable(Node * my_root, int num);
    int treeHeight(Node* root);
    int getHeight(Node * p);
    int getBalance(Node * root);
    int getNodeNum(Node *root);
    Node* putKV(Node *root, string key, string value);
    Node * l_rotate(Node* root);
    Node * r_rotate(Node * root);

    string getKV(Node* root, string key);


    void helperScan(Node *root, string small, string large, vector<KVPair>& result);


    vector<KVPair> scanKV(Node *root, string small, string large);

    void helperPurge(Node*root, vector<KVPair>& result);

    vector<KVPair> purge(Node* root);

   void printTree(Node *v);
    
    
    
};

#endif