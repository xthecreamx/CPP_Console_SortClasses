#ifndef MERGE_DEFINED
#define MERGE_DEFINED

template<class type> void Merge(type values[], int lFirst, int lLast, int rFirst, int rLast)
{
	type tempArray[MAX_VALUES];

	//2 copies of lfirst to copy elements from temp to original array & to help fill out the temp array
	int index = lFirst; //curr index of temp array 
	int saveFirst = lFirst; //index to start copying to original array.

	while ((lFirst <= lLast) && (rFirst <= rLast)) // empty set represented by first > last
	{
		//Fill the temp array according to smallest in pairs
		if (values[lFirst] < values[rFirst])
		{
			tempArray[index] = values[lFirst];
			lFirst++;
		}
		else
		{
			tempArray[index] = values[rFirst];
			rFirst++;
		}
		index++;
	}
		//Here 1/2 arrays will be empty so we just copy remaining items from the nonempty array
		while (lFirst <= lLast)
		{
			tempArray[index] = values[lFirst];
			lFirst++;
			index++;
		}

		while (rFirst <= rLast)
		{
			tempArray[index] = values[rFirst];
			rFirst++;
			index++;
		}

		//copy from temp array to original
		for (index = saveFirst; index <= rLast; index++)
			values[index] = tempArray[index];
	}


template<class type> void MergeSort(type values[], int first, int last)
{
	if (first < last) // If first = last then subset of 1 element
	{
		//split 
		int middle = (first + last) / 2;

		//sort by recursion in which splitting & merging of data is intermingled
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);

		//combine sorted halves of array 
		Merge(values, first, middle, middle + 1, last);
			
	}
}
#endif
