// T.C:  O(N) 
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/celebrity-problem?source=strivers-sde-sheet

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
         stack<int> st;
         int N = M.size();
        for (int i = 0; i < N; i++) st.push(i);

        // Step 2: Eliminate non-celebrities
        while (st.size() > 1) {
            int A = st.top(); st.pop();
            int B = st.top(); st.pop();

            if (M[A][B] == 1) {
                // A knows B → A is not celebrity
                st.push(B);
            } else {
                // A does not know B → B is not celebrity
                st.push(A);
            }
        }

        // Step 3: Verify candidate
        int cand = st.top();
        for (int i = 0; i < N; i++) {
            if (i != cand) {
                if (M[cand][i] == 1 || M[i][cand] == 0)
                    return -1;
            }
        }
        return cand;
    }
};
