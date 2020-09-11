//
//  33 verifyPostorder.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/9/9.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        auto size = postorder.size();
        return dfs(postorder, 0, int(size - 1));
    }
    
    bool dfs(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        
        int pivot = postorder[right];
        int i = left;
        while (i < right && postorder[i] < pivot) {
            i++;
        }
        
        for (int j = i; j < right; j++) {
            if (postorder[j] < pivot)
                return false;
        }
        
        return dfs(postorder, left, i - 1) && dfs(postorder, i, right - 1);
    }
};
