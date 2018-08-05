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
7.斐波那契数列<br>
题目描述<br>
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。n<=39<br>
递归 VS 迭代<br>
```c++
class Solution {
public:
    int Fibonacci(int n) {
        int result;
        int result_pre_pre = 0;
        int result_pre = 1;
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++){
           result = result_pre + result_pre_pre;
           result_pre_pre = result_pre;
           result_pre = result;
        }
        return result;
    }
};
```
8.跳台阶<br>
题目描述<br>
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。<br>
解题思路：同斐波那契数列
```c++
class Solution {
public:
    int jumpFloor(int number) {
        int result;
        int first = 1;
        int second = 2;
        if(number == 1) return 1;
        if(number == 2) return 2;
        for(int i = 3; i <= number; i++){
            result = first + second;
            first = second;
            second = result;
        }
        return result;
    }
};
```
9.变态跳台阶<br>
题目描述<br>
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。<br>
```c++
class Solution {
public:
    int jumpFloorII(int number) {
        int result = 1;
        if(number == 1) return 1;
        for(int i = 2; i <= number; i++){
            result *= 2;
        }
        return result;

    }
};
```
10.矩阵覆盖<br>
题目描述<br>
我们可以用2\*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2\*1的小矩形无重叠地覆盖一个2\*n的大矩形，总共有多少种方法？<br>
11.二进制中1的个数<br>
题目描述<br>
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
```c++
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n != 0){
             count++;
             n = n & (n-1);
         }
         return count;
     }
};
```
12.数值的整数次方<br>
题目描述<br>
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
```c++
class Solution {
public:
    double Power(double base, int exponent) {
        long long p = abs(exponent);
        double result = 1.0;
        double temp;
        while(p){
            if(p & 1)
                result *= base;
            base *= base;
            p = p >> 1;
        }
        return (exponent > 0) ? result:(1/result);
    }
};
```
13.调整数组顺序使奇数位于偶数前面<br>
题目描述<br>
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
```c++
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> result;
        int num = array.size();
        if(num==0) return;
        for(int i = 0; i < num; i++){
            if(array[i] % 2 == 1){ //奇数
                result.push_back(array[i]);
            }
        }
        for(int j = 0; j < num; j++){
            if(array[j] % 2 == 0){
                result.push_back(array[j]);
            }
        }
        array=result;
    }
};
```
14.链表中倒数第K个结点<br>
题目描述<br>
输入一个链表，输出该链表中倒数第k个结点。
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *pListPre = pListHead;
        ListNode *pListLast = pListHead;
        int count = 0;
        if(pListHead == NULL) return NULL;
        while(pListPre != NULL){
            if(count >= k){
                pListLast = pListLast->next;
            }
            pListPre = pListPre->next;
            count++;
        }
        if(count < k) return NULL;
        return pListLast;
    }
};
```
15.反转链表<br>
题目描述<br>
输入一个链表，反转链表后，输出新链表的表头。
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead -> next == NULL)
            return pHead;
        ListNode* pListPre = NULL;
        ListNode* pListNext = NULL;
        while(pHead != NULL){
            pListNext = pHead -> next;  // 保存下一个结点
            pHead -> next = pListPre;   // 链表反转
            pListPre = pHead;
            
            pHead = pListNext;          // 指向已保存的下一个结点
        }
        return pListPre;
    }
};
```
16.合并两个排序的链表<br>
题目描述<br>
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。<br>
递归的方法<br>
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode* newHead = NULL;
        if(pHead1->val <= pHead2->val){
            newHead = pHead1;
            newHead->next = Merge(newHead->next, pHead2);
        }
        else{
            newHead = pHead2;
            newHead->next = Merge(pHead1, newHead->next);
        }
        return newHead;
    }
};
```
非递归方法
```c++
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL && pHead2 == NULL)
            return NULL;
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        ListNode *mergeHead = NULL;
        ListNode *current = NULL;
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val <= pHead2->val){
                if(mergeHead == NULL){
                   mergeHead = current = pHead1;
                }else{
                   current->next = pHead1;
                   current = current->next;
                }
                pHead1 = pHead1->next;
            }else{
                if(mergeHead == NULL){
                   mergeHead = current = pHead2;
                }else{
                   current->next = pHead2;
                   current = current->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 == NULL){
            current->next = pHead2;
        }else{
            current->next = pHead1;
        }
        return mergeHead;
    }
};
```

