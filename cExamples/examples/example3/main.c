#include <stdio.h>

/*Binary search */


int binarySearch(int x, int arr[], int n);

int main(){
    int arr[] = {3, 8 , 10, 15, 22, 45, 99, 128, 150, 199};
    printf("\n%d\n", binarySearch(45, arr, 10));
    return 0;
}

int binarySearch(int x, int arr[], int n){
    int low, high, mid;
    low =0;
    high = n-1;
    while(low <= high){
    mid = (low + high ) /2;
        if(x < arr[mid]) high = mid -1;
        else if( x> arr[mid]) low = mid +1;
        else return mid;
    }
    return -1;

}