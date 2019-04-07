#include "tester.h"
#include <iostream>

bool integersBubble(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] > array[second]) {
        swap(array[first], array[second]);
		return false;
    }
	return true;
}

bool integersQuick(void *elements, int first, int second) {
    int *array = (int*) elements;
    if (array[first] <= array[second]) {
        swap(array[first], array[second]);
		return true;
    }
	return false;
}

bool integersMerge(void *elements, int l, int r){
	int *arr = (int*) elements;
	int m = (l+r)/2;
	int n1 = m - l + 1;
	int n2 = r - m;
	int arr1[n1], arr2[n2];

	for(int i = 0; i<n1; i++)
		arr1[i] =  arr[l+i];
	for(int i = 0; i<n2; i++)
		arr2[i] = arr[m+1+i];
	
	int i = 0, j = 0, k = l;
	while(i<n1 && j<n2){
		if(arr1[i]<=arr2[j])
			arr[k] = arr1[i++];
		else
			arr[k] = arr2[j++];
		k++;
	}
	while(i<n1)
		arr[k++] = arr1[i++];
	while(j<n2)
		arr[k++] = arr2[j++];
	return true;
}


Sort* Tester::getSort(Algorithm sort, void *array, size_t size) {
    switch (sort) {
        case bubblesort: return new BubbleSort(array, size);
        case selectsort: return new SelectSort(array, size);
        case insertsort: return new InsertSort(array, size);
        case shellsort: return new ShellSort(array, size);
        case quicksort: return new QuickSort(array, size);
		case mergeSort: return new MergeSort(array, size);
        default: throw invalid_argument("Not a valid sort");
    }
}

fptr Tester::getCompare(Algorithm sort) {
    switch (sort) {
        case bubblesort: return &integersBubble;
		case selectsort: return &integersBubble;
		case insertsort: return &integersBubble;
		case shellsort: return &integersBubble;
		case quicksort: return &integersQuick;
		case mergeSort: return &integersMerge;
        default: throw invalid_argument("Not a valid comparer");
    }
}

void Tester::integerSorts(int *array, size_t size) {
    Sort* sort;
    int temp[size];

    Algorithm algorithm[] = { bubblesort, selectsort, insertsort, shellsort, quicksort, mergeSort};
    size_t numberOfAlgorithms = sizeof(algorithm) / sizeof(algorithm[0]);

    for (int i = 0; i < numberOfAlgorithms; i++) {
        copy(array, array + size, temp);
        sort = getSort(algorithm[i], temp, size);
        sort->execute(getCompare(algorithm[i]));
        ASSERT(is_sorted(temp, temp + size), "The " + sort->name() + " is not ordering all the elements");
    }
}
