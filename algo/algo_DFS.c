#include<stdio.h>
int g[20][20],visited[20],source=1,n;
void dfs(int i){
	int j;
	visited[i]=1;
	printf("%d -> ",i);
	for(j=1;j<=n;j++){
		if(!visited[j] && g[i][j]!=0){
			dfs(j);
		}
	}
}
int main(){
	int i,j;
	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the adjucency matrix: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	dfs(source);
	return 0;
}
