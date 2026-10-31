#include<bits/stdc++.h>
using namespace std;

// Structure to store petrol and distance of each petrol pump
struct petrolPump
{
    int petrol;
    int distance;
};

// Solution class
class Solution{
  public:

    // Function to find the starting point where the truck
    // can complete the entire circular tour
    int tour(petrolPump p[],int n)
    {
       // deficit stores the total negative balance
       // when the truck fails at any petrol pump
       int deficit = 0;

       // balance stores the remaining petrol
       // after travelling from the starting point
       int balance = 0;

       // start stores the possible starting petrol pump index
       int start = 0;

       // Traverse all petrol pumps one by one
       for(int i=0; i<n; i++) {

           // Calculate petrol gained minus distance travelled
           // If petrol is greater than distance, balance increases
           // Otherwise, balance decreases
           balance += p[i].petrol - p[i].distance;

           // If balance becomes negative,
           // it means truck cannot reach the next petrol pump
           if(balance < 0) {

               // Set the next petrol pump as a new starting point
               start = i+1;

               // Store the negative balance in deficit
               deficit += balance;

               // Reset balance because we are starting a new journey
               balance = 0;
           }
       }

       // Check whether total petrol is sufficient
       // to complete the entire circular tour
       if(balance + deficit >= 0)
            return start;  // Return the valid starting index

       // If total petrol is less than total distance,
       // completing the circular tour is impossible
       return -1;
    }
};
