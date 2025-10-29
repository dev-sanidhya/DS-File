#include <stdio.h>

int main() {
    int arr[] = {3,7,1,9,5}, n=5, x=9, i, mid, l, r;
    
    // Linear Search
    printf("--- Linear Search ---\nArray: ");
    for(i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\nTarget: %d\n",x);
    for(i=0;i<n;i++){
        printf("Checking index %d -> %d\n",i,arr[i]);
        if(arr[i]==x){ 
            printf("Found %d at index %d\n\n",x,i);
            break;
        }
    }
    if(i==n) printf("Element not found\n\n");

    // Binary Search (sort array first: 1 3 5 7 9)
    int sorted[]={1,3,5,7,9}; 
    l=0; r=n-1;
    printf("--- Binary Search ---\nSorted Array: ");
    for(i=0;i<n;i++) printf("%d ",sorted[i]);
    printf("\nTarget: %d\n",x);

    while(l<=r){
        mid=(l+r)/2;
        printf("Mid=%d -> %d\n",mid,sorted[mid]);
        if(sorted[mid]==x){
            printf("Found %d at index %d\n",x,mid);
            return 0;
        }
        else if(sorted[mid]<x) { 
            printf("%d < %d -> move right\n",sorted[mid],x);
            l=mid+1;
        }
        else { 
            printf("%d > %d -> move left\n",sorted[mid],x);
            r=mid-1;
        }
    }
    printf("Element not found\n");
    return 0;
}