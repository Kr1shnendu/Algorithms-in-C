#include<stdio.h>
void warshall(int s[][20],int n){
	int i,j,k,t;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j && s[i][j]==0){
				s[i][j]=9999;
			}
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				t=s[i][k]+s[k][j];
				if(s[i][j]>t){
					s[i][j]=t;
				}
			}
		}
	}
}
int main(){
	int i,j,n,s[20][20];
	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter the dimentions: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&s[i][j]);
		}
	}
	warshall(s,n);
	printf("Shortest path:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
