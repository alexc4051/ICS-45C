#include "stack.h"
#include <iostream>
using namespace std;

int main(){
    while(true){
        string line;
        cout << "Please type a string: ";
        cin.getline(line);
        Stack st;
        for (int i=0; i<line.size(); i++)
            {st.push(line[i]);};
        for (int i=0; i<line.size(); i++)
            {
            cout<< st.top();
            st.pop();
            }
        cout << endl;
        }
    return 0;
}

