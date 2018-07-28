# coding-note
some note for my coding
剑指offer
1.二维数组中的查找
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
```c++
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())  return false;
        int rowLength = array.size();
        int colLength = array[0].size();
        for(int i = rowLength -1; i >= 0; i--){
            if(array[i].empty()) continue;
            if(target >= array[i][0]){
                for(int j = 0; j < colLength; j++){
                    if(target == array[i][j]){
                        return true;
                    }else if(target > array[i][j]){
                        continue;
                    }else{
                        break;
                    }
                }
            }
            else continue;
        }
        return false;
    }
};
```
2.替换空格
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
```c++
class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str==NULL || length <= 0) return ;
        int strLength = 0;
        int spaceNum = 0;
        int i = 0;
        while(str[i] != '\0'){
            ++strLength;
            if(str[i] == ' ')
                ++spaceNum;
            ++i;
        }
        int newStrLength = strLength + spaceNum * 2;
        if(newStrLength > length) return ;
        int indexStr = strLength;
        int newIndexStr = newStrLength;
        
        while(indexStr>=0 && newIndexStr >= indexStr){
            if(str[indexStr] == ' '){
                str[newIndexStr--] = '0';
                str[newIndexStr--] = '2';
                str[newIndexStr--] = '%';
            }
            else{
                str[newIndexStr--] = str[indexStr];
            }
            --indexStr;
        }
    }
};
```

3.从尾到头打印链表
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> temp;
        vector<int> result;
        while(head != NULL){
            temp.push_back(head->val);
            head = head->next;
        }
        int size = temp.size();
        for(int i = 0; i < size; i++){
            result.push_back(temp[size - 1 - i]);
        }
        return result;
    }
};
```
