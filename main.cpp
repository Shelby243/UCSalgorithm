#include <cstdlib>
#include <iostream>
using namespace std;

struct  node {
	int data;
	char const *ch;
	struct node * left;
	struct node * right;
};
struct node * newNode(int d,char const *ch)
{
	struct node *temp;
	temp=(struct node *) malloc(sizeof(node));
	temp->data=d;
	temp->ch=ch;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct node * insertLeft(struct node * tree, struct node *p)
{
	if(tree ==NULL)
		return p;
	tree->left=insertLeft(tree->left, p);
	return tree;
}

struct node * insertRight(struct node * tree, struct node *p)
{
	if(tree ==NULL)
		return p;
	tree->right=insertRight(tree->right, p);
	return tree;
}
void displayTree(struct node *header,int depth, char leaf)
{
    if (header==NULL)
        return;
    else
    {
        for(int i=0;i<depth;i++)
            std::cout<<"-";
        std::cout<<header->data<<"("<<leaf<<")"<<":"<<header->ch<<" "<<depth<<";"<<"\n";
        displayTree(header->left,depth+1,'L');
    }   displayTree(header->right,depth+1,'R');
}
void displayAllTree(struct node *header, char const *title)
{
    struct node*temp;
    std::cout<<title<<"\n";
    displayTree(header,0,'R');
    std::cout<<"\n";
}

struct Qnode{
	struct node *node;
	struct Qnode *next;
};

struct Qnode* new_node(struct node* d)
{
	struct Qnode* temp;
	temp=(struct Qnode *)malloc(sizeof(struct Qnode));
	temp->node=d;
	temp->next=NULL;
	return temp;
}
struct Qnode* insertBack(struct Qnode *header, struct node *d)
{
	struct Qnode *temp, *headertemp;
	temp=new_node(d);
	if(header==NULL)
	{
		header=temp;
		return header;
	}
	headertemp=header;
	while(headertemp->next!=NULL)
		headertemp=headertemp->next;
	headertemp->next=temp;
	return header;
}

void displayLL(struct Qnode *header, char const *title)
{
    struct Qnode*temp;
    std::cout<<title<<"\n";
	for(temp=header; temp!=NULL; temp=temp->next)
        std::cout<<temp->node->data<<" ";
    std::cout<<"\n";
}

int main(int argc, char *argv[])
{
    struct Qnode *queue=NULL;




    struct node *tree=NULL;
    struct node *temp=NULL;
	tree=newNode(0,"S");
	temp=newNode(12,"G");
	queue=insertBack(queue,temp);
	tree->left=insertLeft( tree->left,temp);
	displayLL(queue,"Queue");

	temp=newNode(1,"A");
	queue=insertBack(queue,temp);
	tree->right=insertRight( tree->right,temp);
//    queue=deleteFront(queue);
    displayLL(queue,"Queue");


	temp=newNode(1,"C");
	tree->right=insertLeft( tree->right,temp);
	temp=newNode(3,"B");
	tree->right=insertRight(tree->right,temp);
	temp=newNode(2,"G1");
	tree->right=insertLeft(tree->right,temp);
	temp=newNode(1,"D");
	tree->left=insertRight(tree->left,temp);
	temp=newNode(3,"D1");
	tree->right=insertLeft(tree->right,temp);
	temp=newNode(3,"G2");
	tree->left=insertLeft(tree->left,temp);

	//cout<<tree->data<<" "<<tree->left->data<<" "<<tree->right->data;
	
    displayAllTree(tree,"tree");
    system("PAUSE");
    return EXIT_SUCCESS;
}

