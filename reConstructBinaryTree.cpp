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
