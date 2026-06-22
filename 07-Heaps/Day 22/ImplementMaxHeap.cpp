// T.C: Insert(val): Inserting and Heapifying upwards contribute to O(logN) time.
// Get Maximum(): Constant time operation, i.e., O(1).
// Extract Maximum(): Involves Heapifying downwards contributing to O(logN) time.
// Heap Size(): Constant time operation, i.e., O(1).
// Is Empty(): Constant time operation, i.e., O(1).
// Change Key(ind, val): Involves heapifying which takes O(logN) time.
// S.C: O(N) for storing the max-heap in a list.
// Question Link: https://takeuforward.org/plus/dsa/problems/implement-max-heap?source=strivers-sde-sheet

class Solution {
private:
    vector<int> arr; // list to store the max-heap
    int count; // to store the count of elements in max-heap
    
    // Function to recursively heapify the array upwards
    void heapifyUp(int ind) {
        int parentInd = (ind - 1)/2; 

        // If current index holds larger value than the parent
        if(ind > 0 && arr[ind] > arr[parentInd]) {
            // Swap the values at the two indices
            swap(arr[ind], arr[parentInd]);
            
            // Recursively heapify the upper nodes
            heapifyUp(parentInd);
        } 

        return;
    }
    
    // Function to recursively heapify the array downwards
    void heapifyDown(int ind) {
        int n = arr.size(); // Size of the array

        // To store the index of largest element
        int largestInd = ind; 

        // Indices of the left and right children
        int leftChildInd = 2*ind + 1, rightChildInd = 2*ind + 2;
        
        // If the left child holds larger value, update the largest index
        if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) 
            largestInd = leftChildInd;

        // If the right child holds larger value, update the largest index
        if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) 
            largestInd = rightChildInd;

        // If the largest element index is updated
        if(largestInd != ind) {
            // Swap the largest element with the current index
            swap(arr[largestInd] , arr[ind]);

            // Recursively heapify the lower subtree
            heapifyDown(largestInd);
        }

        return; 
    }
    
public:
    // Method to intialize the max-heap data structure
    void initializeHeap(){
        arr.clear();
        count = 0;
    }
    
    // Method to insert a given value in the max-heap
    void insert(int key){
        // Insert the value at the back of the list 
        arr.push_back(key);
        
        // Heapify upwards
        heapifyUp(count);
        count = count+1; // Increment the counter;
        
        return;
    }
        
    // Method to change the value at a given index in max-heap
    void changeKey(int index, int new_val){
        // If the current value is replaced with a larger value
        if(arr[index] < new_val) {
            arr[index] = new_val;
            heapifyUp(index);
        }

        // Otherwise (if the current value is replaced with smaller value)
        else {
            arr[index] = new_val;
            heapifyDown(index);
        }

        return;
    }
    
    // Method to extract the maximum value from the max-heap
    void extractMax(){
        int ele = arr[0]; // maximum value in the heap
        
        // Swap the top value with the value at last index
        swap(arr[0], arr[count-1]); 
        
        arr.pop_back(); // Pop the maximum value from the list
        count = count - 1; // Decrement the counter
        
        // Heapify the root value downwards
        heapifyDown(0);
    }
    
    // Method to return if the max-heap is empty
    bool isEmpty(){
        return (count == 0);
    }
    
    // Method to return the maximum value in the max-heap
    int getMax(){
        // Return the value stored at the root
        return arr[0];
    }
    
    // Method to return the size of max-heap
    int heapSize(){
        return count;
    }
};