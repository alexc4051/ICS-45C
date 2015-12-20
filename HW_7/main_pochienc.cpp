#include "Matrix_pochienc.h"
#include "Array_pochienc.h"
template
  < class T >
void fillMatrix( Matrix <T> & m )
{int i, j;
  for ( i = 0; i < m.numRows(); i++ )
    m[i][0] = T();
  for ( j = 0; j < m.numCols(); j++ )
    m[0][j] = T();
  for ( i = 1; i < m.numRows(); i++ )
    for ( j = 1; j < m.numCols(); j++ )
    {m[i][j] = T(i * j);} }
int main()
{try{
    Matrix < int > m(10,5);
    fillMatrix( m );
    cout << m;
    Matrix < double > M(8,10);
    fillMatrix( M );
    cout << M;
    cout << "Index 5 of m: " << m[5] << endl;
    cout << "Index 17 of m: " << M[17];
    cout << "Index 16 for m: " << m[16];
    }
  catch (exceptions::MyException & e)
  {  cerr << e.message() << endl;  } }
