#include <vector>
#include <iostream>

using namespace std;

bool test(vector<int> &input){
    int size = input.size();
    int cnt_4 = 0; //multiple 4
    int cnt_odd = 0; //#odd
    bool ret = false;
    for(int i=0; i<size; ++i){
        if(input[i] % 4 == 0) ++cnt_4;
        if(input[i] % 2 != 0) ++cnt_odd;
    }
    if(cnt_4 + cnt_odd == size && cnt_odd == cnt_4 + 1) ret = true;
    if(cnt_4 >= cnt_odd) ret = true;
    return ret;
}

int main(){
    int total; cin >> total;
    vector<vector<int> > inputs(total);
    for(int i=0; i<total; ++i){
        int num; cin >> num;
        for(int j=0; j<num; ++j){
            int ele; cin >> ele;
            inputs[i].push_back(ele);
        }
    }
    for(auto input : inputs){
        bool ret = test(input);
        cout << (ret == true ? "Yes" : "No") << endl;
    }
}
