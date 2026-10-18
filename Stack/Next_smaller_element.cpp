#include <stack>
#include <vector>
using namespace std;

// Function next smaller element find karega
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Stack banaya elements ko store karne ke liye
    stack<int> s;

    // Agar koi smaller element nahi mila,
    // toh -1 answer hoga
    s.push(-1);

    // Answer store karne ke liye vector banaya
    vector<int> ans(n);

    // Right se left ki taraf traverse karenge
    for(int i = n - 1; i >= 0; i--) {

        // Current element ko curr mein store karo
        int curr = arr[i];

        // Jab tak stack ka top current element se
        // bada ya equal hai, use remove karte raho
        while(s.top() >= curr)
        {
            s.pop();
        }

        // Stack ka top current element se chhota hai
        // Yehi next smaller element hai
        ans[i] = s.top();

        // Current element ko stack mein push karo
        // taaki ye left side ke elements ke liye
        // next smaller element ban sake
        s.push(curr);
    }

    // Final answer return karo
    return ans;
}
