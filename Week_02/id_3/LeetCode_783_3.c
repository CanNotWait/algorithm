/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right
};


//need to record parent of root;
int minDiffInBST(struct TreeNode* root) {
    struct TreeNode* root_parent  = NULL;
    struct TreeNode* root_current = root;
    struct TreeNode* root_left    = root_current->left;
    struct TreeNode* root_right   = root_current->right;

    int leftmin  = 0;
    int rightmin = 0;
    int min      = 0;

    if(!root || (!left && !right))
    {
        return 0;
    }

    if(!left && right)
    {
        rightmin = minDiffInBST(right);
        if(rightmin)
        {
            return right->val - root->val > rightmin ? rightmin : right->val - root->val;
        }

        return right->val - root->val;
    }

    if(left && !right)
    {
        leftmin = minDiffInBST(left);
        if(leftmin)
        {
            return root->val - left->val > leftmin ? leftmin : root->val - left->val;
        }

        return root->val - left->val;
    }

    leftmin = minDiffInBST(left);
    rightmin = minDiffInBST(right);

    if(0 == leftmin && 0 == rightmin)
    {
        return root->val - left->val > right->val - root->val ? 
            right->val - root->val : root->val - left->val;
    }

    if(0 == leftmin && 0 != rightmin)
    {
        rightmin = right->val - root->val > rightmin ? rightmin : right->val - root->val;
        rightmin = root->val - left->val > rightmin ? rightmin : root->val - left->val;
        return rightmin;
    }

    if(0 != leftmin && 0 == rightmin)
    {
        leftmin = root->val - left->val > leftmin ? leftmin : root->val - left->val;
        leftmin = right->val - root->val > leftmin ? leftmin : right->val - root->val;
        return leftmin;
    }

    leftmin  = root->val - left->val > leftmin ? leftmin : root->val - left->val;
    rightmin = right->val - root->val > rightmin ? rightmin : right->val - root->val;
    
    //tmp
    min = leftmin > rightmin ? rightmin : leftmin;
    return 
}