#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
    public:
        MergeSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(bool (*compare)(void*, int, int)) {
			sort(compare, 0, size-1);
        }

		void sort(bool (*compare)(void*, int, int), int l, int r){
			if(l < r){
				int m = (l+r)/2;
				sort(compare, l, m);
				sort(compare, m+1, r);
				compare(elements, l, r);
			}
		}

        inline string name() { return "MergeSort"; }
};

#endif
