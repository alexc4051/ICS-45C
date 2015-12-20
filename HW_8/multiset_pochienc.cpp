#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ifstream num("rand_numbers.txt");
  ofstream even("even_pochienc.txt");
  ofstream odd("odd_pochienc.txt");
  vector<int> evens;
  vector<int> odds;
  
  for_each(istream_iterator<string>(num), istream_iterator<string>(),[&](const string & t){stoi(t)%2 == 0 ? evens.push_back(stoi(t)): odds.push_back(stoi(t));});
  sort(begin(evens),end(evens));
  sort(begin(odds),end(odds));
  copy (begin(evens),end(evens), ostream_iterator<int>(even,"\n"));
  copy (begin(odds),end(odds), ostream_iterator<int>(odd," "));
  
	return 0;
}

