#include<stdio.h>
int x[20];
void nextColor(int a,int g[][20]){
	int i;
	x[a]=1;
	for(i=0;i<a;i++){
		if(g[i][a]!=0&&x[i]==x[a]){
			x[a]=x[i]+1;
		}
	}
}
int main(){
	int g[20][20],i,j,n;
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("Enter adj. matrix: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	for(i=0;i<n;i++){
		nextColor(i,g);
	}
	for(i=0;i<n;i++){
		printf("\nNode %d -> color %d",i+1,x[i]);
	}
	return 0;
}
