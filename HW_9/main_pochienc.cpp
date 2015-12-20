#include <iostream>
#include "MapArray_pochienc.h"
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include "SetList_pochienc.h"
using namespace std;

int main()
{
  ifstream setin("stopwords.txt");
  SetList<string> exclusion;
  for_each(istream_iterator<string>(setin),istream_iterator<string>(), [&](const string & t){exclusion.push(t);});
 
  ifstream in ("sample_doc.txt");
  MapArray<string,int> M(1000);
  for_each(istream_iterator<string>(in), istream_iterator<string>(),[&](string s){transform(begin(s), end(s), begin(s), ::tolower); if(!exclusion.count(s)) M[s]++;});
  for_each(M.begin(), M.end(), [&](pair<string, int> const & p) {cout << p.first << " : " << p.second << endl;});

  return 0;
}