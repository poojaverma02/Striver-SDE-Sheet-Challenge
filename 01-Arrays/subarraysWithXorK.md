# Count Subarrays with Given XOR K

## Key Idea
Use Prefix XOR and a Hash Map. If the current prefix XOR is `xr`, and we are looking for a subarray ending at the current index with XOR `k`, then there must exist a previous prefix XOR `x` such that `x ^ xr = k`. This implies `x = xr ^ k`.

## Pattern
Prefix XOR + Hash Map

## Approach
- **Initialize** `xr = 0` and a map `mpp` to store the frequencies of prefix XORs.
- **Insert** `mpp[0] = 1` as a base case to handle subarrays starting from index 0.
- **Iterate** through the array and compute the running prefix XOR `xr`.
- Calculate the target previous XOR `x = xr ^ k`.
- Add the frequency of `x` from the map `mpp` to the count of valid subarrays.
- **Record** the current prefix XOR `xr` in the map `mpp[xr]++`.

## Edge Case
Subarrays starting exactly at index 0. Initializing the map with `0: 1` ensures they are counted correctly when `xr == k`.

## Complexity
Time: O(N * logN) if using `std::map`, or O(N) on average with `std::unordered_map`.
Space: O(N) to store prefix XOR frequencies in the map.

## Revision Note
Prefix XOR trick. `xr ^ x = k` => `x = xr ^ k`. Map stores frequencies of prefix XORs. Don't forget `mpp[0] = 1`!
