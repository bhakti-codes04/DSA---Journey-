// Should return true if tree is Sum Tree, else false

class Solution
{
    public:

    // Function to check whether a binary tree is a Sum Tree or not
    // It returns two values:
    // First  = Whether the tree is a Sum Tree (true/false)
    // Second = Sum of all nodes in the tree

    pair<bool,int> isSumTreeFast(Node* root) {

        // Base Case 1:
        // If root is NULL, the tree is a Sum Tree
        // Its sum is 0
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }

        // Base Case 2:
        // If the current node is a leaf node
        // A leaf node is always considered a Sum Tree
        // Return true and its own data as the sum
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }

        // Step 1: Check whether the left subtree is a Sum Tree
        pair<bool,int> leftAns = isSumTreeFast(root->left);

        // Step 2: Check whether the right subtree is a Sum Tree
        pair<bool,int> rightAns = isSumTreeFast(root->right);

        // Step 3: Get the answer for the left subtree
        bool isLeftSumTree = leftAns.first;

        // Get the answer for the right subtree
        bool isRightSumTree = rightAns.first;

        // Step 4: Get the sum of the left subtree
        int leftSum = leftAns.second;

        // Get the sum of the right subtree
        int rightSum = rightAns.second;

        // Step 5: Check whether the current root data
        // is equal to the sum of its left and right subtrees
        bool condn = root->data == leftSum + rightSum;

        // Create a pair to store the final answer
        pair<bool, int> ans;

        // Step 6: Check all three conditions:
        // 1. Left subtree must be a Sum Tree
        // 2. Right subtree must be a Sum Tree
        // 3. Root data must equal left sum + right sum

        if(isLeftSumTree && isRightSumTree && condn) {

            // Current tree is a Sum Tree
            ans.first = true;

            // Calculate the total sum of the current tree
            // Root data + left subtree sum + right subtree sum
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            // If any condition fails, it is not a Sum Tree
            ans.first = false;
        }

        // Return the Sum Tree status and total sum
        return ans;
    }

    // Main function to check whether the given tree is a Sum Tree
    bool isSumTree(Node* root)
    {
        // Return only the first value (true/false)
        return isSumTreeFast(root).first;
    }
};
