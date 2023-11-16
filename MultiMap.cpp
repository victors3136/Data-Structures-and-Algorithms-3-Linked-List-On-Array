#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

void MultiMap::add(TKey c, TValue v) {
    int temp = next[next_free];
    //int temp = elems[next_free].next;
    elems[next_free].key = c; elems[next_free].value = v;
    next[next_free] = (head == next_free) ? -1 : head;
    //elems[next_free].next = (head == next_free) ? -1 : head;
    head = next_free;
    next_free = temp;
    count ++;
    if(count >= capacity)
        resize();
}


bool MultiMap::remove(TKey c, TValue v) {
    if(head == next_free)
        return false;
    int current = head;
    int prev = -1;
    Node sought {c,v};
    while(current > -1 && elems[current] != sought){
        prev = current;
        current = next[prev];
    }
    if(current > -1){
        if(current == head){
            head = next[head];
        }else{
            next[prev] = next[current];
        }
        elems[current]={NULL_TELEM};
        next[current] = next_free;
        next_free = current;
        count --;
        return true;
    }
    return false;

}


vector<TValue> MultiMap::search(TKey c) const {
    vector<TValue> returnVector;
    if(head == next_free)
        return returnVector;
    int current = head;
    while(current != -1 ){
        if(elems[current].key == c){
            returnVector.push_back(elems[current].value);
        }
        current = next[current];
    }
	return returnVector;
}


int MultiMap::size() const {
	return count;
}


bool MultiMap::isEmpty() const {
	return count == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
    delete[] elems;
    delete[] next;
}

void MultiMap::resize() {
    if (count >= capacity) {
        capacity = capacity << 1;
        int current = head;
        auto newElems = new Node[capacity];
        auto newNext = new int[capacity];
        while (current != -1) {
            newElems[current] = {elems[current].key, elems[current].value};
            newNext [current] =  next [current] ;
            current = next[current];
        }
        delete[] elems;
        delete[] next;
        elems = newElems;
        next = newNext;
        next_free = count;
        for(int i = count; i < capacity - 1; i ++){
            next [ i ] = i + 1;
        }
        next[capacity - 1] = -2;
    }
}


MultiMap::MultiMap() {
    count = 0;
    capacity = 16;
    elems = new Node[capacity];
    next = new int[capacity];
    head = 0;
    next_free = 0;
    for(int i = 0 ; i < capacity ; i ++){
        next[i] = i + 1;
    }
    next[capacity] = -2;
}

TKey MultiMap::minKey() const {
    if(head == next_free)
        return NULL_TKEY;
    int current = head, min = head;
    while(current != -1){
        if(elems[current].key <= elems[min].key)
            min = current;
        current = next[current];
    }
    return elems[min].key;
}
