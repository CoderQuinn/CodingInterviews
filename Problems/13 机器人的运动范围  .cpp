//
//  13 movingCount.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/8.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int get_number(int num) {
        int res = 0;
        while (num) {
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> state(m, vector<bool>(n));
        state[0][0] = true;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        int res = 1;
        
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int x = top.first + dx[i];
                int y = top.second + dy[i];
                int target = get_number(x) + get_number(y);
                
                if (x >= 0 && x < m && y >= 0 && y < n && !state[x][y] && target <= k) {
                    q.push({x, y});
                    state[x][y] = true;
                    res++;
                }
            }
        }
        
        return res;
    }
};
