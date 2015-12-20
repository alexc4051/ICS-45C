#include <iostream>
using namespace std;
class String
  {private:
    bool inBounds( int i )
    { return i >= 0 && i < strlen(buf);}
    static int strlen(const char *s)
	{int len = 0;
	  for (int i=0; s[i]; ++i)
			++len;
	  return len;}
    static char *strcpy(char *dest, const char *src)
	{for (int i=0; dest[i] = src[i]; ++i){}
		return dest;}	    
	static char *strdup(const char *src)
	{char * copy = new char[strlen(src)];
		return strcpy(copy,src);	}
    static int strcmp(const char *left, const char *right)
	{for (int i=0; left[i] != right[i]; i++)
		{if (left[i] < right[i]) 
					return -1;
				return 1;}
	if (strlen(left) == strlen(right))
		return 0;	}
    char * buf; 
  public:
    String( const char * s = "")
    {buf = strdup(s);	}
    String( const String & s )
    {    buf = strdup(s.buf);	}
    String operator = ( const String & s )
    {if (strlen(s.buf) != strlen(buf))
		{delete[] buf;
    	buf = new char[strlen(s.buf)];		}
		for (int i=0; buf[i] = s.buf[i]; i++){}
		return *this;	}
    char & operator [] ( int index )
    {if (index < strlen(buf))
			{return buf[index];}
	else{ cout << "Out of Bounds!" << endl;
		return buf[strlen(buf)];}}
    int size()
    {return strlen(buf);}
    String reverse()
    {String reversed(buf);
		for (int i=0; reversed.buf[i] = buf[strlen(buf)-i-1]; i++){	}	
		return reversed;}
    int indexOf( const char c )
    {for (int i=0; i<strlen(buf); i++)
		{if (buf[i] == c)
			return i;}	}
	int indexOf( const String pattern )
	{	if (strlen(pattern.buf) == 0)
			{cout << "Not Found" << endl;
			return -1;}
		for (int i=0; i<strlen(buf);i++)
		{if (buf[i] == pattern.buf[0])
				{for (int j=1;j<strlen(pattern.buf);j++)
						{if(buf[i+j] != pattern.buf[j] || buf[i+j] == '\0')
						return -1;}
				return i;}}	}
    bool operator == ( const String s )
    {if (strcmp(buf, s.buf) != 0)
    		return false;
    	return true;}
    bool operator != ( const String s )
    {if (strcmp(buf,s.buf) == 0)
			return false;
		return true;}
    bool operator > ( const String s )
    {if (strcmp(buf,s.buf) > 0)
			return true;
		return false;}
    bool operator < ( const String s )
	{return ! operator > (s);}
    bool operator <= ( const String s )
    {if (strcmp(buf,s.buf) <= 0)
			return true;
		return false;}
    bool operator >= ( const String s )
    {return ! operator <= (s);	}
    String operator + ( const String s )
    {char * other = new char[strlen(buf) + strlen(s.buf)];
		for (int i =0; other[i] = buf[i]; ++i){		}
		for (int i = 0; other[i + strlen(buf)] = s.buf[i]; ++i){		}
		return other;}
    String operator += ( const String s )
    {char * other = new char[strlen(buf) + strlen(s.buf)];
		for (int i =0; other[i] = buf[i]; ++i){		}
		for (int i = 0; other[i + strlen(buf)] = s.buf[i]; ++i){		}
    	delete[] buf;
    	buf = new char[strlen(other)];
    	for (int i=0; buf[i] = other[i]; ++i){		}
    	delete [] other;
    	return buf;  }
    void print( ostream & out )
    {out << buf;}
    void read( istream & in )
    {cin >> buf;}
    ~String()
    {delete[] buf;}
  };
  ostream & operator << ( ostream & out, String str )
	{ str.print( out );
	  return out;}
  istream & operator >> ( istream & in, String & str )
  {str.read( in );
  return in;}
