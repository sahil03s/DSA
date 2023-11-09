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


//this functions maps each node to its parent node and returns a node whose data = target, if not found, it returns null
Node* preorder(Node* root, unordered_map<Node*, Node*> &parentMap, int target)
{
    //base case
    if(!root)
        return NULL;
        
    //mapping left child with parent
    if(root->left)
        parentMap[root->left] = root;

    //mapping right child with parent
    if(root->right)
        parentMap[root->right] = root;
            
    //recursive call
    Node *leftAns = preorder(root->left, parentMap, target);
    Node *rightAns = preorder(root->right, parentMap, target);
        
    if(root->data == target)
        return root;
        
    if(leftAns)
        return leftAns;
    else
        return rightAns;
}

//https://practice.geeksforgeeks.org/problems/burning-tree/1
//T.C. = O(n)   S.C. = O(n)
int minTime(Node* root, int target) 
{
    //mapping each node to its parent
    unordered_map<Node*, Node*> parentMap;
    parentMap[root] = NULL;
    Node *curr = preorder(root, parentMap, target);
        
    unordered_map<int, bool> visited;
    queue<Node*> q;
    q.push(curr);
    int t = 0;
        
    while(!q.empty())
    {
        int n = q.size();
        int flag = 0;
        while(n--)
        {
                
            curr = q.front();
            q.pop();
            visited[curr->data] = true;
                
            if(curr->left && !visited[curr->left->data])
            {
                q.push(curr->left);
                visited[curr->left->data] = true;
                flag = 1;
            }
            if(curr->right && !visited[curr->right->data])
            {
                q.push(curr->right);
                visited[curr->right->data] = true;
                flag = 1;
            }
            if(parentMap[curr] && !visited[parentMap[curr]->data])
            {
                q.push(parentMap[curr]);
                visited[parentMap[curr]->data] = true;
                flag = 1;
            }
            
        }
        if(flag)
            t++;
    }
        
    return t;
}

int main()
{
    Node *root = NULL;
    buildFromLevelOrder(root);
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