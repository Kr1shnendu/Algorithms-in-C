#include<stdio.h>
int max,min;
void maxmin(int a[],int i,int j){
	int max1,min1,mid;
	if(i==j){
		max=min=a[i];
	}
	else if(i==j-1){
		if(a[i]>a[j]){
			max=a[i];
			min=a[j];
		}else{
			min=a[i];
			max=a[j];
		}
	}
	else{
		int mid=(i+j)/2;
		maxmin(a,i,mid);
		max1=max;
		min1=min;
		maxmin(a,mid+1,j);
		if(max1>max){
			max=max1;
		}
		if(min1<min){
			min=min1;
		}
	}
}
int main(){
	int arr[]={5,8,56,1,7,77,5,4,12,9,2,-3,6};
	int size=sizeof(arr)/sizeof(int);
	max=min=arr[0];
	maxmin(arr,0,size-1);
	printf("Max:%d  Min:%d",max,min);
	return 0;
}
