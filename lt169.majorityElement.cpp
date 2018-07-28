class Solution {
public:
    int majorityElement(vector<int>& nums) {
        assert(!nums.empty());
        return solve(nums, 0, nums.size());   
    }
    
private:
    int solve(vector<int>& nums, int low, int high) {
        if (1 == high - low) {
            return nums[low];
        }
        
     
        int mid = low + (high - low) / 2;
        int leftMod = solve(nums, low, mid);
        // Be careful, this must be [mid, high), NOT [mid + 1, high)
        // otherwise, the mid will never be countered!! we must count it 
        // either in the left or in the right
        int rightMod = solve(nums, mid, high);
        // left mod is equal right mod, then that number must be the majority num
        if (leftMod  == rightMod)
            return leftMod;
        
        int left = 0;
        int right = 0;
        for (auto num : nums) {
            if (num == leftMod)
                left++;
            else if (num == rightMod)
                right++;
        }
        
        // This is only valid under the assumption that the mod always exsit!!
        return left > right ? leftMod : rightMod;
    }
};
<<<<<<< HEAD


// Solution 2: use std::count to count (in <algorithm> header)
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            assert(!nums.empty());
            return solve(nums, 0, nums.size());   
        }

    private:
        int solve(vector<int>& nums, int low, int high) {
            if (1 == high - low) {
                return nums[low];
            }


            int mid = low + (high - low) / 2;
            int leftMod = solve(nums, low, mid);
            // Be careful, this must be [mid, high), NOT [mid + 1, high)
            // otherwise, the mid will never be countered!! we must count it 
            // either in the left or in the right
            int rightMod = solve(nums, mid, high);
            // left mod is equal right mod, then that number must be the majority num
            if (leftMod  == rightMod)
                return leftMod;

            int leftCnt = count(nums.begin() + low, nums.begin() + high, leftMod);
            int rightCnt = count(nums.begin() + low, nums.begin() + high, rightMod);
           
            // This is only valid under the assumption that the mod always exsit!!
            return leftCnt > rightCnt ? leftMod : rightMod;
        }
    };
=======
>>>>>>> d061a83a9d87612cd52b13dc9206db7ff26f8465
