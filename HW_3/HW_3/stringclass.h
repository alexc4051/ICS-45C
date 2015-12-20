#include <iostream>
using namespace std;
#define MAXLEN 128
  class String
  {
  private:
    bool inBounds( int i )
    { return i >= 0 && i < strlen(buf);}
    static int strlen(const char *s)
		{ int len = 0;
		  for (int i=0; s[i]; ++i)
				++len;
		  return len;}
    static char *strcpy(char *dest, const char *src)
		{for (int i=0; dest[i] = src[i]; ++i){}
			return dest;}
    static char *strcat(char *dest, const char *src)
		{strcpy(dest+strlen(dest), src);
			return dest;}
    static int strcmp(const char *left, const char *right)
	{if (strlen(left) == strlen(right))
		{for (int i=0; left[i] != right[i]; i++)
		{if (left[i] < right[i]) 
					return -1;
				return 1;}
		return 0;}
		else{if (strlen(left) < strlen(right))
				return -1;
			return 1;}}
	static char *strchr(const char *str, int c)
	{for (int i=0; i<strlen(str); i++)
		{if (str[i] == c)
			return (char *) &str[i];}}
    char buf[MAXLEN];
  public:
    String( const char * s = "")
	{strcpy(buf, s);}
	String( const String & s )
	{strcpy(buf, s.buf);}
    String operator = ( const String & s )
	{for (int i=0; buf[i] = s.buf[i]; i++){}}
    char & operator [] ( int index )
	{	return buf[index];	}  
	int size()
	{return strlen(buf);}
    String reverse() 
	{String reversed(buf);
		for (int i=0; reversed.buf[i] = buf[strlen(buf)-i-1]; i++){}	return reversed;}
	int indexOf( const char c )
    {for (int i=0; i<strlen(buf); i++)
		{if (buf[i] == c)
		return i;}}
	int indexOf( const String pattern )
	{for (int i=0; i<strlen(buf);i++)
		{if (buf[i] == pattern.buf[0])
			{for (int j=1;j<strlen(pattern.buf);j++)
				{if(buf[i+j] != pattern.buf[j] || buf[i+j] == '\0')
				return -1;}
			return i;}}} 
	bool operator == ( const String s )
	{if (strcmp(buf,s.buf) !=0)
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
    {if (strcmp(buf,s.buf) < 0)
		return true;
	return false;}
	bool operator <= ( const String s )
	{if (strcmp(buf,s.buf) <= 0)
		return true;
	return false;}
	bool operator >= ( const String s )
	{if (strcmp(buf,s.buf) >= 0)
		return true;
	return false;}
    String operator + ( const String s )
    {String other(buf);
    return strcat(other.buf,s.buf);}
    String operator += ( const String s )
    {	return strcat(buf,s.buf);}
    void print( ostream & out )
	{out << buf;}
    void read( istream & in )
	{in >> buf;}
	~String(){}
  };
  ostream & operator << ( ostream & out, String str )
  {str.print(out);
  return out;}
  istream & operator >> ( istream & in, String & str )
  {str.read( in );
  return in;}

  
