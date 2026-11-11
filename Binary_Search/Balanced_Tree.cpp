/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution{
    public:

    // Function to check whether a binary tree is balanced or not.
    // It returns two things:
    // 1. First: Whether the tree is balanced (true/false)
    // 2. Second: Height of the tree

    pair<bool, int> isBalancedFast(Node* root) {

        // Base Case:
        // If root is NULL, tree is balanced and its height is 0
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // Step 1: Check the left subtree
        // It returns whether left subtree is balanced and its height
        pair<bool,int> left = isBalancedFast(root->left);

        // Step 2: Check the right subtree
        // It returns whether right subtree is balanced and its height
        pair<bool,int> right = isBalancedFast(root->right);

        // Step 3: Store the balanced status of left subtree
        bool leftAns = left.first;

        // Store the balanced status of right subtree
        bool rightAns = right.first;

        // Step 4: Calculate the difference between left and right heights
        // For a balanced tree, the difference must be <= 1
        bool diff = abs(left.second - right.second) <= 1;

        // Step 5: Create a pair to store the final answer
        pair<bool,int> ans;

        // Calculate the height of the current tree
        // Height = Maximum of left and right subtree height + 1
        ans.second = max(left.second, right.second) + 1;

        // Step 6: Check all three conditions:
        // 1. Left subtree should be balanced
        // 2. Right subtree should be balanced
        // 3. Height difference should be <= 1
        if(leftAns && rightAns && diff) {
            ans.first = true;
        }
        else
        {
            ans.first = false;
        }

        // Return balanced status and height
        return ans;
    }

    // Main function to check whether the binary tree is balanced
    bool isBalanced(Node *root)
    {
        // Return only the first value (true or false)
        return isBalancedFast(root).first;
    }
};
