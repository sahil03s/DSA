#include <iostream>
#include <queue>
#include <stack>
#include <map>

using namespace std;

class Node
{
public:
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
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    if (data == -1)
        return NULL;

    root = new Node(data);

    cout << "Enter data for the left child : " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for the right child : " << endl;
    root->right = buildTree(root->right);

    return root;
}
void buildFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter left child for " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->left = new Node(data);
            q.push(temp->left);
        }
        cout << "Enter right child for " << temp->data << " : ";
        cin >> data;
        if (data != -1)
        {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// T.C. = O(n)   S.C. = O(n)
void zigZagTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    bool leftToRight = 1;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            Node *t = q.front();
            q.pop();
            int idx = leftToRight ? i : n - 1 - i;
            temp[idx] = t->data;

            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }

        leftToRight = !leftToRight;
        for (auto x : temp)
        {
            cout << x << " ";
        }
    }

    // if(root == NULL)
    //     return;

    // stack<Node*> curr;
    // stack<Node*> next;
    // curr.push(root);

    // bool LtoR = true;

    // while(!curr.empty())
    // {
    //     Node *temp = curr.top();
    //     curr.pop();
    //     cout << temp->data << " ";

    //     if(LtoR)
    //     {
    //         if(temp->left)
    //             next.push(temp->left);
    //         if(temp->right)
    //             next.push(temp->right);
    //     }
    //     else
    //     {
    //         if(temp->right)
    //             next.push(temp->right);
    //         if(temp->left)
    //             next.push(temp->left);
    //     }
    //     if(curr.empty())
    //     {
    //         LtoR = !LtoR;
    //         swap(curr, next);
    //     }
    // }
}

// T.C. = O(n)   S.C. = O(h)
void traverseLeft(Node *&root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    cout << root->data << " ";

    if (root->left)
        traverseLeft(root->left);
    else
        traverseLeft(root->right);
}

// T.C. = O(n)   S.C. = O(h)
void traverseLeaf(Node *&root)
{
    if (root == NULL)
        return;

    traverseLeaf(root->left);

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    traverseLeaf(root->right);
}

// T.C. = O(n)   S.C. = O(h)
void traverseRight(Node *&root)
{
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        traverseRight(root->right);
    else
        traverseRight(root->left);

    cout << root->data << " ";
}

// T.C. = O(n)   S.C. = O(h)
void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    traverseLeft(root->left);
    traverseLeaf(root->left);
    traverseLeaf(root->right);
    traverseRight(root->right);

}


// T.C. = O(n)   S.C. = O(n)
void verticalOrderTraversal(Node *root)
{
    if(root == NULL)
        return;

    //mapping from vertical distance to nodes
    map<int, vector<int>> nodes;

    //queue of (nodes, vertical distance)
    queue<pair<Node*, int>> q;
    q.push({root,0}); //vertical distance of root is 0

    while(!q.empty())
    {
        pair<Node*, int> t = q.front();
        q.pop();
        Node* temp = t.first;
        int d = t.second;

        nodes[d].push_back(temp->data);

        if(temp->left)
            q.push({temp->left, d-1});
        if(temp->right)
            q.push({temp->right, d+1});
    }

    // for(auto i: nodes)
    //     for(auto j : i.second)
    //             cout << j << " ";

    for(map<int, vector<int>>::iterator i=nodes.begin(); i != nodes.end(); i++)
        for(vector<int>::iterator itr = i->second.begin(); itr != i->second.end() ; itr++ )
            cout << *itr << " ";

}


// T.C. = O(n logn)   S.C. = O(n)
void diagonalUtil(Node* &root, int d, map<int,vector<int>> &mp)
{
    if(!root)
        return;

    mp[d].push_back(root->data);
    diagonalUtil(root->left, d+1, mp);
    diagonalUtil(root->right, d, mp);
}

// T.C. = O(n)   S.C. = O(n)
void diagonalOrderTraversal(Node* &root)
{
    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            Node* temp = q.front();
            q.pop();
            while(temp)
            {
                cout << temp->data << " ";
                if(temp->left)
                    q.push(temp->left);
                temp = temp->right;
            }
        }
        cout << endl;
    }


// T.C. = O(n logn)   S.C. = O(n)
    // if(!root)
    //     return;

    // map<int, vector<int>> mp;
    // diagonalUtil(root, 0, mp);
    // for(auto &i : mp)
    // {
    //     for(auto &j : i.second)
    //         cout << j << " ";
    //     cout << endl;
    // }
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 8 9 10 11 -1 13 14 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    Node *root = NULL;
    buildFromLevelOrder(root);
    cout << "\n\nInorder :" << endl << endl;
    inorderTraversal(root);
    cout << "\n\nPreorder :" << endl << endl;
    preorderTraversal(root);
    cout << "\n\nPostorder :" << endl << endl;
    postorderTraversal(root);
    cout << "\n\nZig zag  :" << endl << endl;
    zigZagTraversal(root);
    cout << "\n\nBoundary  :" << endl << endl;
    boundaryTraversal(root);
    cout << "\n\nVertical order  :" << endl << endl;
    verticalOrderTraversal(root);
    cout << "\n\nDiagonal order  :" << endl << endl;
    diagonalOrderTraversal(root);

    cout << endl << endl << "hello\n\n";
    return 0;
}
