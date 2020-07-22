//
//  jumpFloor.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/22.
//
#include <stdio.h>

class Solution {
public:
    int jumpFloor(int number) {
        if (number == 1) return 1;
        else if(number == 2) return 2;
        
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};
