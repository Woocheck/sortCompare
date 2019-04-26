#ifndef PRINT_TABLE_H
#define PRINT_TABLE_H

#include <string>
#include <iostream>
#include <map>
#include <vector> 


class Table 
{
   private:
   std::map < std::string, std::string > sortingMethods;
   std::vector<int> sortedElementsNumber {};

   public:
   Table(const std::map < std::string, std::string >& m, const std::vector<int>& e):
          sortingMethods {m}, sortedElementsNumber {e} {}; 
   ~Table(){};

   void printTableHeader();
   void printTableRow( const std::string&, const std::vector<std::string>& );
   
   private:
   int methodsNameMaxSize();
   int widthOfAllColumns();

};
#endif //PRINT_TABLE_H