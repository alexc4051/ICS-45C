  #include <iostream>
using namespace std;
  #define STACK_CAPACITY 1000
  class Stack
  {
      char stacks[STACK_CAPACITY];
      bool isFull()
      {
          return counter >= STACK_CAPACITY;
      }
      void stack_error(string msg)
      {
          cerr << "ERROR: " << msg << endl;
      }
      int counter;
  public:
Stack() {counter=0;};
void push(char c)
{if (isFull())
{stack_error("Push on a full stack");
return;}
stacks[counter]=c;
counter++;
};
void pop()
{if (!isEmpty())
counter --;
else{
stack_error("POP on an empty stack");
return;}
};
char top()
{ if (isEmpty()){stack_error("TOP on an empty stack");
return '\0';}
return stacks[counter-1];};
bool isEmpty(){return counter==0;};
~Stack(){};
};
