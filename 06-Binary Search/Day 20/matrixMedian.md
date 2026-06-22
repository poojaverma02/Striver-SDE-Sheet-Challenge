# Matrix Median

## Key Idea
Perform a binary search on the answer (the possible median values) and use `upper_bound` on each row to count elements less than or equal to the candidate median.

## Pattern
Binary Search on Answer / Upper Bound

## Approach
- **Determine** the search space by finding the minimum (`low`) and maximum (`high`) elements by checking the first and last columns of each row.
- **Compute** the required index for the median: `req = (n * m) / 2`.
- **Binary Search**: For a candidate `mid`, count the total number of elements `<= mid` across all rows.
- **Adjust** the search range: if the count is `<= req`, move `low = mid + 1`. Otherwise, `high = mid - 1`.

## Edge Case
Matrix with a single element or a matrix where all elements are identical.

## Complexity
Time: O(log(max - min + 1)) * O(N * logM)
Space: O(1)

## Revision Note
Binary search range `[min_val, max_val]` -> count elements `<= mid` using binary search (upper_bound) on each row -> if `count <= req`, `low = mid + 1`.
