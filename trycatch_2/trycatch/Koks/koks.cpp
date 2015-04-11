#include <iostream>
#include <stdlib.h>

using namespace std;
//////////////////////////////////////////////////////////////
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int item, TreeNode *l = NULL, TreeNode *r = NULL);
};

TreeNode::TreeNode(int item, TreeNode *l, TreeNode *r)
{
    data = item;
    left = l;
    right = r;
}
//////////////////////////////////////////////////////////////

class Tree
{
public:
    Tree();
    ~Tree(void);
    TreeNode* FindNode(int, TreeNode* &);
    void Insert(int);
    void Delete(int);
    void DeleteTree(TreeNode*);
    void PrintTree(TreeNode*, int);
    void Inorder(TreeNode*);
    void Postorder(TreeNode*);
    void Preorder(TreeNode*);
    TreeNode* GetTreeNode(int item, TreeNode *l = NULL, TreeNode *r = NULL);
    void FreeTreeNode(TreeNode *p);
    
    int size;
    TreeNode *root;
    TreeNode *current;

};

Tree::Tree()
{
    root = NULL;
    size = 0;
}

Tree::~Tree()
{
    DeleteTree(root);
}

TreeNode* Tree::GetTreeNode(int item, TreeNode *l, TreeNode *r)
{
    TreeNode *p;
    p = new TreeNode(item, l, r);
    return p;
}

void Tree::FreeTreeNode(TreeNode *p)
{
    delete p;
}

void Tree::DeleteTree(TreeNode *t)
{
    if (t!=NULL)
    {
        DeleteTree(t->left);
        DeleteTree(t->right);
        FreeTreeNode(t);
    }       
}


void IndentBlanks(int num)
{
    for(int i=0; i<num; i++)
       cout << " ";
}    

void Tree::PrintTree(TreeNode *t, int level)
{
    if (t!=NULL)
    {
        PrintTree(t->right, level+1);
        IndentBlanks(6*level);
        cout << t->data << endl;
        PrintTree(t->left, level+1);
    }
}     


void Tree::Inorder(TreeNode *t)
{
    if (t!=NULL)
    {
        Inorder(t->left);
        cout << t->data << " ";
        Inorder(t->right);
    }
}  


void Tree::Postorder(TreeNode *t)
{
    if (t!=NULL)
    {
        Postorder(t->left);
        Postorder(t->right);
        cout << t->data << " ";
    }
}


void Tree::Preorder(TreeNode *t)
{
    if (t!=NULL)
    {
        cout << t->data << " ";
        Preorder(t->left);
        Preorder(t->right);
    }
}    



TreeNode* Tree::FindNode(int item, TreeNode *&parent)
{
    TreeNode *t = root;
    parent = NULL;
    while(t!=NULL)
    {
        if (item == t->data)
            break;
        else
        {
            parent = t;
            if (item < t->data)
                t = t->left;
            else
                t = t->right;
        }
    }
    return t;
}              


void Tree::Insert(int item)
{
    TreeNode *t = root, *parent = NULL, *newNode;
    newNode = GetTreeNode(item, NULL, NULL);
    
    while(t!=NULL)
    {
        parent = t;
        if (item < t->data)
            t = t->left;
        else
            t = t->right;
    }
    
    if (parent == NULL)
        root = newNode;
    else if (item < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
        
    current = newNode;
    size++;
}    
   
        
void Tree::Delete(int item)
{
    TreeNode *DNodePtr; //raditajs uz dzesamo mezglu
    TreeNode *PNodePtr; //raditajs uz dzesama mezgla prieksteci
    TreeNode *RNodePtr; //raditajs uz mezglu kas aizvieto dzeesamo

    //mekleejam elementu kas jaadzees, un taa prieksteci
    if((DNodePtr = FindNode(item, PNodePtr)) == NULL) 
        return;

    //ja viens peectecis
    if(DNodePtr->right == NULL)
        RNodePtr = DNodePtr->left;
    else if(DNodePtr->left == NULL)
        RNodePtr = DNodePtr->right;
        
    //ja divi peecteci    
    else
    {
        TreeNode *PofRNodePtr = DNodePtr; //raditajs uz RNodePtr prieksteci
        RNodePtr = DNodePtr->left; //izveelamies kreisa zara 1. elementu, jo tas kas aizvieto ir mazaak par dzeesamo
        
        while(RNodePtr->right != NULL) //kreisaa pusee ejam liidz galam pa labi, saglabajot RNodePtr un PofRNodePtr vertiibas
        {
            PofRNodePtr = RNodePtr;
            RNodePtr = RNodePtr->right;
        }

        if(PofRNodePtr == DNodePtr) //kreisaa pusee 1. elementam nav peectecu labaa pusee (Situaacija D1)
        {
            RNodePtr->right = DNodePtr->right; //pievienojam dzeesama elementa labo apakskoku sim elementam
        }
        else //kreisaa pusee 1. elementam ir peecteci labaa pusee (Situaacija D2)
        //atrasto elementu jaanem araa, jaasavieno iznemta elementa zaru ar pamatkoku
        {
            RNodePtr->right = DNodePtr->right;
            PofRNodePtr->right = NULL;
            RNodePtr->left = DNodePtr->left;
        }
    }

    if(PNodePtr == NULL)
    {
        RNodePtr->left = root->left;
        RNodePtr->right = root->right;
        root = RNodePtr;
    }    
    //jaapievieno RNodePtr mezglu pie PNodePtr mezgla no pareizaas puses
    else if(DNodePtr->data < PNodePtr->data)
        PNodePtr->left = RNodePtr;
    else
        PNodePtr->right = RNodePtr;

    FreeTreeNode(DNodePtr); //dzeesam elementu
    size--;
}     
//////////////////////////////////////////////////////////////




int main()
{
  Tree tree;
  tree.Insert(50);
  tree.Insert(100);
  tree.Insert(25);
  tree.Insert(150);
  tree.Insert(75);
  tree.Insert(35);
  tree.Insert(15);
  tree.Insert(80);
  tree.Insert(55);
  tree.Insert(7);
  tree.Insert(20);
  
  tree.Inorder(tree.root);
  cout << endl;
  tree.Postorder(tree.root);
  cout << endl;
  tree.Preorder(tree.root);
  cout << endl << endl;
  
  tree.PrintTree(tree.root, 0);
  
  tree.Delete(50);
  cout << endl << endl;
  tree.PrintTree(tree.root, 0);
  
  system("PAUSE");	
  return 0;
}
