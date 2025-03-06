#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> look_up;

int fib(int n){

    if(n <= 1) {
        return n;
    }

    if(look_up.find(n) != look_up.end()) return look_up[n];

    int res = fib(n - 1) + fib(n - 2);
    look_up[n] = res;
    return res;
}

int main(){

    int x, c = 1;

    while(c != 10){
        cout << "Input: ";
        cin >> x;
        cout << fib(x) << endl;
        c++;
    }

    return 0;

}