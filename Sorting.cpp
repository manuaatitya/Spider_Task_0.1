/*

# Author       : Manu Aatitya R P

# Language     : C++

# HeapSort Implementation to Sort Numbers in Increasing Order in C++ using classes

# Spider Task 0.1


*/

#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void MakeHeap(int input_array[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int left = 2*i + 1; // left node = 2*i + 1
	int right = 2*i + 2; // right node = 2*i + 2

	// If left child is larger than root
	if (left < n && input_array[left] > input_array[largest])
		largest = left;

	// If right child is larger than largest so far
	if (right < n && input_array[right] > input_array[largest])
		largest = right;

	// If largest is not root
	if (largest != i)
	{
		swap(input_array[i], input_array[largest]);

		// Recursively heap the sub-tree
		MakeHeap(input_array, n, largest);
	}
}

// Heap sort Function
void HeapSort(int input_array[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		MakeHeap(input_array, n, i);

	// extract element one by one from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(input_array[0], input_array[i]);

		// call max heapify on the reduced heap
		MakeHeap(input_array, i, 0);
	}
}

// Main Function
int main()
{
    int n;
    cin>>n;
    int input_array[n];
    for(int i=0;i<n;i++)
    {
        cin>>input_array[i];
    }
    
	HeapSort(input_array, n);

	cout << "The Sorted array is:\n";
	
	for (int i=0; i<n; ++i)
		cout << input_array[i] << " ";
		
	cout << "\n";
}
