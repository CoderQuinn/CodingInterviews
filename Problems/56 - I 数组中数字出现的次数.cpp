//
//  56 - I 数组中数字出现的次数.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums)
        {
            sum ^= num;
        }
        int k = 0;
        while(!(sum >> k & 1)) k++;

        int num1 = 0;
        for(auto num : nums)
        {
            if(num >> k & 1)
                num1 ^= num;
        }

        int num2 = sum ^ num1;

        return {num1, num2};
    }
};
