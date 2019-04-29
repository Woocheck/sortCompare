#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <vector> 
#include <iomanip>
#include <algorithm>
#include <iterator>


#include "printtable.h"

std::map < std::string, std::string > sortMethodsInitialisation();
std::string getCommand( int , std::string );
std::string getResult();
void removeTempFile();

int main() {

   std::map < std::string, std::string > sortingMethods;
   std::vector<int> sortedElementsNumber{ 1000, 10000, 20000 };
   sortingMethods = sortMethodsInitialisation();

   Table table(sortingMethods,sortedElementsNumber);
   table.printTableHeader();
   

   for( const auto& [ methodArgument, methodName ]: sortingMethods )
   {
      std::vector<std::string> singleMethodResults;
   
      for( auto elements : sortedElementsNumber )
      {       
         system(getCommand( elements, methodArgument ).c_str() );
         singleMethodResults.push_back( getResult() );
      }

      table.printTableRow( methodName, singleMethodResults );
   }
   std::cout << std::endl;
   
   removeTempFile();
   
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
   std::stringstream commandLine {};
   
   commandLine << "( /usr/bin/time -f \"%E\" ./sort " << elementsNumber 
               << " " << argument << " ) 2> tmp.txt";

   return commandLine.str();
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

void removeTempFile()
{
   try
   {
      system("rm tmp.txt");

   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << '\n';
   }
 };  
   
