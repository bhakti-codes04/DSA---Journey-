void insertAtBottom(stack<int> &s, int element) {

    // BASE CASE:
    // Jab stack empty ho, element ko bottom mein push karo.
    if (s.empty()) {
        s.push(element);
        return;
    }

    // Top element ko temporarily store karo.
    int num = s.top();

    // Top element ko remove karo.
    s.pop();

    // Recursively stack ko empty karke element insert karo.
    insertAtBottom(s, element);

    // Return hote waqt purane elements wapas push karo.
    s.push(num);
}

void reverseStack(stack<int> &s) {

    // BASE CASE:
    // Empty stack ko reverse karne ki zaroorat nahi.
    if (s.empty()) {
        return;
    }

    // Top element ko store karo.
    int num = s.top();

    // Top element ko temporarily remove karo.
    s.pop();

    // Baaki stack ko recursively reverse karo.
    reverseStack(s);

    // Removed element ko reversed stack ke bottom mein insert karo.
    insertAtBottom(s, num);
}
