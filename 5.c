#include <stdio.h>

// Insertion Sort
void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i], j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

// Bubble Sort
void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]){
                int t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
}

// Selection Sort
void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[min]) min=j;
        int t=a[i]; a[i]=a[min]; a[min]=t;
    }
}

// Merge Sort Helpers
void merge(int a[], int l, int m, int r){
    int n1=m-l+1, n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}
void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

// Display Array
void printArr(int a[], int n){
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int arr1[]={5,3,8,4,2}, n=5;
    int arr2[]={5,3,8,4,2};
    int arr3[]={5,3,8,4,2};
    int arr4[]={5,3,8,4,2};

    printf("Original: "); printArr(arr1,n);

    insertionSort(arr1,n);
    printf("Insertion Sort: "); printArr(arr1,n);

    mergeSort(arr2,0,n-1);
    printf("Merge Sort: "); printArr(arr2,n);

    bubbleSort(arr3,n);
    printf("Bubble Sort: "); printArr(arr3,n);

    selectionSort(arr4,n);
    printf("Selection Sort: "); printArr(arr4,n);

    return 0;
}