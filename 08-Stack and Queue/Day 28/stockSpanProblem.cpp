// T.C:  O(2N) 
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/stock-span-problem?source=strivers-sde-sheet


class Solution {
private:
    /* Function to find the indices of previous 
    greater element for each element in the array */
    vector<int> findPGE(vector<int> arr) {
        
        int n = arr.size(); //size of array
        
        // To store the previous greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIFO fashion
        stack<int> st;
        
        // Start traversing from the front
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && arr[st.top()] <= currEle) {
                st.pop();
            }
            
            /* If the greater element is not 
            found, stack will be empty */
            if(st.empty()) 
                ans[i] = -1;
                
            // Else store the answer
            else 
                ans[i] = st.top();
            
            // Push the current index in the stack 
            st.push(i);
        }
        
        // Return the result
        return ans;
    }
    
public:
    // Function to find the span of stock prices for each day
    vector <int> stockSpan(vector<int> arr, int n) {
        
        // Get the indices of previous greater elements
        vector<int> PGE = findPGE(arr);
        
        
        // To store the answer
        vector<int> ans(n);
        
        // Compute the result
        for(int i=0; i < n; i++) {
            ans[i] = i - PGE[i];
        }
        
        // Return the result
        return ans;
    }
};