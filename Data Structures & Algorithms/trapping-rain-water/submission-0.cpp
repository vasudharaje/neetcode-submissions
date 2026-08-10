class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;

        for (int i = 0; i < height.size(); i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();

                int h = min(height[left], height[i]) - height[bottom];
                int w = i - left - 1;

                water += h * w;
            }

            st.push(i);
        }

        return water;
    }
};