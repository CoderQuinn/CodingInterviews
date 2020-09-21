//
//  65 不用加减乘除做加法.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int add(int a, int b) {
        while(b)
        {
            int sum = a ^ b;
            unsigned int carry = a & b;
            carry <<= 1;

            a = sum;
            b = carry;
        }
        return a;
    }
};
