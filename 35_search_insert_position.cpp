// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = 0;
        for(auto n : nums) {
            if(n < target) {
                idx++;
            } else {
                break;
            }
        }
        return idx; 
    }
};