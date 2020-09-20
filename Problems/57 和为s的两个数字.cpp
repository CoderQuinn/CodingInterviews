//
//  57 和为s的两个数字.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/20.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto size = nums.size();
        for(int i = 0; i < size; i++)
        {
            int x = target - nums[i];
            
            int left = 0, right = size - 1;
            while(left <= right)
            {
                int mid = left + right >> 1;
                if(nums[mid] == x && i != mid)
                    return {nums[i], x};
                else if(nums[mid] > x)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return {};
    }
};

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto size = nums.size() - 1;
        
        for(int i = 0, j = int(size); i < j; i++)
        {
            while (i < j && nums[i] + nums[j] > target) {
                j--;
            }
            
            if (i < j && nums[i] + nums[j] == target) {
                return {nums[i], nums[j]};
            }
        }
        
        return {};
    }
};
