#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertInBST(root->right, data);
    }

    if (data < root->data)
    {
        root->left = insertInBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *minValue(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node* predeccesser(Node *root)
{
    if (root->right)
        return predeccesser(root->right);

    else
        return root;
}

Node* successor(Node *root)
{
    if (root->left)
        return successor(root->left);
    else
        return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "Inorder of BST" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder of BST" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder of BST" << endl;
    postorder(root);
    cout << endl;
    cout << "Level order traversal" << endl;
    levelOrderTraversal(root);

    cout << "Min value is: " << minValue(root)->data << endl;
    cout << "Max value is: " << maxValue(root)->data << endl;

    // 10 8 21 7 27 5 4 3-1
    cout<<"INorder predecessor: "<<predeccesser(root)->data<<endl;
    cout<<"INorder successor: "<<successor(root)->data<<endl;

    return 0;
}