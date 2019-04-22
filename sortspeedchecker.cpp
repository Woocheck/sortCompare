#include <iostream>
#include <cstdlib>

int main() {

   std::cout<<"Bubble sorting:"<<std::endl;
   //std::system("time ./sort 10000 b");
   std::cout<<std::endl<<"selection sorting:"<<std::endl;
   std::system("time ./sort 1000000 a");
   std::cout<<std::endl<<"Quick sorting:"<<std::endl;
   std::system("time ./sort 1000000 q");
   std::cout<<std::endl<<"STL library sorting:"<<std::endl;
   std::system("time ./sort 1000000 s");
   
   return 0;
}