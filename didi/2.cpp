#include <iostream>
#include <vector>

using namespace std;


class Solution { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};

int main(){
    Solution Sol;
    vector<int> nums;
    while(1){
    	int c;
        if(cin >> c) nums.push_back(c);
        else break;
    }

    vector<int> arrays(nums.begin(), nums.end()-1);
    int k = nums.back();

    int ret = Sol.findKthLargest(arrays, k);
    cout << ret << endl;
}
