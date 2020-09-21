#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        auto l = str.length();
        int i = 0;
        while (i < l && str[i] == ' ') {
            i++;
        }
        
        if (i == l) return 0;
        
        int sign = 1;
        int res = 0;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        
        if (isdigit(str[i])) {
            while (i < l && isdigit(str[i])) {
                int val = str[i] - '0';
                if (sign > 0) {
                    if((INT_MAX - val) / 10 < res || INT_MAX - val == res * 10)
                        return INT_MAX;
                } else {
                    if((INT_MIN + val) / 10 > -res || -res * 10 == INT_MIN + val )
                        return INT_MIN;
                }
                
                res = res * 10 + val;
                i++;
            }
        }
        
        return res * sign;
    }
};
