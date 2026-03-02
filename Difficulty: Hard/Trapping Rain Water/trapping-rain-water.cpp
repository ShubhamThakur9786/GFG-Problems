class Solution {
  public:
    int maxWater(vector<int> &height) {
        stack<int> st;   // stores indices
        int water = 0;

        for (int i = 0; i < height.size(); i++) {
            // While current bar is taller than stack top
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
    
                // If stack becomes empty, no left boundary
                if (st.empty())
                    break;
    
                int distance = i - st.top() - 1;
                int bounded_height = 
                    min(height[i], height[st.top()]) - height[top];
    
                water += distance * bounded_height;
            }
    
            st.push(i);
        }
    
        return water;
        
    }
};