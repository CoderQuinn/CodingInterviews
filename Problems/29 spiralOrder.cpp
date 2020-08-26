//
//  29 spiralOrder.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if (matrix.size() == 0) {
            return ans;
        }
        auto rows = matrix.size();
        auto cols = matrix.front().size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<int> step_x = {0, 1, 0, -1};
        vector<int> step_y = {1, 0, -1, 0};
        
        int i = 0, j = 0, n = 0;
        for (int k = 0; k < rows * cols; k++) {
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;
            
            i += step_x[n];
            j += step_y[n];

            if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j]) {
                i -= step_x[n];
                j -= step_y[n];
                
                n = (n + 1) % 4;
                
                i += step_x[n];
                j += step_y[n];
            }
        }
        return ans;
    }
};
