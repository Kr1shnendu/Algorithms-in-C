#include<stdio.h>
int n=4,i,j,x,y,l=0,m=0,dmin,d,p;

int cal(int temp[10][10],int t[10][10]){
	m=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(temp[i][j]!=t[i][j]){
				m++;
			}
		}
	}
	return m;
}

int check(int a[10][10],int t[10][10]){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!=t[i][j]){
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int a[10][10],t[10][10],temp[10][10],r[10][10];
	printf("Enter the matrix to be solved,space with 0: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nEnter the target matrix,space with 0: ");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&t[i][j]);
		}
	}
	printf("\nEntered matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nTarget matrix is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",t[i][j]);
		}
		printf("\n");
	}
	//logic
	while(!check(a,t)){
		l++;
		d=999;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(a[i][j]==0){
					x=i;
					y=j;
				}
			}
		}
		//to move upwards
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp[i][j]=a[i][j];
			}
		}
		if(x!=0){
			p=temp[x][y];
			temp[x][y]=temp[x-1][y];
			temp[x-1][y]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin<d){
			d=dmin;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					r[i][j]=temp[i][j];
		}
		
		//downwards
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp[i][j]=a[i][j];
			}
		}
		if(x!=n-1){
			p=temp[x][y];
			temp[x][y]=temp[x+1][y];
			temp[x+1][y]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin<d){
			d=dmin;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					r[i][j]=temp[i][j];
		}
		
		//right side
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp[i][j]=a[i][j];
			}
		}
		if(y!=n-1){
			p=temp[x][y];
			temp[x][y]=temp[x][y+1];
			temp[x][y+1]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin<d){
			d=dmin;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					r[i][j]=temp[i][j];
		}
		
		//left
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				temp[i][j]=a[i][j];
			}
		}
		if(y!=0){
			p=temp[x][y];
			temp[x][y]=temp[x][y-1];
			temp[x][y-1]=p;
		}
		m=cal(temp,t);
		dmin=l+m;
		if(dmin<d){
			d=dmin;
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					r[i][j]=temp[i][j];
		}
		
		printf("\nCalculated intermediate matrix: \n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%d\t",r[i][j]);
			}
			printf("\n");
		}
		//move one
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				a[i][j]=r[i][j];
				temp[i][j]=0;
			}
		}
		printf("Minimum cost is : %d \n",m);
	}
	return 0;
}
