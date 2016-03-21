#include <stdlib.h>
#include <iostream>

using namespace std;

/*
store_t* merge_sort (store_t* list1, store_t* list2)
{
	store_t* store;
	store_t* store_next;

	//we start with the biggest element in either list
	//then we advance this very list
	if (list1->num_items > list2->num_items)
	{
		store = list1;
		list1 = list1->next;
	}
	else
	{
		store = list2;
		list2 = list2->next;
	}

	//now we can advance both lists at the same time
	//each time the greater element between them is added to the final list
	store_next = store;
	while (list1 && list2)
	{
		if (list1->num_items > list2->num_items)
		{
			store_next->next = list1;
			list1 = list1->next;
		}
		else
		{
			store_next->next = list2;
			list2 = list2->next;
		}

		//our final list need to be advanced too
		//but only when the next element exist
		if (store_next->next) store_next = store_next->next;
	}

	//if one of the lists has come to an end we just add the other to our final list
	if (list1) store_next->next = list1;
	else if (list2) store_next->next = list2;

	return store;
}
*/

void quick_sort(int array[], const size_t size, int pivot = -1, int begin = -1, int end = -1)
{
    // base case
    if ((begin != -1) && (begin == end))
    {
        return;
    }

    // initializations
    int i = begin, j = end;
    int pivot_bck = pivot;
    int tmp = 0;

    // first call need some workarounds
    if (end == -1)
        end = j = size - 1;
    if (begin == -1)
        begin = i = 0;
    // could be improved to obtain a better pivot at initial time
    if (pivot == -1)
        pivot = pivot_bck = ((j - i) / 2) + begin;

    while ((i <= pivot_bck) && (j >= pivot_bck))
    {
        // make i and j less and greater than pivot, if possible
        if (array[i] >= array[pivot_bck])
        {
            if (array[j] <= array[pivot_bck])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;

                i++; j--;
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
            // reduce j too if it is greater than pivot
            if ((array[j] >= array[pivot_bck])) j--;
        }
    }


    // avoid useless call
    if (begin != pivot_bck)
        quick_sort(array, size, -1, begin, pivot_bck);
    // avoid infinite loop
    if (pivot_bck != begin)
        quick_sort(array, size, -1, pivot_bck, end);
}

int main(int argc, char** argv)
{
    int array[] = {5,3,1,8,4,7,2,6,9,0};

    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
        cout << array[i] << " ";
    cout << endl;
    quick_sort(array, 10);
    for (int i = 0; i < sizeof(array)/sizeof(int); i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
