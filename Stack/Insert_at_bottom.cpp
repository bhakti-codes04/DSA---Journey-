
void solve(stack<int>& s, int x) {

    // BASE CASE:
    // Jab stack empty ho jaye, tab x ko bottom mein insert karo.
    if (s.empty()) {
        s.push(x);  // x ko empty stack mein push karo
        return;     // Function se wapas return karo
    }

    // Stack ke top element ko num mein store karo.
    int num = s.top();

    // Top element ko temporarily remove karo.
    s.pop();

    // RECURSIVE CALL:
    // Stack ko empty hone tak elements remove karte raho.
    solve(s, x);

    // RECURSION SE RETURN HONE KE BAAD:
    // Temporarily removed element ko wapas push karo.
    // Isse original elements ka order same rahega.
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {

    // solve function ko call karke x ko bottom mein insert karo.
    solve(myStack, x);

    // Updated stack ko return karo.
    return myStack;
}
