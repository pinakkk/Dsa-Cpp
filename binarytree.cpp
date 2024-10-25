#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data; 
    node *left;
    node *right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTreeBinary(node *root){
    cout << "Enter Data: " << " ";
    int data;
    cin >> data;

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter Data for left of" << root->data; 
    root->left = buildTreeBinary(root->left);

    cout << "Enter Data for right of" << root->data;
    root->right = buildTreeBinary(root->right);

    return root;
}

void buildTree(node *&root){
    queue<node *> q;
    cout << "Enter Data: " << endl;

    int data; 
    cin >> data; 
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout << "Enter data for left of " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data for right of " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inorder(node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){

    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // buildTree(root);

    root = buildTreeBinary(root);
    inorder(root);
    return 0;
}
