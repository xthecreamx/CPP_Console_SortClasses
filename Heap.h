#ifndef HEAP_DEFINED
#define HEAP_DEFINED

#include"Swap.h"

template<class type> void ReHeapDown(type values[], int root, int bottom)
{
	int maxChild;
	int leftChild = (root * 2) + 1;
	int rightChild = (root * 2) + 2;

	if (leftChild <= bottom) //leaf node check
	{
		//Figure out larger child for comparision
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (values[leftChild] <= values[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}

		// maxChild comparision with root 
		if (values[root] < values[maxChild])
		{
			Swap(values[root], values[maxChild]);
			ReHeapDown(values, maxChild, bottom);
		}
	}
}

template<class type> void HeapSort(type values[], int max)
{
	//Turning unsorted array to Heap by establishing order property starting from first non-leaf node. (MAX / 2) - 1 represents the subtrees with roots that arent leafs.
	for (int index = (max / 2) - 1; index >= 0; index--)
		ReHeapDown(values, index, max - 1);

	//Sorting array
	for (int index = max - 1; index >= 1; index--)
	{
		Swap(values[0], values[index]);
		ReHeapDown(values, 0, index - 1);
	}
}
#endif
