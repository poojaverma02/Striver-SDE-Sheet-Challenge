# Longest Increasing Subsequence

## Key Idea
Finding the Longest Increasing Subsequence (LIS) in $O(N^2)$ using dynamic programming can lead to Time Limit Exceeded (TLE) for large inputs. Instead, we can use a temporary array combined with Binary Search (using `lower_bound`) to construct the LIS efficiently in $O(N \log N)$ time.

## Pattern
Dynamic Programming / Binary Search / Subsequence

## Approach
- **Initialization**: Create a `temp` array and push the first element of `nums` into it.
- **Iteration**: Loop through `nums` starting from index $1$.
  - If the current element is strictly greater than the last element in `temp` (`temp.back()`), it extends the increasing subsequence. Push it to `temp`.
  - If it is not greater, we find its correct position in `temp` to replace an existing element. Use `lower_bound` to find the index of the first element in `temp` that is $\ge$ the current element. Replace the element at that index with the current element.
- **Return**: The length of the `temp` array represents the length of the LIS (though `temp` itself might not be the actual valid LIS, its length is correct).

## Edge Case
Empty array (handled by constraints, but generally return 0). Array with all identical elements (length is 1).

## Complexity
Time: O(N \log N) as `lower_bound` takes $O(\log N)$ and we iterate $N$ times.
Space: O(N) to store the `temp` array.

## Revision Note
Use `temp` array + Binary Search (`lower_bound`). If `nums[i] > temp.back()`, `temp.push_back(nums[i])`. Else, `ind = lower_bound`, `temp[ind] = nums[i]`. Return `temp.size()`.
