#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>

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

//T.C. = O(n)   S.C. = O(h)
bool findPath(Node* root, int n, vector<Node*> &path)
{
    if(!root)
        return false;
        
    path.push_back(root);
        
    if(root->data == n)
        return true;
        
    if(findPath(root->left, n, path) || findPath(root->right, n, path))
        return true;
        
    path.pop_back();
    return false;
}

//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
//T.C. = O(n)   S.C. = O(h)
Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;
            
    Node* leftAns = lca(root->left,n1,n2);
    Node* rightAns = lca(root->right,n1,n2);
        
    if(leftAns && rightAns)
        return root;
        
    else if(leftAns)
        return leftAns;
    else
        return rightAns;

//T.C. = O(n)   S.C. = O(h)
    // vector<Node*> v1;
    // vector<Node*> v2;
    // if( !findPath(root, n1, v1), !findPath(root, n2, v2) )
    //     return NULL;
        
    // int i=0;
    // for(; i<v1.size() && i<v2.size(); i++)
    // {
    //     if(v1[i] != v2[i])
    //         break;
    // }
        
    // return v1[i-1];
}

//T.C. = O(n)   S.C. = O(h)
int AncestorK(Node *root, int &k, int node) //solver returns -1 if node is not found in current path else returns k'th ancestor
{
    if(!root)
        return -1;
    
    if(root->data == node)
        return root->data;
    
    int leftAns = AncestorK(root->left, k, node);
    int rightAns = AncestorK(root->right, k, node);
    
    if(leftAns != -1 || rightAns != -1)
    {
        k--;
        if(k<=0)
        {
            k = INT_MAX;
            return root->data;
        }
            
        return (leftAns != -1)? leftAns : rightAns;
    }
        
    return -1;
}

//https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
//T.C. = O(n)   S.C. = O(h)
int kthAncestor(Node *root, int k, int node)
{
    int ans = AncestorK(root, k, node);
    //it is given that all nodes  in tree are distinct, and k>=1. 
    //Solver returns node, in case when node is present but it has less than k ancestors.
    if(ans == node)
        return -1;
    
    return ans;

//T.C. = O(n)   S.C. = O(h)
    // vector<Node*> path;
    
    // findPath(root, node, path);
    
    // if(path.size() < k+1)
    //     return -1;
    
    // return path[path.size()-1-k]->data;
    
}

void sumK(Node* root, int k, int sum, int &count, unordered_map<int, int> &mp)
{
    if(!root)
        return;
        
    sum += root->data;
    count += mp[sum-k];
        
    mp[sum] += 1;
        
        
    if(sum == k)
        count += 1;
        
    sumK(root->left, k, sum, count, mp);
    sumK(root->right, k, sum, count, mp);
        
    mp[sum]--;        
}

//https://practice.geeksforgeeks.org/problems/k-sum-paths/1
//T.C. = O(n)   S.C. = O(n)
int kSum(Node *root,int k)
{
    int count = 0;
    int sum = 0;
    unordered_map<int, int> mp;
    sumK(root, k, sum, count, mp);
    return count;
}

//T.C. = O(n)   S.C. = O(h)
pair<int, int> MaxSum(Node* root)
{
    if(!root)
        return {0,0};
        
    pair<int,int> left = MaxSum(root->left);
    pair<int,int> right = MaxSum(root->right);
    pair<int, int> ans;
    ans.first = left.second + right.second + root->data;
    ans.second = max(left.first,left.second) + max(right.first, right.second);
        
    return ans;
        
}

//https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
//T.C. = O(n)   S.C. = O(h)
int getMaxSum(Node *root) 
{
    pair<int, int> ans = MaxSum(root);
    return max(ans.first, ans.second);
}

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

    cout << endl << endl << "hello\n\n";
    return 0;
}
