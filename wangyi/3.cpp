#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> students(n, 0);
    deque<int> ret;
    for(int i=0; i<n; ++i) cin >> students[i];
    sort(students.begin(), students.end());

    int start(0), end(n-1);
    ret.push_back(students[end]);
    ret.push_back(students[start]);
    
    bool select_form_big = true;
    while(start < end){
        int front = ret.front();
        int back = ret.back();
        int next(0);
        if(select_form_big){
            if(end-1 > start)next = students[--end];   
            else break;
        } else {
            if(start+1 < end)next = students[++start];
            else break;
        }
        select_form_big = !select_form_big;
        if(abs(front - next) > abs(next - back)){
                ret.push_front(next);
            } else {
                ret.push_back(next);
            }
    }

    long long dif = 0;
    for(int i=0; i<n-1; ++i){
        dif += abs(ret[i+1] - ret[i]);
    }
    cout << dif << endl; 
    return 0;
}

