//
//  11 minArray.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyr © 2020 QuinnYoung. All rs reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(0 < r && nums[0] == nums[r]) --r;
        if (nums[0] <= nums[r]) return nums[0];
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[0]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return nums[l];
    }
};
