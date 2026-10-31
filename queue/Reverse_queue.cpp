// Function to reverse a queue using a stack
queue<int> rev(queue<int> q)
{
    // Create an empty stack
    stack<int> s;

    // Step 1: Remove all elements from the queue
    // and push them into the stack
    while(!q.empty())
    {
        // Get the front element of the queue
        int element = q.front();

        // Remove the front element from the queue
        q.pop();

        // Push the element into the stack
        s.push(element);
    }

    // Step 2: Remove all elements from the stack
    // and insert them back into the queue
    while(!s.empty())
    {
        // Get the top element of the stack
        int element = s.top();

        // Remove the top element from the stack
        s.pop();

        // Insert the element into the queue
        q.push(element);
    }

    // Step 3: Return the reversed queue
    return q;
}
