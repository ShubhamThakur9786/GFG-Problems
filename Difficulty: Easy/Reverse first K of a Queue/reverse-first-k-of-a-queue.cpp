class Solution {
  public:
    queue<int> reverseFirstK(queue<int> &q, int k) {
    if (k <= 0 || k > q.size())
        return q;

    stack<int> st;

    // Step 1: Push first k elements into stack
    for(int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push them back (reversed)
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements
    int remaining = q.size() - k;
    while(remaining--) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
};