#include <stdio.h>
int main() {
	int n,i,k;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter elements of array: ");
	for (i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter number of rotations: ");
	scanf("%d", &k);
	k=k%n;
	if (k==0) {
		printf("Array after rotation:\n");
		for (i=0; i<n; i++) {
			printf("%d ", arr[i]);
		}
		return 0;
	}
	int temp[k];
	for (i=0; i<k; i++) {
		temp[i]=arr[n-k+i];
	}
	for (i=n-1; i>=k; i--) {
		arr[i]=arr[i-k];
	}
	for (i=0; i<k; i++) {
		arr[i]=temp[i];
	}
	printf("Array after rotation:\n");
	for (i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}