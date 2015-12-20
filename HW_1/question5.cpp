#include "stack.h"
#include <iostream>
using namespace std;


int main()
{
    string line;
    cout << "Please type a string:\n";
    Stack st;
    int countlength = 0;
	string line;
	cin.getline(
    while (line)
    {
        for (int i=0; i<line.size(); i++)
        {
            st.push(line[i]);
        };
    st.push('\n');
    countlength+=line.size()+1;
    }
    for (int i=0; i<countlength ;i++)
    {cout<< st.top();
    st.pop();}
    cout<<'\n';
    return 0;
}

