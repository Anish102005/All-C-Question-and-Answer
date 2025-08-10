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
    for(int i=0;i<n-1;i++){
    	for(int j=i+1;j<n;j++){
    		if(arr[i]<arr[j]){
    			k=arr[i];
    			arr[i]=arr[j];
    			arr[j]=k;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[0]){
			printf("second largest element is:%d ",arr[i]);
			break;
		}
	}
	return 0;
}
