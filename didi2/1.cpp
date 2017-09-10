#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
    public:
        //calculate one by one, when we get 0 or some value have seen is down.
        long getMaxK(vector<long> &nums){
            long size = nums.size();
            long ret = 0;
            unordered_set<long> seen;
            seen.insert(0);
            long val_before_now = 0;
            for(long i=0; i<size; ++i){
                long now = nums[i];
                if(seen.find(now ^ val_before_now) != seen.end()){
                    ++ret;
                    //update
                    seen.clear();
                    seen.insert(0);
                    val_before_now = 0;
                    continue;
                }
                val_before_now = val_before_now ^ now;
                seen.insert(val_before_now);
            }
            return ret;
        }
};

int main(){
    Solution Sol;
    long n; cin >> n;
    vector<long> nums(n);
    for(long i=0; i<n; ++i) {
        long c; cin >> c;
        nums[i] = c;
    }
    long ret = Sol.getMaxK(nums);
    cout << ret << endl;
    return 0;
}

