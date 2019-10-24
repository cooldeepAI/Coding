/*
 * Create by Yang Shuangzhen, on 2019/09/15
 *
 */

/**
 * 1. Two Sum
 *
 * Given an array of integers, find two numbers such that add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
 * are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define N 6

vector<int> twoSum(vector<int> &result){
    vector<int> nums = {2, 7, 11, 15, 16, 20};
    int target = 26;

    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    return result;
}

class Solution{
public:
    vector<int> twoSum(vector<int>& number, int target){
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i < number.size(); i++){
            if(m.find(number[i]) == m.end()){
                m[target - number[i]] = i;
            }
            else{
                result.push_back(m[number[i]] + 1);
                result.push_back(i+1);
                break;
            }
        }
    }
};

int main() {
    vector<int> result;
    twoSum(result);
    for(int i : result){
        cout << i << endl;
    }
}