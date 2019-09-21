#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Time    : 2019-09-19 17:38
# @Author  : Yang Shuangzhen
# @File    : 1_twoSum.py

import time


class Solution(object):
    def __init__(self, nums, target):
        self.nums = nums
        self.target = target

    def __len__(self):
        return len(self.nums)

    def twoLoop(self):
        '''
        How to search two nums?

        1. For every number, judge the rest of number list.
        2. Return two index.

        Time: O(n^2)
        Space: O(n)
        :return:
        '''
        for i in range(len(self.nums)):
            left = self.nums[i+1:]
            for j in range(len(left)):
                if(self.nums[i] + left[j] == self.target):
                    return i, j+i+1

    def oneLoop(self):
        '''

        :return:
        '''
        k = 0
        for i in nums:
            k = k + 1     # the first and second index
            if target - i in nums[k:]:
                return (k - 1, nums[k:].index(target - i ) + k)

    def hashTable(self):
        '''

        How to search two index?

        1. Create hash table for number list, the key is number, value is index.
        2. Look every index i, suppose current index is the first index, judge (target - nums[i])
        in hash table, and first index is not equal to second equal which not find the same number.

        Time:
        :return:
        '''
        hash_table = {}
        for i in range(len(self.nums)):
            hash_table[nums[i]] = i    # key:value ---> num:index

        for i in range(len(nums)):
            if self.target - nums[i] in hash_table:
                if hash_table[self.target-nums[i]] != i:
                    return i, hash_table[target-nums[i]]

    def onePassHashTable(self):
        '''
        How to search two index？

        Get a number iteratively, and judge the second number in hash table , if not,create hash table at the same time
        :return:
        '''
        hash_table = {}
        for i, num in enumerate(self.nums):
            if target - num in hash_table:
                return hash_table[target-num], i
            hash_table[num] = i


if __name__ == '__main__':
    nums = [2, 4, 5, 7, 10, 13]
    target = 7
    solution = Solution(nums, target)

    start_time = time.time()
    twoLoop_result = solution.twoLoop()
    end_time = time.time()
    twoLoop_time = end_time - start_time

    start_time = time.time()
    oneLoop_result = solution.oneLoop()
    end_time = time.time()
    oneLoop_time = end_time - start_time

    start_time = time.time()
    hashTable_result = solution.hashTable()
    end_time = time.time()
    hashTable_time = end_time - start_time

    start_time = time.time()
    onePassHashTable_result = solution.onePassHashTable()
    end_time = time.time()
    onePassHashTable_time = end_time - start_time

    print('1. twoLoop result: {}, time: {}'.format(twoLoop_result, twoLoop_time))
    print('2. oneLoop result: {}, time: {}'.format(oneLoop_result, oneLoop_time))
    print('3. hashTable result: {}, time: {}'.format(hashTable_result, hashTable_time))
    print('4. onePassHashTable result: {}, time: {}'.format(onePassHashTable_result, onePassHashTable_time))
