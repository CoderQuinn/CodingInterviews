//
//  LastRemaining.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/16.
//

#include <stdio.h>

// 约瑟夫环, 递归法
class Solution1 {
public:
    int lastRemaining(int n, int m) {
        if (n == 1) return 0;
        
        return (lastRemaining(n-1, m) + m) % n;
    }
};

// 约瑟夫环, 迭代法
class Solution2 {
public:
    int lastRemaining(int n, int m) {
        if (n <= 0 || m <= 0) return -1;
        int last = 0; // 即f(1) = 0
        
        for (int i = 2; i <= n; ++i) {
            last = (last + m) % i; // f(2) = (f(1) + m) % 2
        }
        
        return last;
    }
};
