#include<stdio.h>
int cost[10][10],i,j,u,v,n,now=1,visited[10]={0},min,mincost;
void prim(){
	visited[1]=1;
	while(now<n){
		min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					u=i;
					v=j;
				}
			}
		}
		if(visited[u]==0 || visited[v]==0){
			visited[v]==1;
			printf("\nEdge %d: (%d,%d) => cost: %d",now,u,v,min);
			mincost+=min;
			cost[u][v]=cost[v][u]=999;
		}
		now++;
	}
	printf("\nMinimum cost: %d",mincost);
}
int main(){
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	printf("Enter val: ");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=999;
			}
		}
	}
	prim();
	return 0;
}
