# Assign Cookies

## Key Idea
Sort both the students' greed factors and the cookie sizes, then greedily satisfy the least greedy students using the smallest available cookies.

## Pattern
Greedy Algorithm / Two Pointers

## Approach
- **Sort** the arrays for students' greed factors and cookie sizes in ascending order.
- **Initialize** two pointers, `l` for students and `r` for cookies.
- **Traverse** both arrays: if a cookie satisfies the current student (`Cookie[r] >= Student[l]`), increment both pointers.
- **Otherwise**, just move the cookie pointer to try a larger cookie.

## Edge Case
No cookies available or no students can be satisfied with the given cookies.

## Complexity
Time: O(N logN + M logM + min(N, M))
Space: O(1)

## Revision Note
Sort both arrays -> use two pointers -> if `Cookie[r] >= Student[l]`, move both; else, move cookie pointer `r`.
