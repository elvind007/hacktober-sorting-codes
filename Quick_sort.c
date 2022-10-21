#include<stdio.h>
int partition(int *arr,int s,int e){
    int i,c=0,pivotindex;
    int pivot=arr[s];
    for(i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            c++;
        }
    }
    pivotindex=s+c;

    int temp;
    temp=arr[pivotindex];
    arr[pivotindex]=arr[s];
    arr[s]=temp;


    int j=s,k=e;
    while(j<pivotindex && k>pivotindex){
        while(arr[j]<=pivot){
            j++;
        }
        while(arr[k]>pivot){
            k--;
        }
        if(s<pivotindex&&k>pivotindex){
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
            j++;
            k--;
        }
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p;
    p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

/*void swap(int arr[],int pivotindex,int s){
    int temp;
    temp=arr[pivotindex];
    arr[pivotindex]=arr[s];
    arr[s]=temp;
}*/
int main(){
    int n,arr[10],i;
    printf("How many numbers wants in array:");
    scanf("%d",&n);
    printf("Enter %d numbers of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted array:");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}