class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size());    
    }
    
private:
    int solve(vector<int>& nums, int left, int right) {
        if (right - left == 1)
            return nums[left];
        int mid = left + (right - left) / 2;
        int globalMax = max(solve(nums, left, mid), solve(nums, mid, right));
        
        int leftMax = numeric_limits<int>::min();
        int leftSum = 0;
        for (int i = mid - 1; i >= left; i--) {
            leftSum += nums[i];
            leftMax = max(leftMax, leftSum);
        }
        
        int rightMax = numeric_limits<int>::min();
        int rightSum = 0;
        for (int i = mid; i < right; i++) {
            rightSum += nums[i];
            rightMax = max(rightMax, rightSum);
        }
        
        return max(globalMax, leftMax + rightMax);
    }
};
