//
//  JumpFloorII.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/22.
//

#include <stdio.h>

class Solution {
public:
    int jumpFloor(int number) {
        // assert(number > 0);
        if(number == 1) return 1;
        
        int ret = 1;
        for (int i = 2; i <= number; ++i) {
            ret = ret << 1; // 左移要比乘法快
        }
        return ret;
    }
};
