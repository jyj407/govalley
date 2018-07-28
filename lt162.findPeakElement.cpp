// divide and conquer
// (1) 候选区间不为空
// (2) 目标值可能在候选区间中
// (3) 候选区间要严格变小且性质相同 （开闭性质）
// go valley idea num[mid] 比左右都大，返回mid
// 比左边大比右边小，low = mid + 1
// 比右边大比左边小， high = mid
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ((mid == low || nums[mid] > nums[mid - 1]) && 
                (mid == high - 1 || nums[mid] > nums[mid + 1]))
                return mid;
            
            // mid > 0 ensure the candidate interval is NOT empty
            if (mid > 0 && nums[mid - 1] > nums[mid])
                high = mid;
            else
                low = mid + 1;
        }
        
        return -1;
    }
};

// go valley Yixuan Liu
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int low = 0, high = nums.size() - 1;
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if (nums[mid] < nums[mid + 1])
//                 low = mid + 1;
//             else
//                 high = mid; // mid could be peak
//         }
        
//         // return either high or low in the end, they are both point to the peak
//         return high;
//     }
// };

// My solution based on go valley soultion 1
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int low = 0, high = nums.size();
//         while (low < high) {
//             int mid = low + (high - low) / 2;
//             if ((mid == low || nums[mid] > nums[mid - 1]) && 
//                 (mid == high - 1 || nums[mid] > nums[mid + 1]))
//                 return mid;
//             else if ((mid == low || nums[mid] > nums[mid - 1]) &&
//                      (mid != high - 1 && nums[mid] < nums[mid + 1]))
//                 low = mid + 1;
//             else
//                 high = mid;
//         }
        
//         return -1;
//     }
// };

