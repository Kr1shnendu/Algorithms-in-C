#include<stdio.h>
#include<math.h>
int x[20],c;
int place(int row,int col){
	int i;
	for(i=1;i<=row-1;i++){
		if((x[i]==col)||(abs(x[i]-col)==abs(i-row))){
			return 0;
		}
	}
	return 1;
}
void print(int n){
	int i,j;
	printf("\n\nSoluntion %d:",c++);
	for(i=1;i<=n;i++){
		printf("\n%d. ",i);
		for(j=1;j<=n;j++){
			if(x[i]==j){
				printf("* ");
			}else{
				printf("- ");
			}
		}
	}
}
void nQueen(int row,int n){
	int col;
	for(col=1;col<=n;col++){
		if(place(row,col)){
			x[row]=col;
			if(row==n){
				print(n);
			}else{
				nQueen(row+1,n);
			}
		}
	}
}
int main(){
	int n;
	printf("Enter no. of Queen: ");
	scanf("%d",&n);
	nQueen(1,n);
	return 0;
}
