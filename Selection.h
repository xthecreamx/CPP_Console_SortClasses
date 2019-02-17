#ifndef SELECTION_DEFINED
#define SELECTION_DEFINED

#include"Swap.h"

template<class type> int minIndex(type values[], int start, int end)
{
	int indexOfMin = start;

	for (int index = start + 1; index <= end; index++)
	{
		if (values[index] < values[indexOfMin])
			indexOfMin = index;
	}

	return indexOfMin;
}
template<class type> void SelectionSort(type values[], int elements)
{
	for (int curr = 0; curr < elements - 1; curr++)
	{
		Swap(values[curr], values[minIndex<type>(values, curr, elements - 1)]);
	}
}
#endif