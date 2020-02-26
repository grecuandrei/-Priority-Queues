#include <iostream>
#include <vector>

/// Max Heap ///
struct MaxHeap {
	/// vector to store elements
	std::vector<int> A;
public:
	/// insert key into the heap
	void push(int key) {
		/// get element index and call heapify-up
		int index = size() - 1;
		/// insert the new element to the end
		A.push_back(key);
		heapify_up(index);
	}

	/// function to remove element with highest priority (present at root)
	void pop() {
        /// no elements, display a message at cerr and stop
		/// in my tests, this case won't show up as this is not hte scope
        if (empty()) {
            std::cerr<<"No elements already!"<<std::endl;
            return;
        }
        /// replace the root with the last element
        A[0] = A.back();
        A.pop_back();
        /// call heapify-down on root
        heapify_down(0);
	}

	/// returns highest elem
	int top() {
		/// if it has no elements, return -1 and msg at cerr
		/// in my tests, this case won't show as this is not the scope
	    if (empty()) {
            std::cerr<<"No elements!"<<std::endl;
            return -1;
        }
        /// return the top elem
        return A.at(0);
	}

	/// size of heap
	unsigned int size() {
		return A.size();
	}

	/// function to check if heap is empty or not
	bool empty() {
		return size() == 0;
	}

private:
	/// Recursive Heapify-down algorithm
	void heapify_down(int i) {
		/// get left and right child of index i
		int left = lNode(i);
		int right = rNode(i);
		int largest = i;
		/// compare A[i] to left and right child
		if (left < signed(size()) && A[left] > A[i]) {
			largest = left; /// and save the largest
		}
		if (right < signed(size()) && A[right] > A[largest]) {
			largest = right;
		}
		/// swap with child having greater value
		if (largest != i) {
			std::swap(A[i], A[largest]);
			/// call heapify-down for him
			heapify_down(largest);
		}
	}

	/// Recursive Heapify-up algorithm
	void heapify_up(int i) {
		/// check if i and parent violates the property
		if (i && A[father(i)] < A[i]) {
			/// swap the two if violated
			std::swap(A[i], A[father(i)]);
			/// call Heapify-up
			heapify_up(father(i));
		}
	}

	/// return parent
	int father(int i) {
		return (i - 1) / 2;
	}

	/// return left child of A[i]
	int lNode(int i) {
		return (2 * i + 1);
	}

	/// return right child of A[i]
	int rNode(int i) {
		return (2 * i + 2);
	}
};
