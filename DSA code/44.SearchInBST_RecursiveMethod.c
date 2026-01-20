#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int data;
    struct treeNode* prev;
    struct treeNode* next;
};
struct treeNode* createNode(int val){
    struct treeNode* newNode=(struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
struct treeNode* search(struct treeNode* root, int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    else if(root->data > key){
        return search(root->prev, key);
    }else{
        return search(root->next, key);
    }
}
int main(){
    struct treeNode* node=createNode(50);
    node->prev=createNode(25);
    node->next=createNode(75);
    node->prev->prev=createNode(10);
    node->prev->next=createNode(40);
    node->next->prev=createNode(70);
    node->next->next=createNode(80);
    struct treeNode* n=search(node,40);
    if(n!=NULL) printf("found %d",n->data);
    else printf("not found");
    return 0;
    
}