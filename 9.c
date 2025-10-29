#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char type[20], comp[20];
    int year;
    struct Node *l, *r;
};

struct Node* newN(char t[], char c[], int y) {
    struct Node* n = malloc(sizeof(struct Node));
    strcpy(n->type, t); strcpy(n->comp, c);
    n->year = y; n->l = n->r = NULL;
    return n;
}

struct Node* ins(struct Node* r, char t[], char c[], int y) {
    if(!r) return newN(t,c,y);
    if(y < r->year) r->l = ins(r->l,t,c,y);
    else if(y > r->year) r->r = ins(r->r,t,c,y);
    return r;
}

struct Node* min(struct Node* r){while(r->l)r=r->l;return r;}

struct Node* del(struct Node* r,int y){
    if(!r) return NULL;
    if(y<r->year) r->l=del(r->l,y);
    else if(y>r->year) r->r=del(r->r,y);
    else{
        if(!r->l){struct Node* t=r->r; free(r); return t;}
        if(!r->r){struct Node* t=r->l; free(r); return t;}
        struct Node* t=min(r->r);
        strcpy(r->type,t->type); strcpy(r->comp,t->comp); r->year=t->year;
        r->r=del(r->r,t->year);
    }
    return r;
}

void in(struct Node* r){if(!r)return;in(r->l);printf("%d %s %s\n",r->year,r->type,r->comp);in(r->r);}
void pre(struct Node* r){if(!r)return;printf("%d %s %s\n",r->year,r->type,r->comp);pre(r->l);pre(r->r);}
void post(struct Node* r){if(!r)return;post(r->l);post(r->r);printf("%d %s %s\n",r->year,r->type,r->comp);}

int main(){
    struct Node* r=NULL;
    r=ins(r,"Car","Toyota",2018);
    r=ins(r,"Bike","Yamaha",2015);
    r=ins(r,"Car","Tesla",2021);
    r=ins(r,"SUV","Mahindra",2019);
    r=ins(r,"Truck","Tata",2017);

    printf("Inorder:\n"); in(r);
    printf("Preorder:\n"); pre(r);
    printf("Postorder:\n"); post(r);

    r=del(r,2017);
    printf("After deletion:\n"); in(r);
}
