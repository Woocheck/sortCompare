#ifndef PRINT_TABLE_H
#define PRINT_TABLE_H

#include <string>
#include <iostream>
#include <map>
#include <vector> 


void printTableHeader( const std::map < std::string, std::string >&,
                       const std::vector<int>& );
void printTableRow( const std::string&, const std::vector<int>&, 
                    const std::vector<std::string>&,
                    const std::map < std::string, std::string >& );
int getMethodsNameSize( const std::map < std::string, std::string >& );

#endif //PRINT_TABLE_H