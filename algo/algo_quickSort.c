#include<stdio.h>
int partition(int a[],int low,int high){
	int pivot = a[low];
	int i=low,j=high,temp;
	while(i<j){
		while(a[i]<=pivot && i<=high-1) i++;
		while(a[j]>pivot && j>=low+1) j--;
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[j];
	a[j]=a[low];
	a[low]=temp;
	return j;
}
void quickSort(int a[],int low,int high){
	int pi;
	if(low<high){
		pi=partition(a,low,high);
		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}
int main(){
	int i;
	int arr[]={5,8,56,1,7,77,5,4,12,9,2,6};
	int size=sizeof(arr)/sizeof(int);
	quickSort(arr,0,size-1);
	for(i=0;i<size;i++){
		printf("%d  ",arr[i]);
	}
	return 0;
}
