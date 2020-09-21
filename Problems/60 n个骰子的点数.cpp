//
//  60 n个骰子的点数.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/20.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

// 暴力递归
class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        double sum = 0;
        for (int i = n; i <= n * 6; i++) {
            int count = dfs(n, i);
            sum += count;
            res.push_back(count);
        }
        
        for (auto &num : res) {
            num = num / sum;
        }
        
        return res;
    }
    
    int dfs(int n, int sum)
    {
        if (sum < 0) return 0;
        if (n == 0) {
            return sum == 0;
        }
        
        int res = 0;
        
        for (int i = 1; i <= 6; i++) {
            res += dfs(n - 1, sum - i);
        }
        
        return res;
    }
};

// 动态规划
class Solution1 {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        vector<vector<int>> f(n + 1, vector<int>(n * 6 + 1));
        f[0][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i * 6; j++) {
                for (int k = 1; k <= 6; k++) {
                    if (j >= k) {
                        f[i][j] += f[i - 1][j - k];
                    }
                }
            }
        }
        
        int sum = 0;
        for (int i = n; i <= 6 * n; i++) {
            auto &v = f[n][i];
            sum += v;
            res.push_back(v);
        }
        
        for (auto &num : res) {
            num = num / sum;
        }
        
        return res;
    }
    
};
