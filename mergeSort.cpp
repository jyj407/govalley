#include<iostream>
#include<vector>
using namespace std;

void merge_sort(vector<int>& data, int start, int end) {
    int n = end - start;
    if (n == 1)
        return;
    
    // recursive sorting
    
   int mid = start + (n >> 1);
   merge_sort(data, start, mid); 
   merge_sort(data, mid, end); 

   // merging 
   vector<int> tmp(n, 0);
   int lptr = start;
   int rptr = mid;

   for (int i = 0; i < n; i++) {
      if (lptr == mid) // no more element in the left
          tmp[i] = data[rptr++];    
      else if (rptr == end) // no more element in the right
          tmp[i] = data[lptr++];    
      else if (data[lptr] < data[rptr]) // left < right, copy left
          tmp[i] = data[lptr++];
      else //  (data[lptr] >= data[rptr]) // left >= right, copy right 
          tmp[i] = data[rptr++];
   } 

   for (int i = 0; i < n && start < end; i++, start++) {
       data[start] = tmp[i];
   }
}



int main(void) {
    vector<int> nums = {5,4,3,2,1};
    merge_sort(nums, 0, nums.size());
    for (auto& num : nums)
        cout << "num= " << num << endl;
}
