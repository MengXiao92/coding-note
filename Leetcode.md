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
```
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
```
问题:<br>
1.掌握哈希表的基本语法<br>
2.哈希表中count和find的区别<br>

问题：解数独<br>
```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int flag[10];
        for(int i = 0; i < 9; i++){
            memset(flag,0,sizeof(int)*9);
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.'){
                    if(flag[board[i][j]-'1'])// 判断行有没有重复
                        return false;
                    flag[board[i][j]-'1'] = 1;
                }
            }
        }
        
        for(int i = 0; i < 9; i++){
            memset(flag,0,sizeof(int)*9);
            for(int j = 0; j < 9; j++){
                if(board[j][i]!='.'){
                    if(flag[board[j][i]-'1'])// 判断列有没有重复
                        return false;
                    flag[board[j][i]-'1'] = 1;
                }
            }
        }
        
        for(int i = 0; i < 9; i++){
            memset(flag,0,sizeof(int)*9);
            for(int j = 0; j < 9; j++){
                int cubeX = 3*(i/3)+j/3;
                int cubeY = 3*(i%3)+j%3;
                if(board[cubeX][cubeY]!='.'){
                    if(flag[board[cubeX][cubeY]-'1'])// 判断宫有没有重复
                        return false;
                    flag[board[cubeX][cubeY]-'1'] = 1;
                }
            }
        }
        return true;
    }
};
```
问题：组合之和<br>
```c++
class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp;
    void dfs(int index, int sum, int target, vector<int>& candidates){
        if(index == candidates.size()){
            if(sum == target)
                results.push_back(temp);
            return;
        }
        int c = candidates[index];
        if(index == candidates.size()-1){
            if((target - sum) % c==0){
                for(int i = 0; i < (target - sum)/c; i++){
                    temp.push_back(c);
                }
                results.push_back(temp);
            }
        }else{
            for(;;){
                dfs(index+1,sum,target,candidates);
                sum+=c;
                temp.push_back(c);
                if(sum>target)
                    break;
            }
        }
        while(temp.size()>0 && temp[temp.size()-1]==c)
            temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0,0,target,candidates);
        return results;
    }
};
```
问题:组合之和II<br>
```c++
class Solution {
public:
    vector<vector<int>> results;
    vector<int> temp;
    void dfs(int index,int sum,int target, vector<int>& c){
        if(index == c.size()){
            if(sum == target)
                results.push_back(temp);
            return;
        }
        int i = index;
        for(;i+1 < c.size() && c[i+1] == c[index]; i++);
        int total = i - index + 1;
        for(int j = 0; j <= total; j++){
            dfs(index+total,sum,target,c);
            sum += c[index];
            temp.push_back(c[index]);
            if(target < sum)
                break;
        }
        while(temp.size()>0 && temp[temp.size()-1]==c[index])
            temp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,0,target,candidates);
        return results;
    }
};
```
