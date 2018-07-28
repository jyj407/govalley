// divide and conquer
// (1) 候选区间不为空
// (2) 目标值可能在候选区间中
// (3) 候选区间要严格变小且性质相同 （开闭性质）
// My solution
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int start = 0, end = nums.size();
//         while (start < end) {
//             int mid = start + (end - start) / 2;
//             if (nums[mid] == target)
//                 return mid;
//             // mid could equal end - 1 候选区间不为空
//             else if (nums[mid] <= nums[end - 1]) { // right sorted
//                 // target could be nums[end - 1]
//                 if (target > nums[mid] && target <= nums[end - 1]) { //(2) 目标值可能在候选区间中
//                     start = mid + 1; // 候选区间要严格变小且性质相同
//                 } else {
//                     end = mid; // 候选区间要严格变小且性质相同
//                 }
//             } else //if (nums[mid] >= nums[start]) { // left sorted
//                 // target could be nums[start]
//                 if (target >= nums[start] && target < nums[mid]) { // (2) 目标值可能在候选区间中
//                     end = mid; // 候选区间要严格变小且性质相同
//                 } else {
//                     start = mid + 1; // 候选区间要严格变小且性质相同
//                 }
//             }
        
//         return -1;
//     }
// };

// go valley solution
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while (start < end) {
            int mid = start + ((end - start) >> 1);
            if (nums[mid] == target)
                return mid;
            // mid could equal end - 1 候选区间不为空
            
            if (nums[mid] < nums[start]) { // right sorted
                // target could be nums[end - 1]
                if (target < nums[mid]|| target > nums[end - 1]) //(2) 目标值可能在候选区间中
                    end = mid; // 候选区间要严格变小且性质相同
                else
                    start = mid + 1; // 候选区间要严格变小且性质相同
            } else { //if (nums[mid] >= nums[start]) { // left sorted
                // target could be nums[start]
                if (target >= nums[mid] || target < nums[start]) // (2) 目标值可能在候选区间中
                    start = mid + 1; // 候选区间要严格变小且性质相同
                else
                    end = mid;
            }
        }
        
        return -1;
    }
};
