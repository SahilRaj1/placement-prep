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

int height(Node* root) {

    if (root == NULL) {
        return 0;
    }

    int left = height(root->left) + 1;
    int right = height(root->right) + 1;

    return max(left, right);

}

int main() {

    

    return 0;
}