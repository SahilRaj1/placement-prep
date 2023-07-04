/* Sahil Raj */

#include <bits/stdc++.h>
using namespace std;

class Node {
public:

    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

};

pair<int, int> diameter(Node* root) {

    if (root == NULL) {
        return {0, 0};
    }

    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
    
}

int main() {

    

    return 0;
}