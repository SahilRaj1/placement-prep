/* TOPIC: Binary Tree */

// REFERENCE: https://youtu.be/5NiXlPrLslg

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

// tree construction
Node* buildTree(Node* &root) {

    int data;
    cout << "data : ";
    cin>>data;
    
    // -1 represents null
    if (data == -1) {
        return NULL;
    }

    // creating the node
    root = new Node(data);

    // recursive call for building left part of the tree
    cout << "enter the value at left node of " << root->data <<", ";
    root->left = buildTree(root->left);

    // recursive call for building right part of the tree
    cout << "enter the value at right node of " << root->data <<", ";
    root->right = buildTree(root->right);

    return root;
    
}

// breadth first search
void levelOrderTraversal(Node* &root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);   // seperater to add a new line whenever encountered

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout<<endl;
            // once NULL is popped, the queue will contain all the nodes from next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            
            // push in queue if left of current node is not null
            if (temp->left) {
                q.push(temp->left);
            }

            // push in queue if right of current node is not null
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

}

// storing level order using recursion
void recursiveLevelOrder(Node* node, int level, vector<vector<int>> &ans) {

    if (node == NULL) {
        return;
    }

    if (level >= ans.size()) {
        ans.push_back({});
    }

    ans[level].push_back(node->data);
    recursiveLevelOrder(node->left, level+1, ans);
    recursiveLevelOrder(node->right, level+1, ans);

}

// in-order traversal => L N R
void inorderTraversal(Node* node) {

    if (node == NULL) {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);

}

// pre-order traversal => N L R
void preorderTraversal(Node* node) {

    if (node == NULL) {
        return;
    }

    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);

}

// post-order traversal => L R N
void postorderTraversal(Node* node) {

    if (node == NULL) {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";

}

// create tree from level order traversal
void buildFromLevelOrder(Node* &root) {

    queue<Node*> q;
    cout<<"value of root node : ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // take left node input
        cout << "enter the value of left child of " << temp->data << ": ";
        int leftData;
        cin>>leftData;

        if (leftData != -1) {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        // take right node input
        cout << "enter the value of right child of " << temp->data << ": ";
        int rightData;
        cin>>rightData;

        if (rightData != -1) {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }

}

int main() {

    // initializing root
    Node* root = NULL;

    // creating tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // creating tree using level order
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // buildFromLevelOrder(root);

    // level order traversal
    // 1 3 5 7 11 17
    cout<<"\nlevel order traversal"<<endl;
    levelOrderTraversal(root);

    // reverse level order traversal
    cout<<"\nreverse level order traversal"<<endl;
    vector<vector<int >> ans;
    recursiveLevelOrder(root, 0, ans);
    reverse(ans.begin(), ans.end());
    for (auto &level: ans) {
        for (auto &it: level) {
            cout<<it<<" ";
        } cout<<endl;
    }

    // in-order traversal
    // 7 3 11 1 17 5
    cout<<"\nin-order traversal"<<endl;
    inorderTraversal(root);
    cout<<endl;

    // pre-order traversal
    // 1 3 7 11 5 17
    cout<<"\npre-order traversal"<<endl;
    preorderTraversal(root);
    cout<<endl;

    // post-order traversal
    // 7 11 3 17 5 1
    cout<<"\npost-order traversal"<<endl;
    postorderTraversal(root);
    cout<<endl;

    return 0;
}