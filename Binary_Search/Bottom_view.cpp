// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:

    // Function to find the bottom view of a binary tree
    vector<int> bottomView(Node *root) {

        // Create an empty vector to store the final answer
        vector<int> ans;

        // Base Case:
        // If the tree is empty, return an empty vector
        if(root == NULL) 
        {
            return ans;
        }

        // Map stores:
        // Key   = Horizontal Distance (HD)
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

            // Update the map with the current node's data
            // If multiple nodes have the same HD,
            // the latest visited node will overwrite the previous value.
            // Therefore, the bottommost node gets stored.
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
        // This gives the bottom view from left to right
        for(auto i : topNode) 
        {
            // Store the node's data in the answer vector
            ans.push_back(i.second);
        }

        // Return the final bottom view
        return ans;
    }
};
