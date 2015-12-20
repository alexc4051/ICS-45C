#include <iostream>
using namespace std;
int main()
{
	char * s[4];
	s[3] = '\0';
	for (int i =0; i < 4; ++i)
	{
		if (s[i] == '\0')
		cout << i;
		else if (s[i] != NULL ) 
		cout << 3;
	}
}
