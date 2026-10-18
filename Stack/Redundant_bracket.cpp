
#include <stack>
#include <string>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Stack banaya jisme characters store honge.
    stack<char> st;

    // String ke har character par iterate karenge.
    for (int i = 0; i < s.length(); i++) {

        // Current character ko ch mein store karo.
        char ch = s[i];

        // Agar character opening bracket ya operator hai,
        // toh use stack mein push kar do.
        if (ch == '(' || ch == '+' || ch == '-' ||
            ch == '*' || ch == '/') {

            st.push(ch);
        }
        else {

            // Agar current character closing bracket ')' hai,
            // toh check karo ki brackets redundant hain ya nahi.
            if (ch == ')') {

                // Initially maan rahe hain ki brackets redundant hain.
                bool isRedundant = true;

                // Opening bracket '(' milne tak stack check karo.
                while (!st.empty() && st.top() != '(') {

                    // Stack ke top character ko store karo.
                    char top = st.top();

                    // Agar opening aur closing bracket ke beech
                    // koi operator hai, toh brackets redundant nahi hain.
                    if (top == '+' || top == '-' ||
                        top == '*' || top == '/') {

                        isRedundant = false;
                    }

                    // Check kiya hua character stack se remove karo.
                    st.pop();
                }

                // Agar operator nahi mila, toh brackets redundant hain.
                if (isRedundant == true) {
                    return true;
                }

                // Opening bracket '(' ko bhi stack se remove karo.
                if (!st.empty()) {
                    st.pop();
                }
            }
        }
    }

    // Agar koi redundant bracket nahi mila,
    // toh false return karo.
    return false;
}

