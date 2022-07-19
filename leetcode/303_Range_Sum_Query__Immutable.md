# 303. Range Sum Query - Immutable
https://leetcode.com/problems/range-sum-query-immutable/

```c++
class NumArray {
    vector<int> pref; // using prefix sum 
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) pref.push_back(nums[0]);
            else{
                int res = pref[i - 1] + nums[i];
                pref.push_back(res);
            }    
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return pref[right];
        return pref[right] - pref[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
```