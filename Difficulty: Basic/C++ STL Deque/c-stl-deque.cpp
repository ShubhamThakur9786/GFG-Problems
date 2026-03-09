/*You are required to complete below methods*/

/*prints space separated
elements of the deque A*/
void print(deque<int> &A) {
    // Your code here
    
    // if the queue is empty then print -1 with a newline
    // else print the elements from front to back
    if(A.empty()) {
        cout << -1 << endl;
    }
    else {
        for(int val : A) {
            cout << val << " ";
        }
        cout << endl;
    }
}

/*inserts an element x at
the front of the deque A*/
void add_in_front(deque<int> &A, int x) {
    
    A.push_front(x);
}

/*inserts an element x at
the back of the deque A */
    
void add_in_back(deque<int> &A, int x) {
    // Your code here
    A.push_back(x);
}

/*remove element from
back of the deque A*/
    

void remove_from_back(deque<int> &A) {
    // Your code here
    if(!A.empty()) {
        A.pop_back();
    }
}

    
/*remove element from
front of the deque A*/
void remove_from_front(deque<int> &A) {
    // Your code here
    if(!A.empty()) {
        A.pop_front();
    }
}

/*sort the the deque A in ascending order*/
void sort(deque<int> &A) {
    
    // Your code here
    std::sort(A.begin(), A.end());
}

/*reverses the deque A*/
    
void reverse(deque<int> &A) {
    // Your code here
    std::reverse(A.begin(), A.end());
}

/*returns the size of the deque  A */
    
int size(deque<int> &A) {
    // Your code here
    return A.size();
}

/* returns element at front
    
of the deque*/
int element_at_front(deque<int> &A) {
    // Your code here
    if(!A.empty()) {
        return A.front();
    }
    return -1;
}

/*returns element at end
of the deque*/
int element_at_back(deque<int> &A) {
    // Your code here
    if(!A.empty()) {
        return A.back();
    }
    return -1;
}