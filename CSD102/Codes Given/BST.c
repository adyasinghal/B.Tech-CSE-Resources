//BST

#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode{
int data;
struct  bstnode *left;
struct  bstnode *right;
}node;

node *root=NULL;
node *p;

node *insert(node *, int);
void search(node *, int);
void inorder(node *);
void delete();

void main(){
int ch,element;

while(1){
printf("\n1. To insert element in BST\n");
printf("2. To search an element\n");
printf("3. To print inorder of BST\n");
printf("4. To delete an element in BST\n");
printf("5. Exit\n");
printf("Enter your choice\n");
scanf("%d", &ch);
switch(ch){

case 1: printf("Enter an element to insert\n");
        scanf("%d",&element);
        root=insert(root,element);
        break;
case 2: printf("Enter an element to search\n");
        scanf("%d",&element);
        search(root,element);
        break;
case 3: inorder(root);
        break;
case 4: delete();
	break;
case 5:
        exit(0);
default:  printf("You have entered wrong choice");
          break;
}
}
}

node *insert(node *root,int element)
{
    if(root==NULL)
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->data=element;
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(element<root->data)
        root->left=insert(root->left,element);
    else
        root->right=insert(root->right,element);
    return root;
}

void search(node *root, int key)
{
    if (root == NULL)
            printf("Element not present\n");
    else if(key == root->data)
            printf("Element is present in the tree\n");
      else if (key < root->data)
            search(root->left, key);
      else
            search(root->right, key);

}

void inorder(node *rootnode)
{
    if(rootnode == NULL)
       return;
    if(rootnode->left != NULL)
        inorder(rootnode->left);
    printf("%d\n", rootnode->data);
    if(rootnode->right!= NULL)
        inorder(rootnode->right);
}

void delete(){
int data;
if(root == NULL)
printf("Empty tree");
printf("Enter element to be deleted");
scanf("%d", &data);
p = root;
searchNode(root, data);
}

void searchNode(struct bstnode *x, int data){
if(data > x->value)
{
   p=x;
   searchNode(x->r, data);
}

else if(data < x->value)
{
    p=x;
    searchNode(x->l, data);
}
else if (data == x->value)
{
    deleteNode(x);
}
}

void deleteNode(struct bstnode *x){
int successor;
/* to delete leafnode*/
if((x->l == NULL)&&(x->r == NULL))
{
if(p==x)
root=NULL;   
else if(p->l == x)
    p->l =NULL;
   else
    p->r = NULL;
     
     free(x);
 }

/*to delete node which has one left child*/
else if (x->r == NULL)
{
       if(p == x)
       {
        	root = x->l;
        	p= root;
        }
       else if(p->l == x)
        	p->l = x->l;
       else
	p->r = x->l;
      free(x);
}

/*to delete node which has one right child*/
else if(x->l == NULL)
{
	if (p == x)
	{
     		root = x->r;
     		p= root;
   	}
  	else if(p->r == x)
  		p->r = x->r;
	else
   		p->l = x->r;
	
  	free(x);
}

/*to delete node which has two non-empty children*/
else if((x->l != NULL)&&(x->r != NULL))
{
	successor = smallest(x->r);
	searchNode(root, successor);
	x->value = successor;
}
}

int smallest(struct bstnode *x)
{
	if(x->l != NULL)
   		smallest(x->l);
	else
    		return(x->value);
}