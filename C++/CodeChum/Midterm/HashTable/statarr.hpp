#include <iostream>

using namespace std;

class StatArray {

    int n;
    string* arr;

    public:
    StatArray(){
        n = 0;
        arr = new string[5];
    }

    int add(string e){
        if(n >= 5){
            cout << "array is full" << endl;
            return -1;
        }
        arr[getIdx(0)] = e;
        return ++n;
    }

    int remove(string e){
        if(n <= 0){
            cout << "array is empty" << endl;
            return -1;
        }
        if(search(e)){
            arr[getIdx(1)] = "";
        }
        return --n;
    }

    int getIdx(int type){
        //find empty spot
        if(n >= 5){
            cout << "array is full" << endl;
            return -1;
        }
        for(int i = 0; i < 5; i++){
            if(arr[i] == "" && type == 0) return i;
            else if(arr[i] == "" && type == 1) return i;
            if(i == 5) i = 0;
        }
        return -1;
    }

    int search(string e){
        if(n <= 0){
            cout << "array is empty" << endl;
            return -1;
        }
        for(int i = 0; i < 5; i++){
            if(arr[i] == e){
                return n;
            }
        }
        return -1;
    }

    int getSize(){
        return n;
    }

    void print(){
        if(n > 0){
            for(int i = 0; i < 5; i++){
                cout << arr[i] + " ";
            }
        }
    }

};