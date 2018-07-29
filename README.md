# coding-note
## 剑指offer<br>
1.二维数组中的查找<br>
题目描述<br>
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。<br>
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
2.替换空格<br>
题目描述<br>
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。<br>
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

3.从尾到头打印链表<br>
题目描述<br>
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。<br>
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
4.重建二叉树<br>
题目描述<br>
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int preLength = pre.size();
        int vinLength = vin.size();
        if(preLength <=0 || vinLength <= 0)
            return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        // 找到根节点在中序遍历中的位置，中序遍历的根节点的左边都是左子树，右边都是右子树
        int rootPosInVin = 0;
        for(int i = 0; i < vinLength; i++){
            if(vin[i] == pre[0]){
                rootPosInVin = i;
                break;
            }
        }
        // 左子树 && 右子树
        vector<int> preLeft,preRight,vinLeft,vinRight;
        // 找到左子树
        for(int i = 0; i < rootPosInVin; i++){
            preLeft.push_back(pre[i + 1]);  //前序遍历的左子树，第一个是根节点
            vinLeft.push_back(vin[i]);      //中序遍历的左子树
        }
        // 找到右子树
        for(int i = rootPosInVin + 1; i < vinLength; i++){
            preRight.push_back(pre[i]);
            vinRight.push_back(vin[i]);
        }
        // 递归
        root->left = reConstructBinaryTree(preLeft,vinLeft);
        root->right = reConstructBinaryTree(preRight,vinRight);
        
        return root;
    }
};
```
5.用两个栈实现一个队列<br>
题目描述<br>
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。<br>
解题思路<br>
1.入队：直接将元素进栈stack1
2.出队：判断栈stack2是否为空，将栈stack1中的元素pop出，依次进栈stack2。将stack2中的栈顶pop出
```c++
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int a;
        if(stack2.empty()){
            while(!stack1.empty()){
                a = stack1.top();
                stack2.push(a);
                stack1.pop();
            }
        }
        a = stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```
6.旋转数组的最小数字<br>
题目描述<br>
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。<br>
1. 普通方法<br>
```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int target = 65535;
        if(!rotateArray.empty()){
            for(int i = 0; i < rotateArray.size(); i++){
                if(target > rotateArray[i]){
                    target = rotateArray[i];
                }
            }
        }
        else return 0;
        
        return target;
    }
};
```
2.优化<br>
```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int target = 0;
        if(!rotateArray.empty()){
            for(int i = 0; i < rotateArray.size() - 1; i++){
                if(rotateArray[i+1] < rotateArray[i]){
                    target = rotateArray[i + 1];
                    break;
                }
            }
        }
        else return 0;
        
        return target;
    }
};
```
3.二分法<br>
```c++
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int left = 0;
        int right = rotateArray.size()-1;
        int middle = -1;
        if(!rotateArray.empty()){
            while(rotateArray[left] >= rotateArray[right]){
                if(right - left <= 1){  //!!
                    middle = right;
                    break;
                }
                middle = left + (right - left) / 2;
                if(rotateArray[middle] >= rotateArray[left])
                    left = middle;
                if(rotateArray[middle] <= rotateArray[right])
                    right = middle;
            }
        }else return 0;
        
        return rotateArray[middle];
    }
};
```
