//
//  51 reversePairs.cpp
//  Leetcode-CodingInterviews
//
//  Created by Quinn on 2020/8/18.
//  Copyright © 2020 QuinnYoung. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> tmp_arr;
    int result;
    int reversePairs(vector<int>& nums) {
        result = 0;
        tmp_arr.assign(nums.size(), 0);

        long right = nums.size() - 1;
        count_smaller_helper(nums, 0, int(right));
        
        tmp_arr.clear();
        return result;
    }
    void count_smaller_helper(vector<int>& nums, int left, int right) {
        
        if (left < right) {
            int mid = (right + left) / 2 ;
            count_smaller_helper(nums, left, mid);
            count_smaller_helper(nums, mid + 1, right);
            merge_pass(nums, left, mid, right);
        }
        
    }
    
    void merge_pass(vector<int>& arr, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp_arr[i] = arr[i];
        }
        
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (tmp_arr[i] <= tmp_arr[j]) {
                arr[k++] = tmp_arr[i++];
            } else {
                result += mid - i + 1;
                arr[k++] = tmp_arr[j++];
            }
        }
        
        while (i <= mid) {
            arr[k++] = tmp_arr[i++];
        }
        
        while (j <= right) {
            arr[k++] = tmp_arr[j++];
        }
    
    }
};

class Solution1 {
public:
    vector<int> tmp_arr;
    int result;
    int reversePairs(vector<int>& nums) {
        result = 0;
        tmp_arr.assign(nums.size(), 0);

        long right = nums.size() - 1;
        count_smaller_helper(nums, 0, int(right));
        
        tmp_arr.clear();
        return result;
    }
    void count_smaller_helper(vector<int>& nums, int left, int right) {
        
        if (left < right) {
            int mid = (right + left) / 2 ;
            count_smaller_helper(nums, left, mid);
            count_smaller_helper(nums, mid + 1, right);
            merge_pass(nums, left, mid, right);
        }
        
    }
    
    void merge_pass(vector<int>& arr, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp_arr[i] = arr[i];
        }
        
        int i = left;
        int j = mid + 1;
        int k = left;
        while (i <= mid && j <= right) {
            if (tmp_arr[i] <= tmp_arr[j]) {
                arr[k++] = tmp_arr[i++];
                result += j - mid - 1;
            } else {
                arr[k++] = tmp_arr[j++];
            }
        }
        
        while (i <= mid) {
            arr[k++] = tmp_arr[i++];
            result += j - mid - 1;
        }
        
        while (j <= right) {
            arr[k++] = tmp_arr[j++];
        }
    
    }
};
