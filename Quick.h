#ifndef QUICK_DEFINED
#define QUICK_DEFINED

#include"Swap.h"

template<class type> void split(type values[], int first, int last, int& splitPosition)
{
	// split value is first value of set
	type splitVal = values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++; //start division of array without splitVal
	do
	{
		onCorrectSide = true;

		//Incrementing first for index where element > splitVal
		while (onCorrectSide)
		{
			if (values[first] > splitVal)
			{
				onCorrectSide = false;
			}
			else
			{
				first++;
				onCorrectSide = (first <= last);
				// If first greater than last then values[first] > splitVal
			}
		}

		onCorrectSide = (first <= last);

		//Incrementing last for index where element <= splitVal
		while (onCorrectSide)
		{
			if (values[last] <= splitVal)
			{
				onCorrectSide = false;
			}
			else
			{
				last--;
				onCorrectSide = (first <= last);
			}
		}

		if (first < last) //< & not <= because Swapping the same index does nothing
		{
			Swap(values[first], values[last]);
			//At this point , it is known that first & last elements are in correct position
			first++;
			last++;
		}
	} while (first <= last);

	//In the end , splitPoint = index of last number <= splitVal
	splitPosition = last;
	Swap(values[saveFirst], values[splitPosition]);
}

template<class type> void QuickSort(type values[], int first, int last)
{
	if (first < last) //At least 2 elements in a set
	{
		int splitPoint;

		split(values, first, last, splitPoint);

		QuickSort(values, first, splitPoint - 1);
		QuickSort(values, splitPoint + 1, last);
	}
}
#endif
