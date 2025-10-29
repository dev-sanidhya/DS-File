#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char type[20], comp[20];
    int year;
    struct Node *l, *r;
};

struct Node* newNode(char t[], char c[], int y) {
    struct Node* n = malloc(sizeof(struct Node));
    strcpy(n->type, t); strcpy(n->comp, c);
    n->year = y; n->l = n->r = NULL;
    return n;
}

struct Node* insert(struct Node* r, char t[], char c[], int y) {
    if (!r) return newNode(t, c, y);
    if (y < r->year) r->l = insert(r->l, t, c, y);
    else r->r = insert(r->r, t, c, y);
    return r;
}

struct Node* min(struct Node* r){while(r->l)r=r->l;return r;}

struct Node* del(struct Node* r, int y) {
    if (!r) return NULL;
    if (y < r->year) r->l = del(r->l, y);
    else if (y > r->year) r->r = del(r->r, y);
    else {
        if (!r->l) {struct Node* t=r->r; free(r); return t;}
        else if (!r->r){struct Node* t=r->l; free(r); return t;}
        struct Node* t=min(r->r);
        r->year=t->year; strcpy(r->type,t->type); strcpy(r->comp,t->comp);
        r->r=del(r->r,t->year);
    }
    return r;
}

void in(struct Node* r){if(!r)return;in(r->l);printf("%s %s %d\n",r->type,r->comp,r->year);in(r->r);}
void pre(struct Node* r){if(!r)return;printf("%s %s %d\n",r->type,r->comp,r->year);pre(r->l);pre(r->r);}
void post(struct Node* r){if(!r)return;post(r->l);post(r->r);printf("%s %s %d\n",r->type,r->comp,r->year);}

int main(){
    struct Node* root=NULL;
    root=insert(root,"SUV","Tata",2020);
    root=insert(root,"Sedan","Honda",2018);
    root=insert(root,"Truck","Ashok",2022);
    printf("Inorder:\n"); in(root);
    printf("Preorder:\n"); pre(root);
    printf("Postorder:\n"); post(root);
    root=del(root,2018);
    printf("After Deletion:\n"); in(root);
}
