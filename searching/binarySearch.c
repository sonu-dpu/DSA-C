#include <stdio.h>
int binarySearch(int arr[], int n, int key){
    int left = 0;
    int right = n-1;
    while(left<=right){// left should not cross right 
        int mid = (left + right)/2;
        if(arr[mid]==key){
            return mid;
        }
        // ignore left porting
        if(arr[mid]<key){
            left =  mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}
int binary2(int arr[], int left,int right, int key){
    if (left>right){
        return -1;
    }
    int mid = (left + right)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        return binary2(arr, mid+1, right, key);
    } else{
        return binary2(arr, left, mid-1, key);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found\n", key);
    }
    return 0;
}