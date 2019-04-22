
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

    
int partition (std::vector<int>& table, int startingIndex, int endingIndex) 
{ 
  int pivot = table.at(endingIndex); 
  int i = (startingIndex - 1); 

  for (int j = startingIndex; j <= endingIndex- 1; j++) 
  { 
      if (table.at(j) <= pivot) 
      { 
          i++; 
          std::swap (table.at(i), table.at(j)); 
      } 
  } 
  std::swap (table[i + 1], table[endingIndex]); 
  return (i + 1); 
} 


void quickSortIterative ( std::vector<int>& table, int startingIndex,
                         int endingIndex ) 
{ 
  std::vector<int> stack; 
  stack.resize( endingIndex - startingIndex + 1 );
  int topOfStack = -1; 

  stack[ ++topOfStack ] = startingIndex; 
  stack[ ++topOfStack ] = endingIndex; 

  while ( topOfStack >= 0 ) 
  { 
      endingIndex = stack[ topOfStack-- ]; 
      startingIndex = stack[ topOfStack-- ]; 
 
      int p = partition( table, startingIndex, endingIndex ); 

      if ( p-1 > startingIndex ) 
      { 
          stack[ ++topOfStack ] = startingIndex; 
          stack[ ++topOfStack ] = p - 1; 
      } 

      if ( p+1 < endingIndex ) 
      { 
          stack[ ++topOfStack ] = p + 1; 
          stack[ ++topOfStack ] = endingIndex;
      } 
  }
};


void selectionSort( std::vector<int>& numbers )
{
  for(int indexFirstElement = 0 ; 
      indexFirstElement < std::size( numbers ) - 1 ; 
      indexFirstElement++ )
  {
    int indexMinimalElement = indexFirstElement ;
    for( int index = indexFirstElement + 1 ; index < std::size( numbers ); index++ )
    { 
      if( numbers[index] < numbers[ indexMinimalElement ])
      {
        indexMinimalElement = index;
      }    
    }
    std::swap( numbers.at( indexMinimalElement ), numbers.at( indexFirstElement ) );
  }  
};


void bubbleSort( std::vector<int>& numbers )
{
  bool isChanged;
  do
  {
    isChanged =false;
    for( int i=1; i < numbers.size(); i++ )
     if( numbers[i-1] > numbers[i] )
     {
       auto t=numbers[i];
       numbers[i]=numbers[i-1];
       numbers[i-1]=t;
       isChanged=true;
     }
  } while ( isChanged );
};
