
class Deque
{	
    int *arr;       // Array to store deque elements
    int front;      // Points to the first element
    int rear;       // Points to the last element
    int size;       // Maximum size of deque

public:

    // Constructor to initialize deque
    Deque(int n)
    {
        size = n;               // Set the size of deque
        arr = new int[n];       // Create a dynamic array
        front = -1;             // Initially front is -1
        rear = -1;              // Initially rear is -1
    }

    // Insert an element at the front of deque
    bool pushFront(int x)
    {
        // Check if deque is full
        if(isFull()) {
            return false;       // Insertion not possible
        }

        // If deque is empty, set front and rear to 0
        else if(isEmpty()) {
            front = rear = 0;
        }

        // If front is at 0 and rear is not at last position
        else if(front == 0 && rear != size-1) {
            front = size-1;     // Move front to last index
        } 

        else
        {
            front--;            // Move front one position backward
        }

        arr[front] = x;         // Insert element at front

        return true;            // Element inserted successfully
    }

    // Insert an element at the rear of deque
    bool pushRear(int x)
    {
        // Check if deque is full
        if(isFull()) {
            return false;       // Insertion not possible
        }

        // If deque is empty, set front and rear to 0
        else if(isEmpty()) {
            front = rear = 0;
        }

        // If rear is at last position and front is not at 0
        else if(rear == size-1 && front != 0) {
            rear = 0;           // Move rear to first index
        } 

        else
        {
            rear++;             // Move rear one position forward
        }

        arr[rear] = x;          // Insert element at rear

        return true;            // Element inserted successfully
    }

    // Remove an element from the front of deque
    int popFront()
    {
        // Check if deque is empty
        if(isEmpty()){
            return -1;          // Return -1 if empty
        }
        
        int ans = arr[front];   // Store the front element

        arr[front] = -1;        // Remove the front element
        
        // If only one element is present
        if(front == rear) {
            front = rear = -1;  // Make deque empty
        }

        // If front is at the last index
        else if(front == size - 1) {
            front = 0;          // Move front to first index
        }

        else
        {
            front++;            // Move front to next position
        }

        return ans;             // Return deleted element
    }

    // Remove an element from the rear of deque
    int popRear()
    {
        // Check if deque is empty
        if(isEmpty()){
            return -1;          // Return -1 if empty
        }
        
        int ans = arr[rear];    // Store the rear element

        arr[rear] = -1;         // Remove the rear element
        
        // If only one element is present
        if(front == rear) {
            front = rear = -1;  // Make deque empty
        }

        // If rear is at first index
        else if(rear == 0) {
            rear = size-1;      // Move rear to last index
        }

        else
        {
            rear--;             // Move rear one position backward
        }

        return ans;             // Return deleted element
    }

    // Return the first element of deque
    int getFront()
    {
        // Check if deque is empty
        if(isEmpty()){
            return -1;
        }

        return arr[front];      // Return front element
    }

    // Return the last element of deque
    int getRear()
    {
        // Check if deque is empty
        if(isEmpty()){
            return -1;
        }

        return arr[rear];       // Return rear element
    }

    // Check whether deque is empty or not
    bool isEmpty()
    {
        if(front == -1) {
            return true;        // Deque is empty
        }
        else {
            return false;       // Deque contains elements
        }
    }

    // Check whether deque is full or not
    bool isFull()
    {
        // Check if no empty position is available
        if((front == 0 && rear == size-1) ||
           (front != 0 && rear == (front-1)%(size-1))) {

            return true;        // Deque is full
        }
        else
        {
            return false;       // Space is available
        }
    }
};

