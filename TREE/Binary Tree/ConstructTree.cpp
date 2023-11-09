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


//T.C. = O(n)    S.c. = O(h)
Node* buildFromPreIn(vector<int> &pre, vector<int> &in, int n, int &index, int inOrderStart, int inOrderEnd, unordered_map<int,int> &mp)
{
    //index is preOrderIndex
    if(index >= n || inOrderStart > inOrderEnd)
        return NULL;
    
    //create root from preorder and increment the index by 1
    Node* root = new Node(pre[index++]);

    //search for the location of element in inorder vector
    int i = mp[root->data];

    //building left and right subtrees
    root->left = buildFromPreIn(pre, in, n, index, inOrderStart, i-1, mp);
    root->right = buildFromPreIn(pre, in, n, index, i+1, inOrderEnd, mp);

    return root;
}


//T.C. = O(n)    S.c. = O(n)
Node* buildTreeFromPreIn(vector<int> &pre, vector<int> &in, int n)
{
    //mapping each element of inorder with its index
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
        mp[in[i]] = i;
    
    //index for preodrder vector
    int preOrderIndex = 0;

    return buildFromPreIn(pre, in, n, preOrderIndex, 0, n-1, mp);
}

//T.C. = O(n)    S.c. = O(n)
Node* buildTreeFromPreInIterative(vector<int> &pre, vector<int> &in, int n)
{
    stack<Node*> stack;
    Node *root = new Node(pre[0]);
    stack.push(root);
    int preIndex = 1;
    int inIndex = 0;

    //traverse over preOrder vector
    while(preIndex < n)
    {
        //initialise curr as null
        Node *curr = NULL;
        
        //while stack.top() contains elements with data equal to inorder vector's index, keep popping the element. it means the current node should be a right child of the top node. Pop the stack.
        while(!stack.empty() && stack.top()->data == in[inIndex])
        {
            curr = stack.top();
            stack.pop();
            inIndex++;
        }

        //create a new node
        Node *temp = new Node(pre[preIndex]);

        //if curr is not null, temp is curr->right child, else if curr is NULL, temp is left child of node at the top of stack
        if(curr)
            curr->right = temp;
        else
            stack.top()->left = temp;
        
        stack.push(temp);
        preIndex++;
    }

    return root;
}

//T.C. = O(n)    S.c. = O(h)
Node* buildFromPostIn(vector<int> &post, vector<int> &in, int n, int &index, int inOrderStart, int inOrderEnd, unordered_map<int,int> &mp)
{
    //index is preOrderIndex
    if(index < 0 || inOrderStart > inOrderEnd)
        return NULL;
    
    //create root from preorder and increment the index by 1
    Node* root = new Node(post[index--]);

    //search for the location of element in inorder vector
    int i = mp[root->data];

    //building left and right subtrees
    root->right = buildFromPostIn(post, in, n, index, i+1, inOrderEnd, mp);
    root->left = buildFromPostIn(post, in, n, index, inOrderStart, i-1, mp);

    return root;
}


//T.C. = O(n)    S.c. = O(n)
Node* buildTreeFromPostIn(vector<int> &post, vector<int> &in, int n)
{
    //mapping each element of inorder with its index
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
        mp[in[i]] = i;
    
    //index for preodrder vector
    int postOrderIndex = n-1;

    return buildFromPostIn(post, in, n, postOrderIndex, 0, n-1, mp);
}

Node* buildTreeFromPostInIterative(vector<int> &post, vector<int> &in, int n)
{
    stack<Node*> stack;
    Node* root = new Node(post[n-1]);
    stack.push(root);
    int postOrderIndex = n-2;
    int inOrderIndex = n-1;

    while(postOrderIndex >= 0)
    {
        Node *curr = NULL;

        while(!stack.empty() && stack.top()->data == in[inOrderIndex])
        {
            curr = stack.top();
            stack.pop();
            inOrderIndex--;
        }

        Node *temp = new Node(post[postOrderIndex]);

        if(curr)
            curr->left = temp;
        else
            stack.top()->right = temp;


        stack.push(temp);
        postOrderIndex--;

    }

    return root;
}

int main()
{
    vector<int> in = {8, 4, 9, 2, 10, 5, 11, 1, 6, 13, 3, 14, 7};
    vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 13, 7, 14};
    vector<int> post = {8, 9, 4, 10, 11, 5, 2, 13, 6, 14, 7, 3, 1};
    int n = 13;
    Node *root = buildTreeFromPostInIterative(post, in, n);
    cout << "\n\nLevel order :" << endl;
    levelOrderTraversal(root);
    cout << "\n\nInorder :" << endl << endl;
    inorderTraversal(root);
    cout << "\n\nPreorder :" << endl << endl;
    preorderTraversal(root);
    cout << "\n\nPostorder :" << endl << endl;
    postorderTraversal(root);
    cout << endl << endl << "hello\n\n";
    return 0;
}

//1 2 3 4 5 6 7 8 9 10 11 -1 13 14 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1