#include <iostream>
using namespace std;
class node
{
public:
    char val;
    node *left, *right;
    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
    node(char val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Stack
{
public:
    node *treeNode;
    Stack *next;
    Stack(node *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }
};
class ExpressionTree
{
private:
    Stack *top;
public:
    node *root;
    ExpressionTree()
    {
        top = NULL;
    }
    void push(node *ptr);
    void insert(char val);
    void inOrder(node *root);
    void postOrder(node *root);
    void deleteTree(node* root);
   
    node *pop()
    {
        node *ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
    node *treetoproot()
    {
        return top->treeNode;
    }
    
    bool isOperand(char ch)
    {
        return ch >= '0' && ch <= '9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
    }
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    void construct(string eqn)
    {
        for (int i = eqn.length() - 1; i >= 0; i--)
            insert(eqn[i]);
    }
    
};


 // function to push a node in stack
void ExpressionTree::push(node *ptr)
    {
        if (top == NULL)
            top = new Stack(ptr);
        else
        {
            Stack *nptr = new Stack(ptr);
            nptr->next = top;
            top = nptr;
        }
    }
    
void ExpressionTree::insert(char val)
    {
        if (isOperand(val))
        {
            node *nptr = new node(val);
            push(nptr);
        }
        else if (isOperator(val))
        {
            node *nptr = new node(val);
            nptr->left = pop();
            nptr->right = pop();
            push(nptr);
        }
    }
    
void ExpressionTree::inOrder(node *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout<<root->val;
            inOrder(root->right);
        }
    }
void ExpressionTree::postOrder(node *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout<<root->val;
        }
    }
void ExpressionTree::deleteTree(node* root) {
    if (root == NULL)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}    
int main()
{
    string exp;
    ExpressionTree et;
    cout<<"Enter expression in Prefix form: ";
    cin>>exp;
    et.construct(exp);
    int choice;
    int n;
    cout<<"do you want to continue?";
    cin>>n;
    if(n==1);
    while(1){
        cout<<"\n1.Inorder";
        cout<<"\n2.Postorder";
        cout<<"\n3.Delete";
        cout<<"\n4.exit";
        cout<<"\n Enter your choice:";
        cin>>choice;
        switch (choice){
            case 1:
            cout<<"\nIn-order Traversal of Expression Tree";
            et.inOrder(et.treetoproot());
            break;
            case 2:
            cout<<"\nPost-order Traversal of Expression Tree";
            et.postOrder(et.treetoproot());
            break;
            case 3:
            cout<<"\nafter deleting the tree";
            et.deleteTree(et.root);
            break;
            case 4:
            exit(1);
            break;
        }
    }    
    return 0;
};
