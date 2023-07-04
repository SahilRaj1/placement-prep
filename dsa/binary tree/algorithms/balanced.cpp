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

pair<bool, int> balanced(Node* root) {

    if (root == NULL) {
        return {true, 0};
    }

    pair<bool, int> left = balanced(root->left);
    pair<bool, int> right = balanced(root->right);

    bool op1 = left.first;
    bool op2 = right.first;
    bool op3 = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.first = op1 and op2 and op3;
    ans.second = max(left.second, right.second) + 1;

    return ans;

}

int main() {

    

    return 0;
}