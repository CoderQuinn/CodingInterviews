//
//  62 lastRemaining.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/28.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    int lastRemaining(int n, int m) {
        if(n == 1)  return 0;
        
        return (lastRemaining(n - 1, m) + m) % n;
    }
};
