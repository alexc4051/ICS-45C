#include <iostream>
using namespace std;
string reverse(string buf){
   string reversed(buf);
		for (int i=0; i<4; i++){reversed[i] = buf[4-i-1];}
		return reversed;}
int main ()
{
string s = "asdf";
string d = reverse(s);

    std::cout << d;


}
