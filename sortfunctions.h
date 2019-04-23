#ifndef SORT_FUNCTION_H
#define SORT_FUNCTION_H

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

int  partition ( std::vector<int>& , int, int );
void quickSortIterative ( std::vector<int>& , int, int );
void selectionSort ( std::vector<int>& );
void bubbleSort ( std::vector<int>& );

#endif //SORT_FUNCTION_H
