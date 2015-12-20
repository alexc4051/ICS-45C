#include "Array_pochienc.h"
template
  < typename Element >
class Matrix
{private:
  int rows, cols;
  Array< Array<Element>*> m; 
public:
  Matrix<Element>( int newRows, int newCols )
    : rows( newRows ), cols( newCols ), m( rows )
  {for (int i = 0; i < rows; i++ )
      m[i] = new Array < Element >( cols ); }
  int numRows()
  { return rows; }
  int numCols()
  { return cols; }
  Array < Element > & operator [] ( int row )
  { return * m[row]; }
  void print( ostream & out )
  {for (int i = 0; i <rows; ++i)
       out << m[i] << endl; }
  friend ostream & operator << ( ostream & out, Matrix & m )
  {m.print( out );
    return out; }};
