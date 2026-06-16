// T.C: O(N logN + M logM + min(N, M))
// S.C: O(1)
// Question Link: https://takeuforward.org/plus/dsa/problems/assign-cookies?source=strivers-sde-sheet

class Solution {
public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie) {
        int n = Student.size();  // number of students, each with a greed factor (minimum cookie size they'll be content with)
        int m = Cookie.size();   // number of cookies, each with a certain size

        int l = 0, r = 0;  // l -> pointer for students, r -> pointer for cookies

        // Sort both arrays in ascending order.
        // This lets us try to satisfy the "easiest to please" student first
        // using the smallest cookie that can satisfy them — a greedy strategy.
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());

        // Walk through cookies and students together.
        while (l < n && r < m) {
            // If the current cookie is big enough to satisfy the current student,
            // that student is content, so move to the next student.
            if (Cookie[r] >= Student[l]) {
                l++;
            }
            // Move to the next cookie regardless of whether it satisfied
            // the current student or not — each cookie can only be used once.
            r++;
        }

        // l now represents the total number of students who were
        // successfully satisfied with a cookie.
        return l;
    }
};

