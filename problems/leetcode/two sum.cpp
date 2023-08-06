// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

#include<bits/stdc++.h>
#include<vector>
#include<unordered_map>
#include<hash_map>


    vector<int> twoSum(vector<int>& nums, int target) {
     unordered_map<int,int> hashmap;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            
            if (hashMap.count(complement)) {
                result.push_back(hashMap[complement]);
                result.push_back(i);
                break;
        }
        hashmap[nums[i]]=i;}
    return result;
        }
