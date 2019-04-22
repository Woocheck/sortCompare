#include "../gtest/gtest.h"
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

#include "sortfunctions.cpp"
#include "sortfunctions.h"

std::vector<int> a { 2, 3, 14, 55, 2, 1, 7 };
std::vector<int> b { 1, 2, 2, 3, 7, 14, 55 };

TEST( SortFunctions, QuickSort ) 
{
   quickSortIterative( a, 0, std::size(a)-1 );
   EXPECT_EQ( a, b );   
}

TEST( SortFunctions, SelectionSort ) 
{
   selectionSort( a );
   EXPECT_EQ( a, b );   
}

TEST( SortFunctions, BubbleSort ) 
{  
   bubbleSort( a );
   EXPECT_EQ( a, b );   
}