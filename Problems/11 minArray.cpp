//
//  11 minArray.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = int(numbers.size() - 1);
        
        while (left < right) {
            int mid = left + (right - left >> 1);
            if (numbers[mid] == numbers[right]) {
                right--;
            }
            else if (numbers[mid] < numbers[right]) { // 右边有序
                right = mid;
            }
            else { // 左边有序
                left = mid + 1;
            }
        }
        
        return numbers[left];
    }
};

class Solution1 {
public:
    int minArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right && nums[left] == nums[right]) --right;

        if (nums[left] <= nums[right]) return nums[left];
        
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < nums[0]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return nums[left];
    }
};
