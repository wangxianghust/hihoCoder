#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> input(n,0);
    vector<int> output(n,0);
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    if(n & 0x1){
        //n is odd
        int j = 0;
        for(int i=n-1; i >= 0; i -= 2){
            output[j++] = input[i];
        }
        for(int i=1; i <= n-2; i += 2){
            output[j++] = input[i];
        }
    } else {
        // n is even
        int j = 0;
        for(int i=n-1; i >= 1; i -= 2){
            output[j++] = input[i];
        }
        for(int i=0; i <= n-2; i += 2){
            output[j++] = input[i];
        }
    }
    for(int i=0; i < output.size(); ++i){
        cout << output[i] << " ";
    }
    return 0;
}
