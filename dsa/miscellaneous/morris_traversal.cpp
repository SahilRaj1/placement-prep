/* TOPIC: Morris Traversal */

// TIME COMPLEXITY: O(n)
// SPACE COMPLEXITY: O(1)

// REFERENCE: https://youtu.be/2BdY9fixMrM

#include <bits/stdc++.h>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* buildTree(Node* &root) {

    int data;
    cin>>data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;

}

// find predecessor of a node without recursion or stack
Node* findPred(Node* root) {

    Node* temp = root->left;
    while (temp->right and temp->right != root) {
        temp = temp->right;
    }

    return temp;

}

// morris traversal function for inorder traversal
void morrisTraversal(Node* root) {

    Node* curr = root;
    while (curr) {

        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {

            Node* pred = findPred(curr);
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }

        }

    }

}

int main() {

    Node* root = NULL;
    buildTree(root);
    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

    // morris traversal
    morrisTraversal(root);
    // 4 7 2 5 1 3 6
    cout<<endl;


    return 0;
}