//
//  14 - II cuttingRope.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    typedef unsigned long long ULL;
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;
        int mod = 1e9 + 7;
        ULL res = 1;
        
        if (n % 3 == 1) {
            res = 4;
            n -= 4;
        } else if(n % 3 == 2) {
            res = 2;
            n -= 2;
        }
        
        int k = n / 3;
        
        res = res * qmi(3, k, mod) % mod;
        
        return (int)res;
    }
    
    ULL qmi(int a, int k, int p)
    {
        ULL res = 1;
        ULL x = a;
        
        while (k) {
            if (1 & k) {
                res = res * x % p;
            }
            k = k >> 1;
            x = x * x % p;
        }
        return res;
    }
};
