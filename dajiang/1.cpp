/*
 * 题目描述：
给出n(n < 1000)个数，求任意两个数之间二进制表示位数不同的数量之和。
 * 输入
0  <= n < 32767。输入首先为n，然后跟随n个整数，范围为[0, 4294967295]
输出
组合数量
 *
 *
 */

/*As for an integer(32bits), visit every bit, find num of 1 is x, num of 0 is y
 *then x*y is different bits num of this bit.
 * use 32 iteration is ok.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        long long getDifBitSum(vector<long long> &nums){
            int size = nums.size();
            long long ret = 0;
            if(size == 0) return 0;
            for(int i=0; i<64; ++i){
                int num_of_one = 0;
                for(int j=0; j<size; ++j){
                    if( (nums[j] >> i)&0x1 ) ++num_of_one;
                }
                long long this_bit_sum = num_of_one * (size - num_of_one);
                ret += this_bit_sum;
            }
            return ret;
        }
};

int main(){
    Solution Sol;
    //freopen("1.txt", "r", stdin);
    int total;
    cin >> total;
    vector<long long> nums(total);
    for(int i=0; i<total; ++i) cin >> nums[i];
    long long ret = Sol.getDifBitSum(nums);
    cout << ret << endl;
}


