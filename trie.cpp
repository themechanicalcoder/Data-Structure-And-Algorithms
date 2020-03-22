#include<bits/stdc++.h>
using namespace std;

class Trie{
private:
    unordered_map<char,Trie*>next={};
    bool isword;
public:
    Trie(){};
    void insert(string word){
        Trie* node=this;
        for(char c:word){
            if(!node->next.count(c)){node->next[c]=new Trie();}
            node=node->next[c];
        }
    node->isword=true;
    }
    bool search(string word){
        Trie* node=this;
        for(char c:word){
            if(!node->next.count(c)){return false;}
            node=node->next[c];
        }
        return node->isword;
    }
    bool startswith(string prefix){
        Trie* node=this;
        for(char c:prefix){
            if(!node->next.count(c))return false;
            node=node->next[c];
        }
    return true;
    }


};


int main(){
    Trie obj;

    obj.insert("abcd");
    cout<<obj.search("abc");
    cout<<obj.startswith("abc");

}
