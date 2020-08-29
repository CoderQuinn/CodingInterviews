//
//  41 MedianFinder.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/26.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        max_heap = new priority_queue<int>();
        min_heap = new priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        if (max_heap->size() == min_heap->size()) { // 保证最大堆个数大于等于最小堆个数
            min_heap->push(num);
            max_heap->push(min_heap->top());
            min_heap->pop();
        } else {
            max_heap->push(num);
            min_heap->push(max_heap->top());
            max_heap->pop();
        }
    }
    
    double findMedian() {
        auto total = max_heap->size() + min_heap->size();

        if (total % 2) {
            return max_heap->top();
        } else {
            return (max_heap->top() + min_heap->top()) / 2.0;
        }
    }
    
private:
    priority_queue<int> *max_heap;
    priority_queue<int, vector<int>, greater<int>> *min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
