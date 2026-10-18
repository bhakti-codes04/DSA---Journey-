
void solve(stack<int>& inputStack, int count, int size) {

    // BASE CASE:
    // Jab count, size/2 ke equal ho jayega,
    // tab hum middle element tak pahunch chuke honge.
    if (count == size / 2) {

        // Middle element ko stack se delete kar do.
        inputStack.pop();

        // Recursive function se wapas return karo.
        return;
    }

    // Stack ke top element ko num mein store karo.
    // top() sirf element ko access karta hai, delete nahi.
    int num = inputStack.top();

    // Top element ko temporarily stack se remove karo.
    inputStack.pop();

    // RECURSIVE CALL:
    // Agle element ki taraf badhne ke liye count ko 1 badhao.
    // Aisa tab tak hoga jab tak middle element na mil jaye.
    solve(inputStack, count + 1, size);

    // RECURSION SE RETURN HONE KE BAAD:
    // Jo element num mein store kiya tha,
    // use wapas stack mein push kar do.
    // Middle element ko wapas push nahi kiya jayega.
    inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {

    // Count 0 se start hoga kyunki abhi
    // tak koi element temporarily remove nahi hua hai.
    int count = 0;

    // Middle element delete karne ke liye
    // recursive function ko call karo.
    solve(inputStack, count, N);
}

