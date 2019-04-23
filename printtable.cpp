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

void printTableHeader( const std::map < std::string, std::string >& tempMethodsList,
                       const std::vector<int>& sortedElementsNumber)
{
   
   int widthOfTable {2};
   int widthOfColumn {2};

   widthOfColumn += getMethodsNameSize( tempMethodsList );
   if(widthOfColumn < 13) widthOfColumn = 13;

   widthOfTable += widthOfColumn;
   
   for( auto column : sortedElementsNumber )
   {      
      widthOfColumn = std::size( std::to_string( column ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      widthOfTable += widthOfColumn;
      widthOfTable += 1;
   }
   std::cout << std::setfill( '-' ) << std::setw(widthOfTable) << std::endl;
   std::cout << std::setw( getMethodsNameSize( tempMethodsList ) + 1) <<
             " Method Name";
   for( auto column : sortedElementsNumber )
   {      
      widthOfColumn = std::size( std::to_string( column ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      std::cout << std::setw( widthOfColumn + 2 ) << std::internal << 
                std::to_string( column ) << " ";
   }
   std::cout << std::endl;
};

void printTableRow( const std::string& methodName, const std::vector<int>& sortedElementsNumber, 
                    const std::vector<std::string>& results,
                    const std::map < std::string, std::string >& tempMethodsList )
{
   int widthOfColumn {2};
   widthOfColumn += getMethodsNameSize( tempMethodsList );
   if(widthOfColumn < 13) widthOfColumn = 13;
   std::cout << std::setfill( ' ' ) << std::setw(widthOfColumn) 
             << methodName;
   for( int i = 0; i < std::size(sortedElementsNumber); i++ )
   {      
      widthOfColumn = std::size( std::to_string( sortedElementsNumber[i] ) ); 
      if(widthOfColumn < 13) widthOfColumn = 13;
      std::cout << std::setw( widthOfColumn + 2 ) << std::internal << 
                results[i];
   }
    
    std::cout << std::endl;

};

int getMethodsNameSize( const std::map < std::string, std::string >& methodsList)
{
   int maxSize {0};
   for( const auto& name : methodsList )
   {
      if( maxSize < std::size( name.second ) ) maxSize = std::size( name.second );
   }

   return maxSize;
};
