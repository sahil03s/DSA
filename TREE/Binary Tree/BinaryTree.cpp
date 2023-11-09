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
        cout << endl;
    }
}

//T.C. = O(n)    S.c. = O(h)
void inorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

//T.C. = O(n)    S.c. = O(h)
void preorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//T.C. = O(n)    S.c. = O(h)
void postorderTraversal(Node* root)
{
    if(root == NULL)
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

//T.C. = O(n)    S.c. = O(n)
void inorderIterative(Node* root)
{
    stack<Node*> stack;
    while(root || !stack.empty())
    {
        while(root)
        {
            stack.push(root);
            root = root->left;
        }

        if(!stack.empty())
        {
            root = stack.top();
            stack.pop();
            cout << root->data << " ";
            root = root->right;
        }

    }

}

//T.C. = O(n)    S.c. = O(h)
void preorderIterative(Node* root)
{
    if(!root)
        return;

    stack<Node*> stack;
    stack.push(root);
    while(!stack.empty())
    {
        root = stack.top();
        stack.pop();
        cout << root->data << " ";
        if(root->right)
            stack.push(root->right);
        if(root->left)
            stack.push(root->left);    
    }
}


//T.C. = O(n)    S.c. = O(n)
void postorderIterative(Node* root)
{
    stack<Node*> stack;
    while(root || !stack.empty())
    {
        while(root)
        {
            if(root->right)
                stack.push(root->right);
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if(!stack.empty() && root->right == stack.top())
        {
            stack.pop();
            stack.push(root);
            root = root->right;
        }
        else
        {
            cout << root->data << " ";
            root = NULL;
        }
    }


    // stack<Node*> stack;
    // while(root || !stack.empty())
    // {
    //     while(root)
    //     {
    //         stack.push(root);
    //         stack.push(root);
    //         root = root->left;
    //     }
    //     root = stack.top();
    //     stack.pop();
    //     if(!stack.empty() && root == stack.top())
    //     {
    //         root = root->right;
    //     }
    //     else
    //     {
    //         cout << root->data << " ";
    //         root = NULL;
    //     }
    // }

    
    //Using 2 stacks
    //T.C. = O(n)    S.c. = O(n)
    // if(!root)
    //     return;
    
    // stack<Node*> s1;
    // stack<Node*> s2;
    // s1.push(root);
    
    // while(!s1.empty())
    // {
    //     Node *temp = s1.top();
    //     s1.pop();
        
    //     s2.push(temp);
        
    //     if(temp->left)
    //         s1.push(temp->left);

    //     if(temp->right)
    //         s1.push(temp->right);
    // }

    // while(!s2.empty())
    // {
    //     Node *temp = s2.top();
    //     s2.pop();
    //     cout << temp->data << " ";
    // }


    
}

//T.C. = O(n)    S.C. = O(h)
int height(Node* &root)
{
    if(root == NULL)
        return 0;
    
    int x = height(root->left);
    int y = height(root->right);

    return max(x,y)+1;
}

//T.C. = O(n)    S.C. = O(h)
void addNodesToMap(Node* root, int level, unordered_map<int, vector<int>> &mp)
{
    if(!root)
        return;
    
    mp[level].push_back(root->data);

    addNodesToMap(root->left, level+1, mp);
    addNodesToMap(root->right, level+1, mp);
}

//T.C. = O(n)    S.C. = O(h)
void reverseLevelOrderTraversal(Node* &root)
{
    unordered_map<int, vector<int>> mp;

    addNodesToMap(root, 0, mp);

    for(int i = mp.size()-1; i>=0; i--)
    {
        for(auto itr = mp[i].begin(); itr != mp[i].end(); itr++)
            cout << *itr << " ";
        cout << endl;
    }

//T.C. = O(n)    S.C. = O(n)
    // if(!root)
    //     return;
    
    // unordered_map<int, vector<Node*>> mp;

    // queue<Node*> q;
    // q.push(root);
    // int level = -1;
    // while(!q.empty())
    // {
    //     level++;
    //     int n = q.size();
    //     while(n--)
    //     {
    //         Node *temp = q.front();
    //         q.pop();

    //         mp[level].push_back(temp);

    //         if(temp->left)
    //             q.push(temp->left);
    //         if(temp->right)
    //             q.push(temp->right);
    //     }
    // }

    // for(int i = mp.size()-1; i>=0; i--)
    // {
    //     for(auto itr = mp[i].begin(); itr != mp[i].end(); itr++)
    //         cout << (*itr)->data << " ";
    //     cout << endl;
    // }


//T.C. = O(n)    S.C. = O(n)
    // if(!root)
    //     return;

    // queue<Node*> q;
    // q.push(root);
    // vector<vector<int>> ans;
    // while(!q.empty())
    // {
    //     int n = q.size();
    //     vector<int> t; 
    //     while(n--)
    //     {
    //         Node *temp = q.front();
    //         q.pop();
    //         if(temp->left)
    //             q.push(temp->left);
    //         if(temp->right)
    //             q.push(temp->right);
            
    //         t.push_back(temp->data);
    //     }
    //     ans.push_back(t);
    // }

    // reverse(ans.begin(), ans.end());
    // for(auto i : ans)
    // {
    //     for(auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }


//T.C. = O(n)    S.C. = O(n)
    // if(!root)
    //     return;
    
    // queue<Node*> q;
    // q.push(root);
    // stack<Node*> st;
    // while(!q.empty())
    // {
    //     Node* temp = q.front();
    //     q.pop();
    //     st.push(temp);
    //     if(temp->right)
    //         q.push(temp->right);
    //     if(temp->left)
    //         q.push(temp->left);
    // }
    // while(!st.empty())
    // {
    //     cout << st.top()->data << " ";
    //     st.pop();
    // }
}

//1 2 3 4 5 6 7 8 9 10 11 -1 13 14 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    Node *root = NULL;
    buildFromLevelOrder(root);
    cout << "\n\nLevel order :" << endl;
    levelOrderTraversal(root);
    cout << "\n\nReverseLevel order :" << endl << endl;
    reverseLevelOrderTraversal(root);
    cout << "\n\nInorder :" << endl << endl;
    inorderTraversal(root);
    cout << "\n\nInorder iterative :" << endl << endl;
    inorderIterative(root);
    cout << "\n\nPreorder :" << endl << endl;
    preorderTraversal(root);
    cout << "\n\nPreorder iterative :" << endl << endl;
    preorderIterative(root);
    cout << "\n\nPostorder :" << endl << endl;
    postorderTraversal(root);
    cout << "\n\nPostorder Iterative:" << endl << endl;
    postorderIterative(root);
    cout << "\n\nHeight = " << height(root) << endl;
    cout << endl << endl << "hello\n\n";
    return 0;
}
