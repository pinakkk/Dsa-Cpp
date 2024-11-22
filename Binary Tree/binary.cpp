#include <iostream> 
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right=NULL;
    }

};

Node *buildTree(Node *root){
    // cout << "Enter root :" << " ";
    int data; cin >> data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    // cout << "Enter data for left of " << root->data;
    root->left = buildTree(root->left);

    // cout << "Enter data for right of " << root->data;
    root->right = buildTree(root->right);

    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *insertnode(Node *root, int data){
    if(root == NULL){
        return new Node(data);
    }

    if(data < root->data){
        root->left = insertnode(root->left, data);
    }
    else{
        root->right = insertnode(root->right, data);
    }
    return root;
}

Node *deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        // Found to be deleted
        // case 1 -> no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        // case 2 -> node has one child
        if(root->left == NULL){
            Node *temp = root->right;
            delete temp; return root;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            delete temp; return root;
        }

        // case 3 -> node has two children. find in order successor 
        // Node *temp = findMin(root->right);
        // root->data = temp->data;
        // root->right = deleteNode(root->right, temp->data);

    }

    return root;
}

Node *findMin(Node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}


Node *findMax(Node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

int main(){
    Node *root = NULL;
    root = buildTree(root);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Find and print minimum and maximum values
    cout << "Minimum value: " << findMin(root)->data << endl;
    cout << "Maximum value: " << findMax(root)->data << endl;
    return 0;
}