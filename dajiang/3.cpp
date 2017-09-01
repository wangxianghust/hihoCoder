#include <iostream>
#include <string>

using namespace std;

long work(string &input){
    int size = input.size();
    //int num_d = 0;
    int num_i = 0;
    long ret = 0;
    for(int i=0; i<size; ++i){
        if(input[i] != 'd') continue;
        for(int j=i+1; j<size; ++j){
            if(input[j] != 'j') continue;
            for(int k=j+1; k<size; ++k){
                if(input[k] == 'i') ++num_i; 
            }
            ret += num_i;
            num_i = 0;
        }
    }
    return ret;
}

int main(){
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        string input;
        cin >> input;
        cout << work(input) << endl;
    }
}
