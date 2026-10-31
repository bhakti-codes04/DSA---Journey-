#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

        // Function to find the first non-repeating character
        // at every step of the given string
        string FirstNonRepeating(string A){

            // Map stores the frequency (count) of each character
            map<char, int> m;

            // String to store our final answer
            string ans = "";

            // Queue stores characters in the order they arrive
            queue<char> q;

            // Traverse the input string character by character
            for(int i=0; i<A.length(); i++) {

                // Get the current character from the string
                char ch = A[i];

                // Insert the current character into the queue
                q.push(ch);

                // Increase the frequency of the current character
                m[ch]++;

                // Check characters from the front of the queue
                while(!q.empty()) {

                    // If the front character appears more than once
                    // then it is repeating
                    if(m[q.front()] > 1){

                        // Remove the repeating character from queue
                        q.pop();
                    }
                    else
                    {
                        // If frequency is 1, it is non-repeating
                        // Add it to the answer string
                        ans.push_back(q.front());

                        // Stop checking because we found the first
                        // non-repeating character
                        break;
                    }
                }

                // If queue becomes empty, no non-repeating
                // character is available
                if(q.empty()){

                    // Add # to the answer
                    ans.push_back('#');
                }
            }

            // Return the final answer
            return ans;
        }
};
