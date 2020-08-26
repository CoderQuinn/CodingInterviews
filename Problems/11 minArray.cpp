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
