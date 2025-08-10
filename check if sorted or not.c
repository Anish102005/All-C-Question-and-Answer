#include<stdio.h>
int main(){
	int n,k;
	printf("enter the no of elements :");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements :");
	for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
    }
    int sorted = 1;
    for(int i=0;i<n-1;i++){
    	if(arr[i]>arr[i+1]){
    		sorted=0;
    		break;
		}
	}
	if(sorted==1){
		printf("sorted");
	}
	else{
		printf("not sorted");
	}
	return 0;
}
