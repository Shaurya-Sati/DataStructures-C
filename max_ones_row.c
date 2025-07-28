#include <stdio.h>
int main() {
    int m,n;
    printf("Enter order of matrix: ");
    scanf("%d%d",&m,&n);
    int mat[m][n];
    printf("Enter the elements of the matrix (only 1 and 0): ");
    for (int i=0;i<m;i++)  {
        for (int j=0;j<n;j++) {
            scanf("%d" , &mat[i][j]);
        }
    }
    int temp=-1,i=0,j=n-1;
    while (i<m && j>=0) {
        if (mat[i][j]==1) {
            temp=i;
            j--;
        } else {
            i++;
        }
    }
    if (temp==-1) {
        printf("Not Present");
    } else {
        printf("Row- %d",temp+1);
    }
    return 0;
}