//
//  45 把数组排成最小的数.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(int a, int b) // 可排序：1.反对称性 2.传递性
    {
        string s1 = to_string(a), s2 = to_string(b);
        return s1 + s2 < s2 + s1;
    }

    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);

        string s;
        for(auto num : nums)
        {
            s += to_string(num);
        }
        
        return s;
    }
};
