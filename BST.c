#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    struct Node* p;
};

struct Tree{
    struct Node* root;
};

void insert(struct Tree* T,int x){
    struct Node* z = malloc(sizeof(struct Node));
    z->key = x;
    z->left = NULL;
    z->right = NULL;
    z->p = NULL;
    insert(&T, z);
    struct Node* x =T->root;
    struct Node* y= NULL;
    while(x!=NULL){
        y=x;
        if(z->key<x->key){
            x = x->left;
        }else{
            x = x->right;   
        }
    }
    z->p=y;
    if(y==NULL){
        T->root=z;
    }else if(z->key<y->key){
        y->left=z;
    }else{
        y->right=z;
    }
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}

void predecessor(struct Node* n){
    struct Node* temp = n;
    if(n->left!=NULL){
        struct Node* x =n->left;
        while(x->right!=NULL){
            x =x->right;
        }
        printf("Predecessor of %d is %d",temp->key,x->key);
    }else{
        struct Node* y =temp->p;
        while(y!=NULL && temp==y->left){
            temp=y;
            y=y->p;
        }
        if(y==NULL){
            printf("Predecessor of %d does not exist",n->key);
        }else{
            printf("Predecessor of %d is %d",n->key,y->key);
        }
    }
}

void successor(struct Node* n){
    struct Node* temp = n;
    if(n->right!=NULL){
        struct Node* x =n->right;
        while(x->left!=NULL){
            x =x->left;
        }
        printf("Successor of %d is %d",temp->key,x->key);
    }else{
        struct Node* y =temp->p;
        while(y!=NULL && temp==y->right){
            temp=y;
            y=y->p;
        }
        if(y==NULL){
            printf("Successor of %d does not exist",n->key);
        }else{
            printf("Successor of %d is %d",n->key,y->key);
        }
    }
}

struct Node* Tree_Search(struct Node* x, int k){
    if(x==NULL||k==x->key){
        return x;
    }
    if(k<x->key){
        return Tree_Search(x->left, k);
    }else{
        return Tree_Search(x->right,k);
    }
}

void Transplant(struct Tree* T, struct Node* u, struct Node* v){
    if(u->p==NULL){
        T->root=v;
    }else if(u==u->p->left){
        u->p->left=v;
    }else{
        u->p->right=v;
    }
    if(v!=NULL){
        v->p=u->p;
    }
}

void Tree_Delete(struct Tree* T, struct Node* z){
    if(z->left==NULL){
        Transplant(T,z,z->right);
    }else if(z->right==NULL){
        Transplant(T,z,z->left);
    }else{
        struct Node* y = Tree_Minimum(z->right);
        if(y->p!=z){
            Transplant(T,y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        Transplant(T,z,y);
        y->left=z->left;
        y->left->p=y;
    }
}

//Morris Inorder Traversal for Binary Search Tree

struct Node* Predecessor(struct Node* root){
    struct Node* temp=root->left;
    while((temp->right!=NULL)&&(temp->right!=root)){
        temp=temp->right;
    }
    return temp;
}

void Morris_inorder(struct Node* root){
    struct Node* c=root;
    while(c!=NULL){
        if(c->left==NULL){
            printf("%d ",c->key);
            c=c->right;
        }else{
            struct Node* pre=Predecessor(c);
            if(pre->right==NULL){
                pre->right=c;
                c=c->left;
            }else{
                pre->right=NULL;
                printf("%d ",c->key);
                c=c->right;
            }
        }
    }
}
