//
//  40 getLeastNumbers.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
#include <queue>
using namespace std;

// using stl
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
        if (arr.empty() || k == 0) {
            return result;
        }
        
        priority_queue<int> max_heap;
        for (int i = 0; i < arr.size(); ++i) {
            if (i < k) {
                max_heap.push(arr[i]);
            } else if(max_heap.top() > arr[i]) {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }
        
        while (!max_heap.empty()) {
            int num = max_heap.top();
            max_heap.pop();
            result.push_back(num);
        }
        return result;
    }
};

class Solution1 {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result;
  
        return result;
    }
    
    void build_max_heap(vector<int>& arr) {
        
    }
    
private:
    int heap_size_;
};
