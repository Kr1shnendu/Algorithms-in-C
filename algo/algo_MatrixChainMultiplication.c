#include<stdio.h>
#define MAX 100
int m[MAX][MAX],p[MAX+1],n;
int mm(){
	int i,j,k,d,q;
	for(i=1;i<=n;i++){
		m[i][i]=0;
	}
	for(d=1;d<n;d++){
		for(i=1;i<=n-d;i++){
			j=i+d;
			m[i][j]=9999;
			for(k=i;k<j;k++){
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
				}
			}
		}
	}
	return m[1][n];
}
int main(){
	int i,mult;
	printf("Enter no. of matrix: ");
	scanf("%d",&n);
	printf("Enter the dimentions: ");
	for(i=0;i<=n;i++){
		scanf("%d",&p[i]);
	}
	mult=mm();
	printf("Min cost: %d",mult);
	return 0;
}
