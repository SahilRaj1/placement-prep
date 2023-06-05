/* TOPIC: Binary Search Trees */

// REFERENCE: https://youtu.be/UeRUKRJvPa4

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

// insert a node into BST
Node* insertIntoBST(Node* &root, int data) {

    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }

    return root;

}

// take input stream of data from user
void takeInput(Node* &root) {
    int data;
    cin>>data;
    while (data != -1) {
        insertIntoBST(root, data);
        cin>>data;
    }
}

// recursively searching in BST
Node* searchBST(Node* root, int target) {
        
    if (root == NULL) {
        return NULL;
    }

    Node* left = NULL;
    Node* right = NULL; 
    if (target < root->data) {
        left = searchBST(root->left, target);
    } else if (target > root->data) {
        right = searchBST(root->right, target);
    } else {
        return root;
    }

    if (left != NULL and right == NULL) {
        return left;
    }
    if (left == NULL and right != NULL) {
        return right;
    }

    // left == NULL and right == NULL
    return NULL;

}

// iteratively searching in BST
Node* iterativeSearchBST(Node* root, int target) {

    Node* temp = root;
    while (temp) {
        if (temp->data > target) {
            temp = temp->left;
        } else if (temp->data < target) {
            temp = temp->right;
        } else {
            return temp;
        }
    }
    return NULL;

}

// get minimum fron BST
int getMin(Node* root) {
    if (root == NULL) {
        return -1;
    }
    if (root->left == NULL) {
        return root->data;
    }
    return getMin(root->left);
}

// get masximum fron BST
int getMax(Node* root) {
    if (root == NULL) {
        return -1;
    }
    if (root->right == NULL) {
        return root->data;
    }
    return getMax(root->right);
}

Node* deleteFromBST(Node* &root, int target) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == target) {

        // node to delete with no children
        if (root->left == NULL and root->right == NULL) {
            delete root;
            return NULL;
        }

        // node to delete with left child
        else if (root->left != NULL and root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node to delete with right child
        else if (root->left == NULL and root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // node to delete with two children
        else {
            int maxi = getMax(root->left);
            root->data = maxi;
            deleteFromBST(root->left, maxi);
        }

    }

    // target in left subtree
    else if (target < root->data) {
        root->left = deleteFromBST(root->left, target);
    }

    // target in right subtree
    else {
        root->right = deleteFromBST(root->right, target);
    }

    return root;

}

int main() {

    Node* root = NULL;

    cout<<"enter data to create BST: ";
    takeInput(root);
    // 6 2 5 1 7 10 3 9 4 8 -1

    cout<<"\nLevel Order Traversal"<<endl;
    levelOrderTraversal(root);
    // 6 2 7 1 5 10 3 9 4 8
    cout<<endl;

    // Inorder traversal on a BST gives all the elements in a sorted order
    cout<<"\nInorder Traversal"<<endl;
    inorderTraversal(root);
    // 1 2 3 4 5 6 7 8 9 10
    cout<<endl;

    cout<<"\nPreorder Traversal"<<endl;
    preorderTraversal(root);
    // 6 2 1 5 3 4 7 10 9 8
    cout<<endl;

    cout<<"\nPostorder Traversal"<<endl;
    postorderTraversal(root);
    // 1 4 3 5 2 8 9 10 7 6
    cout<<endl<<endl;

    Node* node = iterativeSearchBST(root, 5);
    if (node) {
        cout << "found " << node->data << endl;
    } cout<<endl;

    cout << "Minimum : " << getMin(root) << endl;
    cout << "Maximum : " << getMax(root) << endl;
    cout<<endl;

    // deleting from BST
    root = deleteFromBST(root, 7);

    cout<<"\nInorder Traversal after deletion"<<endl;
    inorderTraversal(root);
    // 1 2 3 4 5 7 8 9 10
    cout<<endl;

    return 0;
}