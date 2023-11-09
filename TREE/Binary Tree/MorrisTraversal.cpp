#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node {
    public :
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

Node* buildTree(Node* root)
{
    int data;
    cout << "Enter the data : " ;
    cin >> data;

    if(data == -1)
        return NULL;
    
    root = new Node(data);

    cout << "Enter data for the left child : " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for the right child : " << endl;
    root->right = buildTree(root->right);

    return root;

}
void buildFromLevelOrder(Node* &root)
{
    queue<Node*> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left child for " << temp->data << " : " ;
        cin >> data;
        if(data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Enter right child for " << temp->data << " : " ;
        cin >> data;
        if(data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }

    }
}
void levelOrderTraversal(Node* &root)
{
    cout << endl;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
void inorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

Node* findPredecessor(Node* &root)
{
    Node *temp = root->left;
    while(temp->right != NULL && temp->right != root)
        temp = temp->right;
    
    return temp;
}

//for inorder traversal
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

//for preorder traversal
//T.C. = O(n)   S.C. = O(1)
void morrisTraversalPre(Node* &root)
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
                cout << curr->data << " ";
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

//1 2 3 4 5 6 7 8 9 10 11 -1 13 14 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    Node *root = NULL;
    buildFromLevelOrder(root);
    cout << "\n\nLevel order :" << endl;
    levelOrderTraversal(root);
    cout << "\n\nInorder :" << endl << endl;
    inorderTraversal(root);
    cout << "\n\nMorris :" << endl << endl;
    morrisTraversal(root);
    cout << "\n\nPreorder :" << endl << endl;
    preorderTraversal(root);
    cout << "\n\nPreorder using Morris :" << endl << endl;
    morrisTraversalPre(root);
    cout << "\n\nPostorder :" << endl << endl;
    postorderTraversal(root);
    cout << endl << endl << "hello\n\n";
    return 0;
}
