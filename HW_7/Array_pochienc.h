#ifndef ARRAY_POCHIENC_H
#define ARRAY_POCHIENC_H
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

inline namespace exceptions 
{struct MyException : public exception 
  {virtual const char * message() const throw() 
    {	return "Out of Bounds!\n";	}	};}

template
  < typename Type >
class Array
{private:
  int len;
  Type * buf;
public:
  Array<Type>( int newLen )
    : len( newLen ), buf( new Type[newLen] )
  {  }
  Array<Type>( Array & l )
    : len( l.len ), buf( new Type[l.len] )
  {for ( int i = 0; i < l.len; i++ )
      buf[i] = l.buf[i];}
  struct MyException{};
  int length()
  {  return len;  }
  Type & operator [] ( int i )
    throw (exceptions::MyException)
  {if( i < 0 || i > len )
      throw exceptions::MyException();
    return buf[i]; }
  void print( ostream & out )
  {for (int i = 0; i < len; i++)
      out << setw(5) << buf[i];  }
  friend ostream & operator << ( ostream & out, Array & a )
  {a.print( out );
    return out; }
  friend ostream & operator << ( ostream & out, Array * ap )
  {ap->print( out );
    return out; } };
#endif