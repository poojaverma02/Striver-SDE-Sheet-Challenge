//T.C: O(N Log N) 
//S.C: O(N), in the merge sort there is use a temporary array to store elements in sorted order.
//Link: https://takeuforward.org/plus/dsa/problems/count-inversions?source=strivers-sde-sheet

class Solution {
   private:
    long long int merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;
        // pointer for left half  [low...mid]
        int left = low;
        // pointer for right half [mid+1...high]
        int right = mid + 1;

        long long int cnt = 0;

        // merge both halves while comparing elements
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                // no inversion: left element is in correct relative order
                temp.push_back(arr[left]);
                left++;
            } else {
                // arr[left] > arr[right] → inversion found
                // every remaining element in left half [left...mid] forms
                // an inversion with arr[right], so count all at once
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        // copy remaining elements of left half (already sorted, no new
        // inversions)
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // copy remaining elements of right half (already sorted, no new
        // inversions)
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // write sorted temp back into original array for this range
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;  // total inversions found during this merge
    }

    long long int mergeSort(vector<int>& arr, int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            // avoids integer overflow vs (low+high)/2
            int mid = low + (high - low) / 2;
            // count inversions in left half
            cnt += mergeSort(arr, low, mid);
            // count inversions in right half
            cnt += mergeSort(arr, mid + 1, high);
            // count split inversions & merge
            cnt += merge(arr, low, mid, high);
        }
        return cnt;
    }

   public:
    long long int numberOfInversions(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};