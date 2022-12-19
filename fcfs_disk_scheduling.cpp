#include<stdio.h>
#include<math.h>
int main(){
	int n,initial,ans=0;
	printf("ENTER THE NUMBER OF DISK PLATTERS	:  	");
	scanf("%d",&n);
	int RQ[n];
	printf("ENTER THE NUMBER OF REQUESTS : ");
	for(int i=0;i<n;i++){
		scanf("%d",&RQ[i]);
	}
	printf("ENTER THE INTIALS : ");
	scanf("%d",&initial);
	ans=ans+abs(initial-RQ[0]);	
	for(int i=1;i<n;i++){
		ans=ans + abs (RQ[i]-RQ[i-1]);
		initial=RQ[i];
	}
	printf("TOTAL HEAD COUNT IS %d",ans);
	return 0;
}