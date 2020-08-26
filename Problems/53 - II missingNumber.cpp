//
//  53 - II missingNumber.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        auto size = nums.size();
        int left = 0;
        int right = int(size - 1);
        
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (nums[mid] > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if(left == size - 1 && left == nums[size - 1])
            left = size;
        
        return left;
    }
};
