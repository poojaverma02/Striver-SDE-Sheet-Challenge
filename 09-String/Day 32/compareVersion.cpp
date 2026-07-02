// T.C: O(N) 
// S.C: O(N)
// Question Link: https://takeuforward.org/plus/dsa/problems/compare-version-numbers?source=strivers-sde-sheet

class Solution {
public:
    // Function to compare two version strings
    int compareVersion(string version1, string version2) {
        // Splitting both versions by '.'
        vector<int> v1, v2;
        stringstream s1(version1), s2(version2);
        string temp;
        
        // Extract numbers from version1
        while (getline(s1, temp, '.'))
            v1.push_back(stoi(temp));
        
        // Extract numbers from version2
        while (getline(s2, temp, '.'))
            v2.push_back(stoi(temp));
        
        // Make both vectors of equal length by padding zeros
        int n = max(v1.size(), v2.size());
        while (v1.size() < n) v1.push_back(0);
        while (v2.size() < n) v2.push_back(0);
        
        // Compare each corresponding element
        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i]) return 1;
            if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};
