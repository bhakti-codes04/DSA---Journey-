/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
    public:

    // Function to return a list of nodes visible from the top view
    // from left to right in a Binary Tree.

    vector<int> topView(Node *root)
    {
        // Create an empty vector to store the final answer
        vector<int> ans;

        // Base Case:
        // If the tree is empty, return an empty vector
        if(root == NULL) 
        {
            return ans;
        }

        // Map stores the first node found at each horizontal distance (HD)
        // Key   = Horizontal Distance
        // Value = Node's data
        map<int,int> topNode;

        // Queue stores:
        // First  = Address of the tree node
        // Second = Horizontal Distance (HD)
        queue<pair<Node*, int> > q;

        // Push the root node into the queue
        // Horizontal distance of root is 0
        q.push(make_pair(root, 0));

        // Traverse the tree using Level Order Traversal (BFS)
        while(!q.empty()) {

            // Get the front element of the queue
            pair<Node*, int> temp = q.front();

            // Remove the front element from the queue
            q.pop();

            // Store the current node
            Node* frontNode = temp.first;

            // Store the horizontal distance of the current node
            int hd = temp.second;

            // If no node is present for this horizontal distance,
            // store the current node's data in the map.
            // Because BFS visits nodes level by level,
            // the first node at each HD is visible from the top.
            if(topNode.find(hd) == topNode.end())
                topNode[hd] = frontNode->data;

            // If the left child exists,
            // its horizontal distance will decrease by 1
            if(frontNode->left)
                q.push(make_pair(frontNode->left, hd-1));

            // If the right child exists,
            // its horizontal distance will increase by 1
            if(frontNode->right)
                q.push(make_pair(frontNode->right, hd+1));
        }

        // Traverse the map in sorted order of horizontal distance
        // This gives nodes from left to right
        for(auto i : topNode) 
        {
            // Store each node's data in the answer vector
            ans.push_back(i.second);
        }

        // Return the final top view
        return ans;
    }
};
