#include <stdio.h>
int main() {
    int n;
    printf("Enter size of matrix: ");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter elements of matrix:\n ");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%d" , &arr[i][j]);
        }
    }
    int target,flag=0;
    printf("Enter the element to search: ");
    scanf("%d",&target);
    int i=0,j=n-1;
    while (i<n && j>=0) {
        if (arr[i][j]==target) {
            flag=1;
            break;
        } else if (arr[i][j]<target) {
            i++;
        } else {
            j--;
        }
    }
    if (flag==1) {
        printf("Present");
    } else {
        printf("Not Present");
    }
    return 0;
}