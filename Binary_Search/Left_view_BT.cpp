/* A binary tree node

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

// Function to find the left view of a binary tree
// Left View means the nodes visible when we see the tree from the left side.

// Recursive function to traverse the tree
void solve(Node* root, vector<int> &ans, int level) {

    // Base Case:
    // If root is NULL, there is no node to process
    if(root == NULL)
        return;

    // Check whether we are visiting this level for the first time
    // If level == ans.size(), it means no node has been added
    // for this level yet.
    if(level == ans.size())
        ans.push_back(root->data);

    // Step 1: First traverse the left subtree
    // Because we need the first (leftmost) node at every level
    solve(root->left, ans, level+1);

    // Step 2: Then traverse the right subtree
    solve(root->right, ans, level+1);
}

// Function to return a list containing
// elements of the left view of the binary tree
vector<int> leftView(Node *root)
{
    // Create an empty vector to store the left view nodes
    vector<int> ans;

    // Start recursive traversal from root
    // Initially, level is 0
    solve(root, ans, 0);

    // Return the left view of the binary tree
    return ans;
}
