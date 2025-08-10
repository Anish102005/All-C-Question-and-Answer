#include<stdio.h>
#include<stdlib.h>
int main(){
	int m,k;
	printf("enter the number of elements:");
	scanf("%d",&m);
	int*arr=(int*)malloc(m*sizeof(int));
	printf("enter the elements:");
	for(int i=0;i<m;i++){
		scanf("%d",&arr[i]);
	}
	printf("elements to be added:");
	scanf("%d",&k);
	arr[m]=k;
	for(int i=0;i<m+1;i++){
		printf("%d ",arr[i]);
	}
	free(arr);
	return 0;
}
