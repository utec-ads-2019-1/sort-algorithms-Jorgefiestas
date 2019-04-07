#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(bool (*compare)(void*, int, int)) {
			sort(compare, 0, size-1);
        }

		void sort(bool (*compare)(void*, int, int), int l, int r){
			int i = l;
			if(l < r){	
				for(int j = l; j<r; j++){
					if(compare(elements, j, r)){
						compare(elements, r, j);
						compare(elements, j, i);
						i++;
					}
				}
				compare(elements, r, i);
				sort(compare, l, i-1);
				sort(compare, i+1, r);
			}
		}

        inline string name() { return "QuickSort"; }
};

#endif

