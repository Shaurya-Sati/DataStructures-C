#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int x,int y) {
    if (x>y)
        return y;
    return x;
}

int mini_dist(int arr[],int n,int a,int b) {
    int min1=INT_MAX;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]==a && arr[j]==b || arr[i]==b && arr[j]==a) {
                min1 = min(min1, abs(i - j));
            }
        }
    }
    if (min1==INT_MAX)
        return -1;
    return min1;
}

int main() {
    int n,i,j,a,b,T;
    printf("Enter number of test cases: ");
    scanf("%d" , &T);
    while (T--) {
        printf("Enter size of array: ");
        scanf("%d" , &n);
        int arr[n];
        printf("Enter elements of the array: ");
        for (i=0;i<n;i++) {
            scanf("%d" , &arr[i]);
        }
        printf("Enter two elements a and b: ");
        scanf("%d %d",&a,&b);
        int dist=mini_dist(arr,n,a,b);
        if (dist!=-1) {
            printf("Minimum distance between %d and %d is %d\n",a,b,dist);
        } else {
            printf("Either %d or %d is not present",a,b);
        }
    }
}