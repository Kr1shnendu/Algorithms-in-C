#include<stdio.h>
int cost[10][10],dist[10],i,j,n,v,min,count=1;
int visited[10];
void dijkstras(int s){
	for(i=1;i<=n;i++){
		visited[i]=0;
		dist[i]=cost[s][i];
	}
	visited[s]=1;
	dist[s]=0;
	while(count<=n){
		min=999;
		for(i=1;i<=n;i++){
			if(dist[i]<min && visited[i]==0){
				min=dist[i];
				v=i;
			}
		}
		visited[v]=1;
		count++;
		for(i=1;i<=n;i++){
			if(dist[i] > dist[v]+cost[v][i]){
				dist[i] = dist[v]+cost[v][i];
			}
		}
	}
}
int main(){
	int s;
	printf("Enter the no. of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the adjucency matrix: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0){
				cost[i][j]=999;
			}
		}
	}
	printf("\nEnter the source vertex: ");
	scanf("%d",&s);
	dijkstras(s);
	
	for(i=1;i<=n;i++){
		if(s!=i){
			printf("\n%d->%d: %d",s,i,dist[i]);
		}
	}
	
	return 0;
}
