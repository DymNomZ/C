#include <cstdlib>
#include <iostream>
#include <cmath>
#include "hashtable.hpp"
#include "statarr.hpp"
using namespace std;

class HTSepChain : public HashTable {
    // IMPLEMENT ME
    int N;
    
    StatArray** table;
    
    public:
        HTSepChain(int N){
            this->N = N;
            table = (StatArray**)calloc(N, sizeof(StatArray*));
            for(int i = 0; i < N; i++){
                this->table[i] = new StatArray();
            }
        }
        
    int hash_code(string key){
        int code = 0;
        int len = key.length();
        for(int i = 0; i < len; i++){
            code += key[i] * pow(5, len-(i+1));
        }
        return code;
    }
    
    int compress(int code){
        return code % this->N;
    }
    
    int insert(string key){
        //search
        int hash = this->hashfn(key);
        if(search(key) >= 0){
            throw logic_error("Already added key " + key);
        }
        
        this->table[hash]->add(key);
        return this->table[hash]->getSize();
    }
    
    int search(string key){
        int hash = this->hashfn(key);
        
        if(this->table[hash]->getSize() <= 0 || !this->table[hash]->search(key)){
            return -1;
        }
        return this->table[hash]->getSize();
    }
    
    int remove(string key){
        int hash = this->hashfn(key);
        
        if(!this->table[hash]->search(key)) return -1;
        this->table[hash]->remove(key);
        return this->table[hash]->getSize();
    }
    
    void print(){
        for(int i = 0; i < N; i++){
            cout << i << "	";
            this->table[i]->print();
            cout << endl;
        }
        cout << endl;
    }

};