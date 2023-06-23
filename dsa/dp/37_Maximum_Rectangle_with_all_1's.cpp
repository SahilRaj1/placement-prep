/* TOPIC: Maximum Rectangle with all 1's */

// TIME COMPLEXITY: O()
// SPACE COMPLEXITY: O()

// REFERENCE: https://youtu.be/IPT6emqnxg8
// QUESTION: https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i=n-1; i>=0; i--) {
            while(st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &arr, int n) {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i=0; i<n; i++) {
            while(st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i=0; i<n; i++) {
            if (next[i] == -1) {
                next[i] = n;
            }
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }

        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        vector<vector<int>> M(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    M[i][j] = 1;
                }
            }
        }
        
        int ans = largestRectangleArea(M[0]);

        for (int i=1; i<M.size(); i++) {
            // update row
            for (int j=0; j<M[0].size(); j++) {
                if (M[i][j] != 0) {
                    M[i][j] = M[i][j] + M[i-1][j];
                }
            }
            int newArea = largestRectangleArea(M[i]);
            ans = max(ans, newArea);
        }

        return ans;
    }
};

int main() {

    

    return 0;
}