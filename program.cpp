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
        std::cout<<header->data<<"("<<leaf<<")"<<":"<<header->ch<<" "<<depth<<"\n";
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

 

void uniformCS(struct node *header){
	struct node* queue[1000];
	int front=0,rear=0;
	
	queue[rear++]=header;
	 
	while(front!=rear){
		int minCost=1000;
		int minIndex=-1;
		for(int i=front;i<rear;i++){
			if(queue[i]->data<minCost){
				minCost=queue[i]->data;
				minIndex=i;
			}
		}
		struct node *node=queue[minIndex];
		for(int i=minIndex;i<rear-1;i++){
			queue[i]=queue[i+1];
		}
	 
		rear--;
		
		std::cout<<node->ch<<endl;
		if(node->left!=NULL){
			queue[rear++]=node->left;
		}
		if(node->right!=NULL){
			queue[rear++]=node->right;
		}
	}
	
}
int main(int argc, char *argv[])
{
    struct Qnode *queue=NULL;




    struct node *tree=NULL;
    struct node *temp=NULL;
   
	tree=newNode(0,"S");
	tree->left=newNode(12,"G");
	tree->right=newNode(1,"A");
	tree->right->left=newNode(1,"C");
	tree->right->right=newNode(3,"B");
	tree->right->left->left=newNode(2,"G1");
	tree->right->right->left=newNode(3,"D1");
	tree->right->left->right=newNode(1,"D");
	tree->right->right->left->left=newNode(1,"G2");
	
	
    displayAllTree(tree,"tree");
    std::cout<<"\n";
    uniformCS(tree);
    system("PAUSE");
    return EXIT_SUCCESS;
}

