stack<int> _push(int arr[], int n) {
    // code here
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(st.empty()) {
            st.push(arr[i]);
        }
        else {
            if(st.top() < arr[i]) {
                st.push(st.top());
            }
            else {
                st.push(arr[i]);
            }
        }
    }
    
    return st;
}

// Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int> s) {

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}