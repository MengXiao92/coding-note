Leetcode<br>
两数之和<br>
方法1<br>
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2,0);
        int len = nums.size();
        map<int,int> hash_nums;
        for(int i = 0; i < len; i++){
            hash_nums[nums[i]] = i;
        }
        for(int j = 0; j < len; j++){
            int component = target - nums[j];
            if((hash_nums.count(component))!=0 && hash_nums[component] != j)
            {
                results[0] = j;
                results[1] = hash_nums[component];
                break;
            }
        }
        return results;
    }
};
