#include <iostream>

using namespace std;

int main(){
    long long x, f, d, p;
    cin >> x;
    cin >> f; 
    cin >> d;
    cin >> p;
    long long ret = 0;
    int day_for_room = d/x;
    if(day_for_room >= f){
        long long d_rest = d - x*f;
        ret = f + d_rest/(p+x);
    } else {
        ret = d/x;
    }
    cout << ret << endl;
    return 0;
}
