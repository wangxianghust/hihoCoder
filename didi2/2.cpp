#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        vector<int> ret;
        ret.push_back(1);
        if(n == 1) return 1;
        for(int i=2; i<=n; ++i){
            int last = ret.back();
            int M2(0), M3(0), M5(0);
            for(int i : ret){
                if(i * 2 > last) {
                    M2 = 2 * i;
                    break;
                }
            }

            for(int i : ret){
                if(i * 3 > last) {
                    M3 = 3 * i;
                    break;
                }
            }
            
            for(int i : ret){
                if(i * 5 > last) {
                    M5 = 5 * i;
                    break;
                }
            }

            int next =  min(M2, min(M3, M5));
            ret.push_back(next);
        }
        return ret.back();
    }
};

int main(){
    Solution Sol;
    int n; cin >> n;
    int ret = Sol.nthUglyNumber(n);
    cout << ret << endl;
}
