#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): map(c) {
	current = map.head;
}

TElem MultiMapIterator::getCurrent() const{
    if(!valid())
        throw exception();
    Node& node = map.elems[current];
    return {node.key, node.value};
}

bool MultiMapIterator::valid() const {
	return(current != -1 && current != map.next_free);
}

void MultiMapIterator::next() {
    if(!valid())
        throw exception();
    current = map.next[current];
	//current = map.elems[current].next;
}

void MultiMapIterator::first() {
	current = map.head;
}

