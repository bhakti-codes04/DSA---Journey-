class Solution
{
    public:

    // Function to check whether two binary trees are identical or not
    bool isIdentical(Node *r1, Node *r2)
    {
        // Base Case 1:
        // If both nodes are NULL, then both trees are identical
        if(r1 == NULL && r2 == NULL) {
            return true;
        }

        // Base Case 2:
        // If the first tree is NULL but the second tree is not NULL
        // Then both trees are not identical
        if(r1 == NULL && r2 != NULL) {
            return false;
        }

        // Base Case 3:
        // If the first tree is not NULL but the second tree is NULL
        // Then both trees are not identical
        if(r1 != NULL && r2 == NULL) {
            return false;
        }

        // Step 1: Check whether the left subtrees are identical
        bool left = isIdentical(r1->left, r2->left);

        // Step 2: Check whether the right subtrees are identical
        bool right = isIdentical(r1->right, r2->right);

        // Step 3: Compare the data of both current nodes
        bool value = r1->data == r2->data;

        // Step 4: Check all three conditions:
        // 1. Left subtrees should be identical
        // 2. Right subtrees should be identical
        // 3. Current node values should be equal

        if(left && right && value) {
            return true;
        }
        else
        {
            return false;
        }
    }
};
