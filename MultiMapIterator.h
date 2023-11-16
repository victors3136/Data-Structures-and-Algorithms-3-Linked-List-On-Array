#pragma once
#include "MultiMap.h"

class MultiMap;

class MultiMapIterator
{
	friend class MultiMap;

private:
	const MultiMap& map;

    int current;

	//DO NOT CHANGE THIS PART
	explicit MultiMapIterator(const MultiMap& c);

public:
	TElem getCurrent()const;
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return the value at the current position
    /// \errors throws std::error if the current position is not valid

	bool valid() const;
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return true if the current position represents a valid index inside the slla and the slla is not empty
    /// \errors throws no custom errors

	void next();
    /// \time Theta(1)
    /// \space Theta(1)
    /// \return number of (key,value) pairs in the multimap
    /// \errors throws std::error if the current position is invalid

	void first();
    /// \time Theta(1)
    /// \space Theta(1)
    /// \errors throws no custom errors
};

