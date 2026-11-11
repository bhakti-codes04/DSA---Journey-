/**********************************************************
    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
***********************************************************/

// Function to count the total number of leaf nodes
void inorder(BinaryTreeNode<int> *root, int &count) {

    // Base Case: If the root is NULL, return
    // This means there is no node in the tree
    if(root == NULL) {
        return;
    }

    // Step 1: Traverse the left subtree
    inorder(root->left, count);

    // Step 2: Check whether the current node is a leaf node
    // A leaf node has both left and right children as NULL
    if(root->left == NULL && root->right == NULL) {
        count++;  // Increment count if it is a leaf node
    }

    // Step 3: Traverse the right subtree
    inorder(root->right, count);
}

// Function to return the total number of leaf nodes
int noOfLeafNodes(BinaryTreeNode<int> *root){

    // Initialize count with 0
    int cnt = 0;

    // Call inorder function to count all leaf nodes
    inorder(root, cnt);

    // Return the total count of leaf nodes
    return cnt;
}
