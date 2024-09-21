#include<stdio.h>
struct sack{
	double weight;
	double cost;
	double ratio;
};
void sort(struct sack s[],int n){
	struct sack temp;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(s[i].ratio<s[j].ratio){
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
}
void knapsack(struct sack s[],int n,int cap){
	double x[10],u=cap,tp=0.0;
	int i;
	for(i=0;i<n;i++){
		x[i]=0.0;
	}
	for(i=0;i<n;i++){
		if(s[i].weight>u){
			break;
		}else{
			x[i]=1.0;
			tp+=s[i].cost;
			u-=s[i].weight;
		}
		printf("\nIntermediate price: %lf",tp);
		printf("\nRemaining capacity: %lf",u);
	}
	if(i<n){
		x[i]=u/s[i].weight;
		tp+=x[i]*s[i].cost;
	}
	printf("\nTotal price: %lf",tp);
}
int main(){
	struct sack s[10];
	int n,c,i;
	printf("Enter no of objects: ");
	scanf("%d",&n);
	printf("Enter knapsack capacity: ");
	scanf("%d",&c);
	for(i=0;i<n;i++){
		printf("Enter weight for %d: ",i+1);
		scanf("%lf",&s[i].weight);
		printf("Enter cost for %d: ",i+1);
		scanf("%lf",&s[i].cost);
		s[i].ratio=s[i].cost/s[i].weight;
	}
	sort(s,n);
	knapsack(s,n,c);
	return 0;
}
