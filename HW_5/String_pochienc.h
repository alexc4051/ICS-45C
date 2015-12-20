#include <iostream>
using namespace std;
 class String
  {private:
    bool inBounds( int i )
    { return i >= 0 && i < length();}
    struct ListNode
    {char info;
      ListNode * next;
      ListNode(char newInfo, ListNode * newNext)
        : info( newInfo ), next( newNext )
      {      }
      static ListNode * stringToList(const char *s)
    	{	return s[0] == '\0' ? nullptr: new ListNode(s[0], stringToList(s+1));}
      static ListNode * copy(ListNode * L)
      		{	return !L ? nullptr: new ListNode(L-> info, copy(L-> next));}		
      static bool equal(ListNode * L1, ListNode * L2)
            {  return (L1 == nullptr && L2 == nullptr) ? true: (L1 != L2) ? false: equal(L1 -> next, L2 -> next);  }
      static ListNode * concat(ListNode * L1, ListNode * L2)
        { return L1 == nullptr ? copy( L2 ) : new ListNode( L1->info, concat( L1->next, L2 ) ); }
      static int compare(ListNode * L1, ListNode * L2)
      	  {return (L1== nullptr && L2!= nullptr) ? -1 : (L1 != nullptr && L2 == nullptr) ? 1: (L1 == nullptr && L2 == nullptr) ? 0: (L1->info < L2->info)? -1: (L1->info > L2->info) ? 1 : compare(L1 -> next, L2 -> next);  }
      static void deleteList(ListNode * L)
     { ListNode *temp;
    for (ListNode * p = L; p != nullptr; )
    {temp = p;
    p = p-> next;
    delete temp;}}
      static int length(ListNode * L)      
        {return L == nullptr ? 0: 1+length(L-> next);}};
    ListNode * head; 
  public:
    String( const char * s = "")
    {	head = ListNode::stringToList(s); }
    String( const String & s )
    { head = ListNode::copy(s.head); }
    String operator = ( const String & s )
    { ListNode::deleteList(head);
      head = ListNode::copy(s.head); 
      return *this;}
    char & operator [] ( const int index )
    {   if (!inBounds(index))
    { cout << "Out of Bounds" << endl;
      return head->info;}
    int count = 0;
    for (ListNode *p = head; p!= nullptr; p = p-> next)
    {if (count == index)
        {return p->info;}
      count ++;}}
    int length() const 
    {return ListNode::length(head);}
    int indexOf( char c ) const
    {int count =0;
    for (ListNode *p = head; p != nullptr; p= p->next)
    { if(p->info == c) 
    return count;
    count++; }
    return -1;}
    bool operator == ( const String & s ) const
    {return ListNode::equal(head,s.head);}
    bool operator < ( const String & s ) const
    {if(ListNode::compare(head,s.head) < 0)
      {return true;}
    return false;}
    String operator + ( const String & s ) const
    { String temp;
      temp.head = ListNode::copy(ListNode::concat(head,s.head));
      return temp; }
    String operator += ( const String & s )
    { ListNode *newhead;
    newhead = ListNode::concat(head,s.head);
    ListNode::deleteList(head);
    head = ListNode::copy(newhead);
    ListNode::deleteList(newhead);
    return *this; }
    void print( ostream & out )
    {for ( ListNode * p = head; p != nullptr; p = p->next )
      out << p->info;}
    void read( istream & in )
    {char s[256]; 
    in >> s;
    ListNode::deleteList(head);
    head = ListNode::stringToList(s);    
    }
    ~String()
    { ListNode::deleteList(head);  }
  };
  ostream & operator << ( ostream & out, String str )
  { str.print( out );
  return out;  }
  istream & operator >> ( istream & in, String & str )
  {str.read( in );
  return in; }