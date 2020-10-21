//
//  04 findNumberIn2DArray.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
    
        int row = matrix.size();
        int col = matrix.front().size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
