//
//  Fibonacci.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/22.
//
#include <stdio.h>

// Recursion
class Solution01 {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if (n < 2) return result[n];
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

class Solution {
public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if (n < 2) return result[n];
        
        int x = 0;
        int y = 1;
        int ret = 0;
        for (int i = 2; i <= n; ++i) {
            ret = x + y;
            x = y;
            y = ret;
        }
        
        return ret;
    }
};
