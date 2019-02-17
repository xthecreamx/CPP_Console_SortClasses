#ifndef BUBBLE_DEFINED
#define BUBBLE_DEFINED

#include"Swap.h"

template<class type> void bubbleUp(type values[], int start, int end)
{
	for (int index = end; index > start; index--)
	{
		if (values[index] < values[index - 1])
			Swap(values[index], values[index - 1]);
	}
}
template<class type> void BubbleSort(type values[], int elements)
{
	for (int curr = 0; curr < elements - 1; curr++)
		bubbleUp(values, curr, elements - 1);
}
#endif
