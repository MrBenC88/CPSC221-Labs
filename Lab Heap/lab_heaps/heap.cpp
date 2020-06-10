/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.

    //use 0 based index
    return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    
    return (2 * currentIdx + 1);
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    
    return (2 * currentIdx + 2);
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    
    return (currentIdx - 1) / 2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    /// @todo Update to return whether the given node has a child
    
    return (2 * currentIdx + 1) < _elems.size();
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    
    return higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])
     ? leftChild(currentIdx) : rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /// @todo Implement the heapifyDown algorithm.

    // base case
	if (!hasAChild(currentIdx)) return;

	size_t childIdx = maxPriorityChild(currentIdx);

	if (higherPriority(_elems[childIdx], _elems[currentIdx])) {
		std::swap(_elems[currentIdx], _elems[childIdx]);
		heapifyDown(childIdx);
	}
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);

    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    /// @todo Construct a heap using the buildHeap algorithm
    /// Your algorithm should use heapifyDown() so that it constructs
    /// the same heap as our test case.

	for (size_t i = 0; i < elems.size(); i ++) {
		_elems.push_back(elems[i]);
	}


	for (size_t j = parent(_elems.size() - 1); j > 0; j--)
		heapifyDown(j);

	heapifyDown(root());


}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    /// @todo Remove, and return, the element with highest priority

    T returnVal = _elems[root()];
    _elems[root()] = _elems[_elems.size() - 1];
    _elems.pop_back();
    heapifyDown(root());
    return returnVal;

}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
    return _elems[root()];

}
template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    /// @todo Add elem to the heap
    _elems.push_back(elem);
    heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
    return _elems.empty();
}
