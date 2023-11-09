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

// T.C. = O(nLogn)   S.C. = O(n)
void topView(Node* &root)
{
    if(root == NULL)
        return;
    
    queue<pair<Node*,int>> q;
    q.push({root,0});

    map<int, int> mp;

    while(!q.empty())
    {
        pair<Node*, int> t = q.front();
        q.pop();
        Node* temp = t.first;
        int d = t.second;

        if(mp.find(d) == mp.end())
            mp[d] = temp->data;
        
        if(temp->left)
            q.push({temp->left, d-1});
        if(temp->right)
            q.push({temp->right, d+1});
    }

    for(auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->second << " ";

    cout << "\n\n";
}

// T.C. = O(nLogn)   S.C. = O(n)
void bottomView(Node* &root)
{
    if(root == NULL)
        return;
    
    queue<pair<Node*,int>> q;
    q.push({root,0});

    map<int, int> mp;

    while(!q.empty())
    {
        pair<Node*, int> t = q.front();
        q.pop();
        Node* temp = t.first;
        int d = t.second;

        mp[d] = temp->data;
        
        if(temp->left)
            q.push({temp->left, d-1});
        if(temp->right)
            q.push({temp->right, d+1});
    }

    for(auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->second << " ";

    cout << "\n\n";
}

// T.C. = O(n)   S.C. = O(h)
void leftView(Node* &root)
{

    // if(root == NULL)
    //     return;
    
    // if(maxLevel < level)
    // {
    //     cout << root->data << " ";
    //     maxLevel = level;
    // }
    
    // leftView(root->left, maxLevel, level+1);
    // leftView(root->right, maxLevel, level+1);

    // T.C. = O(n)   S.C. = O(n)

    if(root == NULL)
        return;
    
    queue<pair<Node*,int>> q;
    q.push({root,0});

    vector<int> ans;

    while(!q.empty())
    {
        pair<Node*, int> t = q.front();
        q.pop();
        Node* temp = t.first;
        int level = t.second;

        if(level == ans.size())
        {
            ans.push_back(temp->data);
            cout << temp->data << " ";
        }
        
        if(temp->left)
            q.push({temp->left, level+1});
        if(temp->right)
            q.push({temp->right, level+1});
    }

    cout << "\n\n";
}

// T.C. = O(n)   S.C. = O(h)
void rightView(Node* root, int maxLevel = 0, int level = 0)
{
    // if(root == NULL)
    //     return;
    
    // if(level == maxLevel)
    // {
    //     cout << root->data << " ";
    //     maxLevel++;
    // }
    
    // rightView(root->right, maxLevel, level+1);
    // rightView(root->left, maxLevel, level+1);

    // T.C. = O(n)   S.C. = O(n)

    if(root == NULL)
        return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();
        while(n--)
        {
            root = q.front();
            q.pop();
        
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        cout << root->data << " ";
    }

    cout << "\n\n";
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
    cout << "\n\nPreorder :" << endl;
    preorderTraversal(root);
    cout << "\n\nPostorder :" << endl;
    postorderTraversal(root);
    cout << "\n\nVertical order  :" << endl;
    verticalOrderTraversal(root);
    cout << "\n\nTop View :" << endl;
    topView(root);
    cout << "\n\nBottom View :" << endl;
    bottomView(root);
    cout << "\n\nLeft View :" << endl;
    leftView(root);
    cout << "\n\nRight View :" << endl ;
    rightView(root);

    cout << endl << endl << "hello\n\n";
    return 0;
}
