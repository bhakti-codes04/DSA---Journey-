
#include<iostream>   // cout aur endl use karne ke liye
#include<stack>      // Stack data structure use karne ke liye
#include<string>     // String use karne ke liye
using namespace std; // std:: baar-baar likhne ki zaroorat nahi

int main() {

    // Original string banayi hai.
    string str = "bhakti";

    // Characters store karne ke liye stack banaya.
    stack<char> s;

    // String ke har character par loop chalega.
    for (int i = 0; i < str.length(); i++) {

        // Current character ko ch mein store karo.
        char ch = str[i];

        // Character ko stack ke top par push karo.
        s.push(ch);
    }

    // Reversed string store karne ke liye empty string.
    string ans = "";

    // Jab tak stack empty nahi hota, loop chalao.
    while (!s.empty()) {

        // Stack ka top character access karo.
        char ch = s.top();

        // Character ko answer string ke end mein add karo.
        ans.push_back(ch);

        // Top character ko stack se remove karo.
        s.pop();
    }

    // Final reversed string print karo.
    cout << "answer is: " << ans << endl;

    // Program successfully finish hua.
    return 0;
}

