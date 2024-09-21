#include<stdio.h>
int cost[10][10],i,j,a,b,u,v,n,now=1,min,mincost,parent[10]={0};
int find(int i){
	while(parent[i]){
		i=parent[i];
	}
	return i;
}
int uni(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
	}
	return 0;
}
void kruskal(){
	while(now<n){
		min=999;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(cost[i][j]<min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		v=find(v);
		u=find(u);
		if(uni(u,v)){
			printf("\nEdge %d: (%d,%d) => cost: %d",now,a,b,min);
			mincost+=min;
			cost[a][b]=cost[b][a]=999;
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
	kruskal();
	return 0;
}
