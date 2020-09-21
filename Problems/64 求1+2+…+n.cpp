//
//  64 求1+2+…+n.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/21.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int sumNums(int n) {
        int res = n;
        n > 0 && (res += sumNums(n - 1));
        return res;
    }
};
