# Rabin-Karp Algorithm

## Key Idea
Use a rolling hash to efficiently search for occurrences of a pattern within a text string. The hash values can be updated in $O(1)$ time when shifting the window, avoiding full string comparisons except when a hash collision occurs.

## Pattern
String Matching / Rolling Hash

## Approach
- **Initialize**: Choose a prime base $P$ (e.g., 7) and a modulo $MOD$ (e.g., 101). Compute the initial hash for the pattern and for the first window of the text (length $N$).
- **Slide Window**: For each window of size $N$ in the text (from index $0$ to $M-N$):
- **Compare**: If the current hash of the text window matches the pattern's hash, perform a substring comparison to avoid false positives (hash collisions). If they match, record the starting index.
- **Roll Hash**: Update the hash for the next window by subtracting the contribution of the outgoing character and adding the contribution of the incoming character, multiplying by the appropriate prime powers. Update the `pLeft` and `pRight` multipliers dynamically.

## Edge Case
Pattern length is greater than text length, or hash collisions causing false positives.

## Complexity
Time: Average $O(M)$, Worst-case $O(N \times M)$ if many hash collisions occur.
Space: $O(K)$ where $K$ is the number of matches found.

## Revision Note
Compute initial hashes for `pat` and `txt` of length `N` -> Slide window over `txt`: if `hashPat == hashText`, double check `substr` -> update `hashText` by removing old char and adding new char with prime multipliers modulo.
