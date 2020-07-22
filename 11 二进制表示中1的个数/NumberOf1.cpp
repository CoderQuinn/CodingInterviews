//
//  NumberOf1.cpp
//  CodingInterviews
//
//  Created by Quinn on 2020/7/22.
//

#include <stdio.h>

class Solution1 {
public:
     int  NumberOf1(int n) {
         int k = 1;
         int ret = 0;
         while (k) {
             if (k & n) ret ++ ;
             k = k << 1;
         }
         return ret;

     }
};

// 补码性质
class Solution2 {
public:
     int  NumberOf1(int n) {
         int ret = 0;
         while (n) {
             ret ++ ;
             n = (n - 1) & n;
         }
         return ret;

     }
};

