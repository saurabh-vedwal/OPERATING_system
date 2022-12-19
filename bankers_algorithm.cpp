#include<stdio.h>
int main(){
	int n,m;
	printf("ENTER THE NUMBER OF PROCESSES	:");
	scanf("%d",&n);	
	printf("ENTER THE NUMBER OF RESOURCES	:");
	scanf("%d",&m);
	int allocation[n][m];
	printf("ENTER THE ALLOCATION MATRIX\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&allocation[i][j]);
		}
	}
	int process[n][m];
	printf("ENTER THE PROCESS MATRIX \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&process[i][j]);
		}
	}
	int available[m];
	printf("ENTER THE AVAILABLE MATRIX\n");
	for(int i=0;i<m;i++){
		scanf("%d",&available[i]);
	}
	int fun[n],answer[n];
	int index=0;
	for(int i=0;i<n;i++){
		fun[i]=0;
	}
	int need[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j]=process[i][j]-allocation[i][j];
		}
	}
	printf("NEED MATRIX IS \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("  %d  ",need[i][j]);
		}
		printf("\n");
	}
	int y=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(fun[i]==0){
				int flag=0;
				for(int j=0;j<m;j++){
					if(need[i][j]>available[j]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					answer[index++]=i;
					for(y=0;y<m;y++){
						available[y]+=allocation[i][y];
					}
					fun[i]=1;
				}
			}
		}
	}
	int flag=1;
	for(int i=0;i<n;i++){
		if(fun[i]==0){
			flag=0;
			printf("THIS PROCESS WILL NOT COMPLETE ");
		}
	}
	if(flag==1){
		printf("PROCESS THAT WILL COMPLETE	:");
		for(int i=0;i<n-1;i++){
			printf("  P-%d   ",answer[i]);
		}
		printf("   P-%d  ",answer[n-1]);
	}
	return 0;
}