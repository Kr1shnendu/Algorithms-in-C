#include<stdio.h>
int n,i,j,adj[10][10],ar[10],p,count=0;
int front=0,rear=0,que[100];
void insert(int val){
	que[front++]=val;
}
int del(){
	rear++;
	return que[rear-1];
}
int unvisit(int j){
	for(i=0;i<front;i++){
		if(que[i]==j){
			return 0;
		}
	}
	return 1;
}
void bfs(int i){
	int m;
	if(front==0){
		insert(i);
	}
	for(j=1;j<=n;j++){
		if(adj[i][j]==1 && unvisit(j)){
			insert(j);
		}
	}
	m=del();
	ar[p++]=m;
	count++;
	if(count<=n){
		bfs(m);
	}
}
void display(){
	for(i=0;i<n;i++){
		printf("%d  ",ar[i]);
	}
}
int main(){
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	printf("Enter val: ");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&adj[i][j]);
		}
	}
	bfs(1);
	display();
	return 0;
}
