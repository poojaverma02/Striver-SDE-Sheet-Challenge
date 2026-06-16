# Count Inversions

## Key Idea
Use Merge Sort. During the merge step, if an element in the right subarray is smaller than one in the left subarray, it forms an inversion with all remaining elements in the sorted left subarray.

## Pattern
Divide and Conquer (Merge Sort)

## Approach
- **Divide** the array recursively into two halves using `mergeSort(low, mid)` and `mergeSort(mid+1, high)`.
- **Merge** the sorted halves using a temporary array.
- **Count** inversions during merge: if `arr[left] > arr[right]`, then `cnt += (mid - left + 1)`.
- **Copy** remaining elements, then copy the temporary array back to the original array.

## Edge Case
Already sorted arrays (0 inversions) or reverse-sorted arrays (maximum inversions).

## Complexity
Time: O(N log N)
Space: O(N)

## Revision Note
Merge Sort: if `arr[left] > arr[right]`, it forms inversions with all remaining elements in the left half `(mid - left + 1)`.
