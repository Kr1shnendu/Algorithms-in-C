#include<stdio.h>
int x[20],n,g[20][20],i,j,start=1;
void nextValue(int k){
	do{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0) return;
		if(g[x[k-1]][x[k]]!=0){
			for(j=1;j<k;j++){
				if(x[j]==x[k]) break;
			}
			if(j==k){
				if(k<n || (k==n)&&g[x[n]][x[1]]!=0) return;
			}
		}
	}while(1);
}
void hamiltonian(int k){
	x[1]=start;
	do{
		nextValue(k);
		if(x[k]==0){
			return;
		}else if(k==n){
			printf("\nHamiltonian cycle: ");
			for(i=1;i<=n;i++){
				printf("%d -> ",x[i]);
			}
			printf("%d",start);
		}else{
			hamiltonian(k+1);
		}
	}while(1);
}
int main(){
	printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("Enter adj. matrix: ");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	hamiltonian(2);
	return 0;
}
