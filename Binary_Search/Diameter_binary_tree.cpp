/* Tree node structure used in the program

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

class Solution {
  private:

    // Function to calculate the height of a binary tree
    int height(struct Node* node){

        // Base Case:
        // If node is NULL, height of the tree is 0
        if(node == NULL) {
            return 0;
        }

        // Calculate the height of the left subtree
        int left = height(node->left);

        // Calculate the height of the right subtree
        int right = height(node->right);

        // Height = Maximum of left and right height + 1 (current node)
        int ans = max(left, right) + 1;

        // Return the height
        return ans;
    }

  public:

    // Function to return the diameter of a Binary Tree

    // diameterFast returns two values:
    // First  = Diameter of the tree
    // Second = Height of the tree

    pair<int,int> diameterFast(Node* root) {

        // Base Case:
        // If root is NULL, diameter and height both are 0
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        // Step 1: Calculate diameter and height of the left subtree
        pair<int,int> left = diameterFast(root->left);

        // Step 2: Calculate diameter and height of the right subtree
        pair<int,int> right = diameterFast(root->right);

        // Step 3: Find three possible diameters

        // Option 1: Diameter exists completely in the left subtree
        int op1 = left.first;

        // Option 2: Diameter exists completely in the right subtree
        int op2 = right.first;

        // Option 3: Diameter passes through the root node
        // Left height + Right height + 1 (current root node)
        int op3 = left.second + right.second + 1;

        // Step 4: Create a pair to store the final answer
        pair<int,int> ans;

        // Find the maximum diameter among all three options
        ans.first = max(op1, max(op2, op3));

        // Calculate the height of the current tree
        // Height = Maximum of left and right subtree height + 1
        ans.second = max(left.second, right.second) + 1;

        // Return diameter and height together
        return ans;
    }

    // Main function to calculate the diameter of the binary tree
    int diameter(Node* root) {

        // Return only the diameter (first value of the pair)
        return diameterFast(root).first;
    }
};
