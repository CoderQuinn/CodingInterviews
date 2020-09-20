//
//  44 数字序列中某一位的数字.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int findNthDigit(int n) {
        long i = 1, s = 9, base = 1; //i表示是几位数，s表示几位数共有多少个，base表示几位数的起始值
        while(n >= i * s)
        {
            n -= i * s;
            i++;
            s *= 10;
            base *= 10;
        }
        long number = base + (n + i - 1) / i - 1;
        int j = n % i ? n % i : i; // 该数的第几位，余0为最后一位即i
        for(int k = j + 1; k <= i; k++) number /= 10; // 删掉r之后的所有位
        return number % 10;
    }
};
