#include <iostream>



void increment( int & x )
{
  x = x + 1;
}
int main()
{
  int z = 10;
  increment( z );
  increment( z );
  std::cout << z;
  return 0;
}
