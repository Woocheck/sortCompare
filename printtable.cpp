#include <array>
#include <string>
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector> 
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <fstream>

#include "printtable.h"

void Table::printTableHeader()
{
   int widthOfTable = widthOfAllColumns();

   std::cout << std::setfill( '-' ) << std::setw(widthOfTable) << std::endl;
   std::cout << std::setw( methodsNameMaxSize() + 1) <<
             " Method Name";
   
   int widthOfColumn {2};
   for( auto column : sortedElementsNumber )
   {      
      widthOfColumn = std::size( std::to_string( column ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      std::cout << std::setw( widthOfColumn + 2 ) << std::internal << 
                std::to_string( column ) << " ";
   }
   std::cout << std::endl;
};

void Table::printTableRow( const std::string& methodName, 
                           const std::vector<std::string>& results )
{
   int widthOfColumn {2};
   widthOfColumn += methodsNameMaxSize();
   if(widthOfColumn < 13) widthOfColumn = 13;
   std::cout << std::setfill( ' ' ) << std::setw(widthOfColumn) << methodName;

   for( int i = 0; i < std::size(sortedElementsNumber); i++ )
   {      
      widthOfColumn = std::size( std::to_string( sortedElementsNumber.at(i) ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      std::cout << std::setw( widthOfColumn + 2 ) << std::internal << 
                results.at(i);
   }
    
    std::cout << std::endl;
};

int Table::methodsNameMaxSize()
{
   int maxSize {0};
   for( const auto& name : sortingMethods )
   {
      if( maxSize < std::size( name.second ) ) maxSize = std::size( name.second );
   }

   return maxSize;
};

int Table::widthOfAllColumns()
{
   int result {2};
   int widthOfColumn {2};

   widthOfColumn += methodsNameMaxSize();
   if(widthOfColumn < 13) widthOfColumn = 13;

   result += widthOfColumn;
   
   for( auto column : sortedElementsNumber )
   {      
      widthOfColumn = std::size( std::to_string( column ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      result += widthOfColumn;
      result += 1;
   }

   return result;
};
