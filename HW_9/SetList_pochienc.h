#include <iterator>
#include <iostream>
#include <string>
using namespace std;
template 
  <class T>
class SetList
{
	struct ListNode
	{
		ListNode(const T& newinfo,ListNode* newnext)
        :info(newinfo),next(newnext){}
		T info;
		ListNode* next;
	};
	ListNode* head;
 
public:
	class iterator 
	{
		ListNode* val;
	public:
    typedef std::forward_iterator_tag iterator_category;
    typedef iterator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef ptrdiff_t difference_type;
    iterator(ListNode* x=nullptr)
        :val(x){}
		iterator(const iterator& x)
        :val(x.val) {}
    self_type operator=(const iterator& x)
		{ 
			val=x.val; 
      return *this; 
		}
		self_type operator++()
		{ 
			val = val->next; 
      return *this; 
		}
		self_type operator++(int holder)
		{ 
			self_type temp(*this); 
      val = val->next; 
      return temp; 
		}
		reference operator*() const 
        { return val->info; }
		
    pointer operator->() const 
        { return val; }
		
    bool operator==(const self_type& rhs) const
		{
			return val == rhs.val; 
		}	
		bool operator!=(const self_type& rhs) const
		{
			return val != rhs.val; 
		}	
	};
	class const_iterator 
	{
		const ListNode* val;
	public:
    typedef std::forward_iterator_tag iterator_category;
    typedef const_iterator self_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef ptrdiff_t difference_type;
    
		const_iterator(const ListNode* newval = nullptr)
        :val(newval){}
    const_iterator(const const_iterator& x)
        :val(x.val) {}
		const_iterator(const iterator& x)
        :val(x.val){}
    const_iterator& operator=(const const_iterator& x)
		{ 
			val=x.val; 
      return *this; 
		}		
		self_type operator++()
		{ 
			val = val->next; 
      return *this; 
		}
		self_type operator++(int holder)
		{ 
			self_type temp(*this); 
      val = val->next; 
      return temp; 
		}
		reference operator*() const 
      { return val->info; }
		
    pointer operator->() const 
      { return val; }
		
    bool operator==(const self_type& rhs) const
		{
			return val == rhs.val; 
		}
		bool operator!=(const self_type& rhs) const
		{
			return val != rhs.val; 
		}
	};

	SetList() 
      : head(nullptr) {}

	SetList(const SetList& L) 
      : head(nullptr)
	{
		for ( const_iterator i = L.begin(); i!=L.end(); ++i )
			push(*i);
		reverse();
	}

	void reverse()
	{
    ListNode * result = nullptr;
    for ( ListNode * p = head; p != nullptr; p = p->next )
      result = new ListNode( p->info, result );
    head = result;
  }
	SetList& operator=(const SetList& x)
	{
    ListNode* temp = head; 
    head = x.head; 
    x.head = temp;
		return *this;
	}

  int count(const T&x)
  { for(ListNode *p = head; p!=nullptr; p=p->next)
        {if(x == p->info)
            return 1;}
    return 0;
  }

	void push(const T&x)
	{
		ListNode* temp = new ListNode(x,nullptr);
		temp->next = head;
		head = temp;
	}
	void pop()
	{
		if (head)
		{
			ListNode* newhead = head->next;
			delete head;
			head = newhead;
		}
	}

	T& front() { return *begin(); }
	
  const T& front() const { return *begin(); }

	iterator begin() 
      { return iterator(head); }
	
  iterator end() 
      { return iterator(); }
	
  const_iterator begin() const 
      { return head; }
	const_iterator end() const 
      { return const_iterator(); }
 
	~SetList() { while (!head) pop(); }
};
