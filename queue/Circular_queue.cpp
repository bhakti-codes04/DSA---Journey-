
class CircularQueue{
    int *arr;       // Array to store queue elements
    int front;      // Points to the first element
    int rear;       // Points to the last element
    int size;       // Maximum size of queue
    
public:

    // Constructor to initialize circular queue
    CircularQueue(int n){
        size = n;               // Set the size of queue
        arr = new int[size];    // Create a dynamic array
        front = rear = -1;      // Initially queue is empty
    }

    // Function to insert an element into the queue
    bool enqueue(int value){

        // Check if queue is full
        if( (front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1) ) ) {

            return false;       // Queue is full, insertion not possible
        }

        else if(front == -1) {  // If inserting the first element
            front = rear = 0;   // Set front and rear to 0
        }

        else if(rear == size-1 && front != 0) {
            rear = 0;           // Move rear to 0 to maintain circular order
        }

        else {
            rear++;             // Move rear to next position
        }

        arr[rear] = value;      // Insert the value at rear position

        return true;            // Element inserted successfully
    }

    // Function to remove an element from the queue
    int dequeue(){

        if(front == -1) {       // Check if queue is empty
            return -1;          // Return -1 if queue is empty
        }

        int ans = arr[front];   // Store the front element

        arr[front] = -1;        // Remove the front element

        if(front == rear) {     // If only one element is present
            front = rear = -1;  // Reset queue to empty
        }

        else if(front == size - 1) {
            front = 0;          // Move front to 0 to maintain circular order
        }

        else {
            front++;            // Move front to next position
        }

        return ans;             // Return the deleted element
    }
};

