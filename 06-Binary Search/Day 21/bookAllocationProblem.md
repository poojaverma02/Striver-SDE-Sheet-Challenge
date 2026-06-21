# Allocate Books

## Key Idea
Use binary search on the maximum pages a student can read, with a greedy check to see how many students are needed for a given maximum limit.

## Pattern
Binary Search on Answer / Greedy

## Approach
- **Set** bounds: `low = max(nums)` (minimum possible max pages) and `high = sum(nums)` (all books to one student).
- **Check Function**: Iterate books and assign to the current student until their sum exceeds `mid`. If so, allocate to a new student.
- **Adjust Boundaries**: If the required `students` exceeds `m`, increase the allowed pages (`low = mid + 1`). Otherwise, try a smaller max limit (`high = mid - 1`).

## Edge Case
Number of students `m` is greater than the number of books `n` (impossible allocation).

## Complexity
Time: O(N * log(sum-max))
Space: O(1)

## Revision Note
BS on answer `[max_book, sum_books]` -> `countStudents` function greedy assignment -> if `students > m`, need more pages `low = mid + 1`.
