//
//  63 maxProfit.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/31.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min_price = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        return ans;
    }
};
