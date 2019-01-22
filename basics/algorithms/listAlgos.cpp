#include <iostream>

using namespace std;

unsigned int partition(int * a, unsigned int low, unsigned int high)
{
	int pivot = a[low];

	while ( low < high )
	{
		if ( a[low] > a[high] )
			swap(a[low], a[high]);

		if ( a[low] <= pivot ) low++;
		else high--;
	}

	return low;
}

void quicksort(int * a, unsigned int low, unsigned int high)
{
	if ( low < high )
	{
		unsigned int partitioned_index = partition(a, low, high);
		quicksort(a, low, partitioned_index - 1);
		quicksort(a, partitioned_index + 1, high);
	}
}
  
void merge(int * a, int low, int mid, int high) 
{ 
    unsigned int n1 = mid - low + 1; 
    unsigned int n2 =  high - mid; 
  
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (unsigned int i = 0; i < n1; i++) L[i] = a[ low + i ];
    for (unsigned int j = 0; j < n2; j++) R[j] = a[ mid + 1 + j ]; 
  
    unsigned int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) 
    { 
        if ( L[i] <= R[j] ) a[k] = L[i++]; 
        else a[k] = R[j++]; 
        k++; 
    } 
  
    while (i < n1) 
    { 
        a[k] = L[i++]; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        a[k] = R[j++]; 
        k++; 
    } 
} 

void mergesort(int * a, unsigned int low, unsigned int high)
{
	if ( low < high )
	{
		unsigned int mid = low + (high - low)/2; // avoid overflow
		mergesort(a, low, mid);
		mergesort(a, mid + 1, high);

		merge(a, low, mid, high);
	}
}

unsigned int binarysearch(int * a, unsigned int low, unsigned int high, int elem)
{
	if ( low <= high )
	{
		unsigned int mid = low + (high - low)/2;
		if ( a[mid] == elem ) return mid;
		else if ( a[mid] > elem ) return binarysearch(a, low, mid - 1, elem);
		else return binarysearch(a, mid + 1, high, elem);
	}

	return -1;
}

int main()
{
	int a[] = { 3, 2, 5, -1, 6, 0, 9, -2 };

	const int a_size = sizeof(a)/sizeof(a[0]);
	// quicksort(a, 0, a_size - 1);
	mergesort(a, 0, a_size - 1);

	for ( unsigned int i = 0; i < a_size; i++ ) cout << a[i] << " ";
	cout << endl;

	cout << binarysearch(a, 0, a_size - 1, 5) << endl;

	return 0;
}