#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(void *elements, size_t size) : Sort(elements, size) {}

        void execute(bool (*compare)(void*, int, int)) {
			for(int h = size/2; h > 0; h /= 2){
				for(int i = h; i < size; i++){
					int j = i;
					while(j >= h && !compare(elements, j-h, j)) j = j-h;
				}
			}
        }

        inline string name() { return "ShellSort"; }
};

#endif
