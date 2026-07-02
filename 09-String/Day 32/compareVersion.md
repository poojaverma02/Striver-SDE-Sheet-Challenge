# Compare Version Numbers

## Key Idea
Parse the version strings by splitting them at the `.` character into integer components. Pad the shorter version with zeros and compare corresponding components from left to right.

## Pattern
String Parsing / Array

## Approach
- **Split Strings**: Use a `stringstream` and `getline` with `.` as the delimiter to extract the numerical parts of `version1` and `version2`, converting them to integers using `stoi()`.
- **Pad with Zeros**: Find the maximum length between the two resulting arrays, and pad the shorter array with `0`s until they are equal length.
- **Compare**: Loop through the arrays element by element. If `v1[i] > v2[i]`, return `1`. If `v1[i] < v2[i]`, return `-1`.
- **Equality**: If the loop finishes without returning, the versions are identical. Return `0`.

## Edge Case
Versions with different number of dots, trailing zeros, or empty versions.

## Complexity
Time: O(N + M) where N and M are the lengths of the strings.
Space: O(N + M) for the vectors storing the parsed integers.

## Revision Note
Use `stringstream` with `getline(s, temp, '.')` -> `stoi(temp)` to push to vector -> pad vectors with zeros to match size -> compare element by element.
