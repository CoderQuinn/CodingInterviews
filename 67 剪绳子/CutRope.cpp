//
//  CutRope.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/22.
//

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>    // std::max

// 数学推导法 https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/mian-shi-ti-14-i-jian-sheng-zi-tan-xin-si-xiang-by/
class Solution {
public:
    int cutRope(int number) {
        // assert(number >= 2)
        if (number <= 3) return number - 1;
        
        int x = number / 3;
        int y = number % 3;
        if (y == 1) {
            return pow(3, x-1) * 4;
        } else if (y == 2) {
            return pow(3, x) * 2;
        } else {
            return pow(3, x);
        }
    }
};


// 递归公式：f(n) = max(f(i) * f(n-i)); 参考：https://blog.nowcoder.net/n/a052345076e349abaf3e8dba4202d493?f=comment
class Solution2 {
public:
    int cutRope(int number) {
        if (number <= 0) return 0;
        else if (number <= 3) return number - 1;
        return cutPopeCore(number);
        
    }
    
    int cutPopeCore(int number) {
        if (number < 4) return number;
        
        int max = -1;
        for (int i = 1; i < number / 2 + 1; ++i) {
            max = std::max(max, cutPopeCore(i) * cutPopeCore(number - i));
        }
        
        return max;
    }
};

// 迭代
class Solution1 {
public:
    int cutRope(int number) {
        if (number <= 0) return 0;
        else if (number <= 3) return number - 1;
        
        std::vector<int> ret(number + 1, -1);
        ret[1] = 1;
        ret[2] = 2;
        ret[3] = 3;
        
        for (int i = 4; i <= number; ++i) {
            for (int j = 1; j < i / 2 + 1; ++j) {
                ret[i] = std::max(ret[i], ret[j] * ret[i - j]);
            }
        }
        
        return ret[number];
        
    }
};
