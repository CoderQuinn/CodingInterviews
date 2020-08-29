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

        build_min_heap(arr);
        
        for (int i = 0; i < k; i++) {
            int val = arr[0];
            result.push_back(val);
            
            swap(arr[0], arr[heap_size_- 1]);
            heap_size_--;
            
            min_heapif(arr, 0);
            
        }
        return result;
    }
    
    void build_min_heap(vector<int>& arr) {
        heap_size_ = arr.size();
        
        // 从非叶结点开始调整
        for (int i = heap_size_ / 2 - 1; i >= 0; i--) {
            min_heapif(arr, i);
        }
    }
    
    void min_heapif(vector<int>& arr, int i) {
        int left = i * 2 + 1;
        int right = (i + 1) * 2;
        
        int min = i;
        
        if (left < heap_size_ && arr[left] < arr[min]) {
            min = left;
        }
        
        if (right < heap_size_ && arr[right] < arr[min]) {
            min = right;
        }
        
        if (min != i) {
            swap(arr[min], arr[i]);
            min_heapif(arr, min);
        }
    }
    
private:
    int heap_size_;
};
