#include<stdio.h>
int main(){
	int n,k;
	int max;
	printf("enter the size:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements:");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	printf("the largest element is:%d ",max);
	return 0;
}
