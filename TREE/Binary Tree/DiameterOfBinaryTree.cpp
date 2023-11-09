#include <iostream>
#include <queue>
#include <stack>

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

//T.C. = O(n)    S.C. = O(h)
int height(Node* &root)
{
    if(root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight, rightHeight)+1;

    return ans;
}

//T.C. = O(n^2)    S.C. = O(h)
int diameter(Node* &root)
{
    if(root == NULL)
        return 0;
    
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int rootDiameter = height(root->left) + height(root->right) + 1;

    int ans = max(rootDiameter, max(leftDiameter,rightDiameter));
}

//T.C. = O(n)    S.C. = O(h)
pair<int,int> diameterFast(Node* &root)
{
    if(root == NULL)
        return {0,0};

    pair<int,int> p1 = diameterFast(root->left);
    pair<int,int> p2 = diameterFast(root->right);

    pair<int, int> ans;
    ans.first = max( (p1.second+p2.second+1), max(p1.first, p2.first));
    ans.second = max(p1.second, p2.second)+1;

    return ans;
}

//T.C. = O(n^2)    S.C. = O(h)
bool isBalanced(Node *root)
{
    if(root == NULL)
        return true;
        
    bool leftBal = isBalanced(root->left);
    bool rightBal = isBalanced(root->right);
    bool rootBal = abs( height(root->left)-height(root->right) <=1 ) ;
        
    bool ans = (leftBal && rightBal && rootBal);
}

//T.C. = O(n)    S.C. = O(h)
pair<bool, int> isBalancedFast(Node* &root)
{
    if(root == NULL)
        return {true,0};
            
    pair<bool, int> leftAns = isBalancedFast(root->left);
    pair<bool, int> rightAns = isBalancedFast(root->right);
    bool diff = abs(leftAns.second - rightAns.second)<=1;
        
    pair<bool, int> ans;
    ans.first = (leftAns.first && rightAns.first && diff);
    ans.second = max(leftAns.second, rightAns.second)+1;
    
    return ans;
}


//T.C. = O(n)    S.C. = O(h)
bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL)
        return true;
        
    if(r1 == NULL || r2 == NULL || r1->data != r2->data)
        return false;
            
        
    return (isIdentical(r1->left,r2->left) && isIdentical(r1->right, r2->right));
}

//https://practice.geeksforgeeks.org/problems/sum-tree/1
//returns true if root->val == sum of all elements of its left and right subtree
//T.C. = O(n)    S.C. = O(h)
pair<bool,int> isSumTree(Node* &root)
{
    if(root == NULL)
        return {true,0};
        
    pair<bool,int> left = isSumTree(root->left);
    pair<bool,int> right = isSumTree(root->right);
    bool diff = (root->left == NULL && root->right == NULL || root->data == left.second + right.second);
        
    pair<bool,int> ans;
    ans.first = (left.first && right.first && diff);
    ans.second = root->data + left.second + right.second;
          
    return ans;
        
}


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
//1 2 3 4 5 6 7 8 9 10 11 -1 13 14 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

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
    cout << "\n\nHeight = " << height(root) << endl;
    cout << "\n\nHeight = " << diameterFast(root).second << endl;
    cout << "\n\nDiameter = " << diameter(root) << endl;
    cout << "\n\nDiameter = " << diameterFast(root).first << endl;
    cout << endl << endl << "hello\n\n";
    return 0;
}
