Leetcode<br>
两数之和<br>
方法1:暴力搜索<br>
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2,0);
        int len = nums.size();
        //if(len < 2)
        //    return NULL;
        for(int i = 0; i < len -1; i++){
            for(int j = i+1; j < len; j++){
                if(nums[i] + nums[j] == target){
                    results[0] = i;
                    results[1] = j;
                    //break;
                }
                else continue;
            }
        }
        return results;
    }
};
方法2:哈希表<br>
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
问题:<br>
1.掌握哈希表的基本语法<br>
2.哈希表中count和find的区别<br>
