bool isValidParenthesis(string expression)
{
    // Stack banaya jo opening brackets store karega
    stack<char> s;

    // Expression ke har character par loop chalega
    for(int i = 0; i < expression.length(); i++) {

        // Current character ko ch variable mein store karo
        char ch = expression[i];

        // Check karo ki current character opening bracket hai ya nahi
        if(ch == '(' || ch == '{' || ch == '[') {

            // Opening bracket ko stack mein push kar do
            s.push(ch);
        }
        else
        {
            // Agar closing bracket hai, toh pehle check karo
            // ki stack empty toh nahi hai
            if(!s.empty()) {

                // Stack ka top element check karo
                char top = s.top();

                // Check karo ki opening aur closing brackets match karte hain ya nahi
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')) {

                    // Brackets match ho gaye, toh opening bracket remove karo
                    s.pop();
                }
                else
                {
                    // Brackets match nahi hue, expression invalid hai
                    return false;
                }
            }
            else
            {
                // Opening bracket se pehle closing bracket aa gaya
                // Isliye expression invalid hai
                return false;
            }
        }
    }

    // Saare characters check karne ke baad:
    // Agar stack empty hai, toh saare brackets match ho gaye
    if(s.empty())
        return true;

    // Stack mein opening brackets bache hain, toh expression invalid hai
    else
        return false;
}
