class Solution{
    public:

    // Function to find the height of a binary tree
    int height(struct Node* node){

        // Base Case:
        // If node is NULL, return 0 because an empty tree has height 0
        if(node == NULL) {
            return 0;
        }

        // Step 1: Calculate the height of the left subtree
        int left = height(node->left);

        // Step 2: Calculate the height of the right subtree
        int right = height(node->right);

        // Step 3: Find the maximum height between left and right
        // Add 1 for the current root node
        int ans = max(left, right) + 1;

        // Step 4: Return the calculated height
        return ans;
    }
};
