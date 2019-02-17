#ifndef INSERTION_DEFINED
#define INSERTION_DEFINED

#include"Swap.h"

template<class type> void insertItem(type values[], int start, int end)
{
	bool finished = false;
	bool moreToSearch = start != end;

	for (int curr = end; moreToSearch && !finished;)
	{
		if (values[curr] < values[curr - 1])
		{
			Swap(values[curr], values[curr - 1]);
			curr--;
			moreToSearch = start != end;
		}
		else
			finished = true;
	}
}

template<class type> void InsertionSort(type values[], int max)
{
	for (int curr = 0; curr < max; curr++)
		insertItem(values, 0, curr);
}

#endif
