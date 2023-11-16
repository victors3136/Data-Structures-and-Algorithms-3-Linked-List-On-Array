#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE (-111111)
#define NULL_TKEY (-111111)
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;
struct Node{
    TKey key { NULL_TKEY } ;
    TValue value { NULL_TVALUE } ;

    Node()=default;
    Node(TKey k, TValue v): key ( k ) , value ( v ) { };
    bool operator==(const Node &rhs) const {
        return key == rhs.key && value == rhs.value;
    }

    bool operator!=(const Node &rhs) const {
        return !(rhs == *this);
    }

    Node(TElem e):key(e.first), value(e.second) { };
};

class MultiMap
{
	friend class MultiMapIterator;

private:
    Node* elems;
    int * next ;
    int count;
    int capacity;
    int head; /// head of values
    int next_free; ///head of free positions

    void resize();
    /// \time O(size) amortized
    /// \space Theta(capacity)
    /// \errors throws no custom errors
public:
	//constructor
	MultiMap();
    /// \time Theta(1)
    /// \space Theta(1)
    /// \errors throws no custom errors

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);
    /// \time Theta(1) without possible resizing
    /// \space Theta(1) without possible resizing
    /// \param c Key of the node to be added; v Value of the node to be added
    /// \errors throws no custom errors

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);
    /// \time O(count)
    /// \space Theta(1)
    /// \param c, v key and value of node to be removed
    /// \return true if e was successfully removed from the set, false is it was not present
    /// \errors throws no custom errors

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;
    /// \time Theta(count)
    /// \space O(count)
    /// \param c key of the node for which we will extract and return the values
    /// \return std::vector of TValues
    /// \errors throws no custom errors

	//returns the number of pairs from the multimap
	int size() const;
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return number of (key,value) pairs in the multimap
    /// \errors throws no custom errors

	//checks whether the multimap is empty
	bool isEmpty() const;
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return true if the multimap has no key,value pairs, false otherwise
    /// \errors throws no custom errors



	//returns an iterator for the multimap
	MultiMapIterator iterator() const;
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return an iterator to the current instance
    /// \errors throws no custom errors

	//destructor
	~MultiMap();
    /// \time Theta(1)
    /// \space Theta(1)
    /// \errors throws no custom errors

    // finds and returns the min key for the multimap
    // if multimap is empty, returns NULL_TKey
    TKey minKey()const;
    ///\time Theta(count)
    ///\space Theta(1)
    ///\return NULL_TKey if the map is empty, smallest key otherwise
    ///\errors throws no custom errors (might be a problem if TKey is not TComp)
};

