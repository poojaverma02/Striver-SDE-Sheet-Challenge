# Documentation Guide

This guide defines the standard structure and style for documenting solutions in the Striver SDE Sheet Challenge repository.

## 1. Folder Structure
To scale well for all 45 challenge days, organize solutions into day-wise directories. Keep the markdown explanation side-by-side with the solution code for quick referencing during revision.

```text
Striver-SDE-Sheet-Challenge/
├── Day_01_Arrays/
│   ├── nextPermutation.cpp
│   ├── nextPermutation.md
│   ├── setMatrixZero.cpp
│   └── setMatrixZero.md
├── Day_02_Arrays_Part_II/
├── ...
└── DOCUMENTATION_GUIDE.md
```

## 2. Naming Convention
- **C++ Code File:** `camelCase.cpp` (e.g., `nextPermutation.cpp`)
- **Explanation File:** `camelCase.md` (e.g., `nextPermutation.md`)
- Both files must share the exact same base name and reside in the same day-folder.

## 3. Markdown Template
Use the exact template below for every explanation file:

```markdown
# Problem Name

## Key Idea
(1-2 lines summarizing the core logic)

## Pattern
(Short phrase identifying the DSA pattern, if applicable)

## Approach
- **(Action)** (Step 1)
- **(Action)** (Step 2)
- **(Action)** (Step 3)

## Edge Case
(1-liner for critical edge cases, if applicable)

## Complexity
Time: O(?)
Space: O(?)

## Revision Note
(Mini-Trace or 1 line summarizing the core trick to remember)
```

## 4. Writing Rules & Style Guidelines
- **Maximum Length:** Keep the entire explanation under 120 words.
- **Focus:** Discuss *only* the optimal solution. Do not include brute force discussions or lengthy theory.
- **Visuals:** Use a "Mini-Trace" in the Revision Note when possible (e.g., `[2, 1, 5, 4, 3] -> dip at 1 -> swap -> reverse -> [2, 3, 1, 4, 5]`).
- **Formatting:** Use concise bullet points for the approach. **Bold** the key action verbs (e.g., **Traverse**, **Swap**, **Reverse**) for skim-reading.
- **Tone:** Professional, crisp, and revision-friendly. Write as if creating serious, quick-glance student notes.
