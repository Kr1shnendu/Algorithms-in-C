#include<stdio.h>
void merge(int a[],int left,int mid,int right){
	int temp[right-left+1];
	int low=left,high=mid+1,k=0,i;
	while(low<=mid && high<=right){
		if(a[low]<a[high]){
			temp[k++]=a[low++];
		}else{
			temp[k++]=a[high++];
		}
	}
	while(low<=mid){
		temp[k++]=a[low++];
	}
	while(high<=right){
		temp[k++]=a[high++];
	}
	for(i=left;i<=right;i++){
		a[i]=temp[i-left];
	}
}
void mergeSort(int a[],int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
int main(){
	int i;
	int arr[]={5,8,56,1,7,77,5,4,12,9,2,6};
	int size=sizeof(arr)/sizeof(int);
	mergeSort(arr,0,size-1);
	for(i=0;i<size;i++){
		printf("%d  ",arr[i]);
	}
	return 0;
}
