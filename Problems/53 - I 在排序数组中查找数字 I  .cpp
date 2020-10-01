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

class Solution1
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int i = 0, j = 0;

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        if(nums[l] != target) return 0;
        
        i = l;

        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid - 1;
        }
        j = r;

        return j - i + 1;
    }
};
