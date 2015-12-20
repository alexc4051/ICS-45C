#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template
    <typename T, typename U>
class MapArray
{
    
    int sz;
    pair<T,U>*buf;
    int count;
public:
    struct iterator
    {
         typedef std::forward_iterator_tag iterator_category;
         typedef iterator self_type;
         typedef std::pair<T, U> value_type;
         typedef std::pair<T, U> &reference;
         typedef std::pair<T, U> *pointer;
         typedef ptrdiff_t difference_type;
    private:
        pointer buf;
    public:
        iterator(pointer ptr) 
            : buf(ptr) { }
    		iterator(const iterator& x)
            :buf(x.buf) {}
        self_type operator++() 
            { ++buf; 
              return *this; }
        self_type operator++(int postfix) 
            { self_type cpy = *this; 
              buf++; return cpy; }
        reference operator*() 
            { return *buf; }
        pointer operator->() 
            { return buf; }
        bool operator==(const self_type& rhs) const 
            { return buf == rhs.buf; }
        bool operator!=(const self_type& rhs) const 
            { return buf != rhs.buf; }
    };

    class const_iterator
    {
    public:
         typedef std::forward_iterator_tag iterator_category;
         typedef iterator self_type;
         typedef std::pair<T, U> value_type;
         typedef std::pair<T, U> &reference;
         typedef std::pair<T, U> *pointer;
         typedef ptrdiff_t difference_type;
    private:
        pointer buf;
    public:
        const_iterator(pointer ptr) 
            : buf(ptr) { }
        const_iterator(const const_iterator& x)
            : buf(x.buf) { }
		    const_iterator(const iterator& x)
            : buf(x.buf){}
        self_type operator++() 
            { ++buf; 
              return *this; }
        self_type operator++(int postfix) 
            { self_type cpy = *this; 
              buf++; return cpy; }
        const reference operator*() 
            { return *buf; }
        const pointer operator->() 
            { return buf; }
        bool operator==(const self_type& rhs) const 
            { return buf == rhs.buf; }
        bool operator!=(const self_type& rhs) 
            const { return buf != rhs.buf; }
    };

    MapArray(int size) 
        : sz(size), count(0), buf(new pair<T, U>[sz]) { }
    MapArray(initializer_list<T> s)
        : sz(s.size()), count(s.count), buf(new pair<T, U>[sz]) 
        { uninitialized_copy(s.begin(), s.end(), buf);}
    int size() const 
        { return sz; }
    U & operator [](T s)
    {
        int index = find(s);
        if (index != -1){
            return buf[index].second;
        } else{
            buf[count] = make_pair(s,0);
            int prevtail = count;
            ++count;
            return buf[prevtail].second;
        }
    }
    int find(T&s) const 
    {
        for (int i = 0; i < count; i++)
        {
            if (buf[i].first == s){
                return i;
            }
        }
        return -1;
    }
    const U& operator[](T index) const { return buf[index].second; }
    iterator begin() { return iterator(buf); }
    iterator end() { return iterator(buf + count); }
    const_iterator begin() const { return const_iterator(buf); }
    const_iterator end() const { return const_iterator(buf + count); }
    ~MapArray() { delete[] buf; }
};
