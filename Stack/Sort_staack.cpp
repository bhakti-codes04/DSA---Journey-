// Function to insert a number at its correct position
// in an already sorted stack
void sortedInsert(stack<int> &stack, int num) {

    // Base case:
    // Agar stack empty hai, toh num ko push kar do
    // Ya agar top element num se chhota hai,
    // toh num ko top par insert kar sakte hain
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;  // Function ko yahin stop kar do
    }

    // Stack ke top element ko temporary variable mein save karo
    int n = stack.top();

    // Top element ko stack se remove karo
    stack.pop();

    // Recursive call:
    // num ko uski correct position par insert karne ke liye
    // neeche ke elements ko check karo
    sortedInsert(stack, num);

    // Recursive call ke baad saved element ko wapas push karo
    stack.push(n);
}


// Function to sort the complete stack
void sortStack(stack<int> &stack) {

    // Base case:
    // Agar stack empty hai, toh recursion stop kar do
    if(stack.empty()) {
        return;
    }

    // Stack ke top element ko save karo
    int num = stack.top();

    // Top element ko stack se remove karo
    stack.pop();

    // Recursive call:
    // Baaki stack ko sort karo
    sortStack(stack);

    // Sorted stack mein num ko uski correct position
    // par insert karo
    sortedInsert(stack, num);
}
