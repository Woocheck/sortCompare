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

std::map < std::string, std::string > sortMethodsInitialisation();
std::string getCommand( int , std::string );
std::string getResult();

int main() {

   std::map < std::string, std::string > sortingMethods;
   std::vector<int> sortedElementsNumber{ 1000, 10000, 50000 };
   sortingMethods = sortMethodsInitialisation();
   
   printTableHeader(sortingMethods, sortedElementsNumber );

   for( const auto& [ methodArgument, methodName ]: sortingMethods )
   {
      std::vector<std::string> result;
      

      for( auto elements : sortedElementsNumber )
      {         
         
         std::string commandLine {};
         commandLine = getCommand( elements, methodArgument );

         system(commandLine.c_str());

         result.push_back( getResult() );
         
      }
      printTableRow( methodName, sortedElementsNumber, result, sortingMethods );
   }
   std::cout << std::endl;
   
   return 0;
}

std::map < std::string, std::string > sortMethodsInitialisation()
{
   std::map < std::string, std::string > tempMethodsList;
   tempMethodsList[ "b" ] = "Bubble sorting";
   tempMethodsList[ "a" ] = "Selection sorting";
   tempMethodsList[ "q" ] = "Quick sorting";
   tempMethodsList[ "s" ] = "STL library sorting";

   return tempMethodsList;
};

std::string getCommand( int elementsNumber , std::string argument )
{
   std::string commandLine { "( /usr/bin/time -f \"%E\" ./sort " };
   
   commandLine += std::to_string( elementsNumber );
   commandLine += " ";
   commandLine += argument;
   commandLine += " ) 2> tmp.txt";

   return commandLine;
};

std::string getResult()
{
   std::ifstream plik;
   plik.open( "tmp.txt" );
   std::string sortingTime {};
   plik >> sortingTime;
   plik.close();

   return sortingTime;
};

