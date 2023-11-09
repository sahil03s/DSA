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
void inOrderTraversal(Node* root)
{
    if(!root)
        return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(Node* root)
{
    if(!root)
        return;
    
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
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


void inorderArray(Node* root, vector<int> &in)
{
    if(!root)
        return;
    
    inorderArray(root->left, in);
    in.push_back(root->data);
    inorderArray(root->right, in);
}


//T.C. = O(n)     S.C. = O(n)
Node* flattenLL(Node *root)
{
    if(!root)
        return NULL;
    
    vector<int> in;
    inorderArray(root, in);

    Node* ans = new Node(in[0]);
    Node* curr = ans;
    int n = in.size();

    for(int i=1; i<n; i++)
    {
        Node* temp = new Node(in[i]);
        curr->right = temp;
        curr = temp;
    }

    return ans;

//T.C. = O(n^2)     S.C. = O(h)
    // if(!root || !root->left && !root->right)
    //     return root;

    // root->right = flattenLL(root->right);

    // if(root->left)
    // {
    //     Node *temp = root->left;
    //     root->left = NULL;
    //     Node *leftAns = flattenLL(temp);
    //     while(temp->right)
    //         temp = temp->right;
    //     temp->right = root;
    //     return leftAns;
    // }
    // else
    //     return root;
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

    cout << "\n\n";

    root = flattenLL(root);

    while(root)
    {
        cout << root->data << " ";
        root = root->right;
    }

    return 0;
}

//100 50 30 70 60 110 120 115 -1

//7501 2917 8088 744  7505 -1

