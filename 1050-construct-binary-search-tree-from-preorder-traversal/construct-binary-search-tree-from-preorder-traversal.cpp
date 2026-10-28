
class Solution {
public:
    TreeNode* BST(vector<int>& preorder, int &index, long long lower, long long upper) {
        
        if(index==preorder.size()|| lower>preorder[index] || upper<preorder[index] )
        return NULL;
        
        TreeNode* root= new TreeNode(preorder[index++]);
        root->left=BST(preorder,index,lower,root->val);
        root->right=BST(preorder,index,root->val,upper);
        
        return root;
    
    }
        
        

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return BST(preorder, index, LLONG_MIN, LLONG_MAX);
    }
};