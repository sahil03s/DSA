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


//T.C. = O(n)    S.c. = O(n)
void inorder(Node* root, vector<int> &in)
{
    if(!root)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right, in);
}

//T.C. = O(n)    S.c. = O(h)
Node* solve(vector<int> &in, int start, int end)
{
    if(start > end)
        return NULL;
    
    int key = start + (end-start)/2;
    Node* root = new Node(in[key]);
    root->left = solve(in, start, key-1);
    root->right = solve(in, key+1, end);

    return root;
}


//T.C. = O(n)    S.c. = O(n)
Node* balancedBst(Node* root) {
    vector<int> in;
    inorder(root,in);

    return solve(in, 0, in.size()-1);
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

    return 0;
}

//100 50 30 70 60 110 120 115 -1