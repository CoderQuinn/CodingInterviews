//
//  53 - I search.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int find_left(vector<int>& nums, int target) {
        int left = 0;
        auto size = nums.size();
        int right = int(size - 1);
        
        while (left < right) {
            int mid = (right + left >> 1);
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left < size && nums[left] == target) {
            return left;
        }
        return -1;
    }
    
    int find_right(vector<int>& nums, int target) {
        int left = 0;
        auto size = nums.size();
        int right = int(size - 1);
        
        while (left < right) {
            int mid = (right + 1 + left >> 1);
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        if (left < size && nums[left] == target) {
            return left;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int left = find_left(nums, target);
        int right = find_right(nums, target);
        
        int ans = 0;
        if (left != -1) {
            ans = right - left + 1;
        }
        
        return ans;
    }
};
