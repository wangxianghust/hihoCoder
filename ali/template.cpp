#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("test.txt", "r", stdin);
    int total;
    cin >> total;
    for(int i=0; i<total; ++i){
        int size; cin >> size;
        vector<string> strs;
        for(int j=0; j<size; ++j){
            string s; cin >> s;
            strs.push_back(s);
        }
    }
}

树的遍历
https://github.com/wangxianghust/CLRS/blob/master/10/Tree.cpp

Huffman coding
https://github.com/wangxianghust/CLRS/blob/master/16/Huffman.cpp
