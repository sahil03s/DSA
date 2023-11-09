#include <iostream>
#include <queue>

using namespace std;

class Node{
    public :
    int data;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->data = key;
        this->left = NULL;
        this->right = NULL;
    }
};

//T.C. = O(h)   S.C. = O(h)
Node* insertIntoBST(Node* &root, int data)
{
    if(root == NULL)
    {
        Node* root = new Node(data);
        return root;
    }

    else if(root->data < data)
        root->right = insertIntoBST(root->right, data);
    else
        root->left = insertIntoBST(root->left, data);

    return root;
}

Node* createBST()
{
    Node *root = NULL;
    cout << "Enter data (-1 to end) : " << endl;
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }

    return root;
}

//T.C. = O(n)    S.c. = O(n)
void levelOrderTraversal(Node* &root)
{
    cout << endl;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        cout << "\n";
    }
}

//T.C. = O(n)    S.c. = O(h)
void inOrderTraversal(Node* root)
{
    if(!root)
        return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

//T.C. = O(n)    S.c. = O(h)
void preOrderTraversal(Node* root)
{
    if(!root)
        return;
    
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//T.C. = O(n)    S.c. = O(h)
void postOrderTraversal(Node* root)
{
    if(!root)
        return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* findPredecessor(Node* &root)
{
    Node *temp = root->left;
    while(temp->right != NULL && temp->right != root)
        temp = temp->right;
    
    return temp;
}

//T.C. = O(n)   S.C. = O(1)
void morrisTraversal(Node* &root)
{
    Node *curr = root;
    
    while(curr)
    {
        if(!curr->left)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node* pred = findPredecessor(curr);
            if(!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

//T.C. = O(h)    S.c. = O(1)
Node* search(Node* root, int key)
{
    Node *curr = root;
    while(curr)
    {
        if(curr->data == key)
            return curr;
        else if(key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    return NULL;

//T.C. = O(h)    S.c. = O(h)
    // if(root == NULL || root->data == key)
    //     return root;

    // else if(key < root->data)
    //     return search(root->left, key);
    
    // else
    //     return search(root->right, key);
}


//T.C. = O(h)    S.c. = O(1)
Node* minNode(Node* root)
{
    if(!root)
        return NULL;

    Node* curr = root;
    while(curr->left)
        curr = curr->left;
    
    return curr;
}

//T.C. = O(h)    S.c. = O(1)
Node* maxNode(Node* root)
{
    if(!root)
        return NULL;

    Node* curr = root;
    while(curr->right)
        curr = curr->right;
    
    return curr;
}

//T.C. = O(h)    S.c. = O(1)
Node* inOrderPredecessor(Node* root, int key)
{
    if(!root)
        return NULL;
    
    Node* temp = root;
    Node* pred = NULL;

    while(temp->data != key)
    {
        if(temp->data < key)
        {
            pred = temp;
            temp = temp->right;
        }
        else 
            temp = temp->left;
    }
    
    Node* leftTree = temp->left;
    while(leftTree != NULL)
    {
        pred = leftTree;
        leftTree = leftTree->right;
    }

    return pred;
}

//T.C. = O(h)    S.c. = O(1)
Node* inOrderSuccessor(Node* root, int key)
{
    if(!root)
        return NULL;
    
    Node *temp = root;
    Node* succ = NULL;

    while(temp->data != key)
    {
        if(temp->data > key)
        {
            succ = temp;
            temp = temp->left;
        }
        else
            temp = temp->right;
    }
    
    Node* rightTree = temp->right;
    while(rightTree)
    {
        succ = rightTree;
        rightTree = rightTree->left;
    }

    return succ;
}

//T.C. = O(h)    S.c. = O(h)
Node* deleteNode(Node* root, int key)
{
    if(!root)
        return NULL;

    if(root->data == key)
    {   
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        if(!root->left || !root->right)
        {
            Node* t = root->left ? root->left : root->right ;
            delete root;
            return t;
        }

        if(root->left && root->right)
        {
            Node *t = inOrderSuccessor(root, root->data);
            root->data = t->data;
            root->right = deleteNode(root->right, root->data);
            return root;
        }
    }
    else if(key < root->data)
        root->left = deleteNode(root->left, key);
    else
        root->right = deleteNode(root->right, key);
    
    return root;
}

//T.C. = O(N)   S.C. = O(1)
Node* LCA(Node* root, int n1, int n2)
{
    while(root)
    {
        if(root->data < n1 && root->data < n2)
            root = root->right;
        else if(root->data > n1 && root->data > n2)
            root = root->left;
        else    
            return root;
    }

    return root;
}

int main()
{
    Node* root = createBST();
    cout << "\nLevelOrder Traversal :\n";
    levelOrderTraversal(root);
    cout << "\nInOrder Traversal :\n";
    inOrderTraversal(root);
    cout << "\n\nPreOrder Traversal :\n";
    preOrderTraversal(root);
    cout << "\n\nPostOrder Traversal :\n";
    postOrderTraversal(root);

    Node* temp = NULL;
    temp = inOrderPredecessor(root, root->data);
    cout << "\n\nPredecessor : " << temp->data << "\n\n";
    temp = inOrderSuccessor(root, root->data);
    cout << "Successor : " << temp->data << "\n\n";
    temp = inOrderPredecessor(root, 70);
    cout << "\n\nPredecessor : " << temp->data << "\n\n";
    temp = inOrderSuccessor(root, 70);
    cout << "Successor : " << temp->data << "\n\n";

    root = deleteNode(root, 70);

    cout << "\nLevelOrder Traversal :\n";
    levelOrderTraversal(root);
    cout << "\nInOrder Traversal :\n";
    inOrderTraversal(root);
    cout << "\n\nPreOrder Traversal :\n";
    preOrderTraversal(root);
    cout << "\n\nPostOrder Traversal :\n";
    postOrderTraversal(root);
    cout << "\n\n";
    return 0;
}

//100 50 30 70 60 110 120 115 -1