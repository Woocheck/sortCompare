#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <random>

#include "./sortfunctions.h"


int main( int argc, char const *argv[] )
{
  std::vector<int> numbers {};
  numbers.resize( atoi( argv[1] ) );

  for( auto &each : numbers )
       each=std::rand()%100;

  if( *argv[2] == 's' )
  {
    std::sort( numbers.begin(), numbers.end() );
  }
  else if( *argv[2]=='b' )
  {
    bubbleSort( numbers );
  }
  else if( *argv[2] == 'a' )
  {  
    selectionSort(numbers);  
  }
  else if (*argv[2]=='q')
  {
    quickSortIterative(numbers,0,std::size(numbers)-1);
  }

  return 0;
};
