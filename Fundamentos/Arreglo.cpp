#include <stdio.h>
int main(){
	
	float S[100], acum;
	int i=0,n=0;
	 printf("Cuantos datos va ingresar? ");
	 scanf("%d",&n);
	 printf("Con for\n");
	 for(i=0;i<n;i++){
	 	printf("S[%d]= ", (i+1));
	 	scanf("%f",& S[i]);
	 	acum=acum+S[i];
	 }
	 for(i=0;i<n;i++){
	 	printf("%.2f ",S[i]);
	 	if(i<n-1)
	 		printf(" + ");
	}
	printf("= %.2f\n", acum);
	printf("Con while\n");
	i=0;
	acum=0;
	while(i<n){
		printf("S[%d]= ", (i+1));
	 	scanf("%f",& S[i]);
	 	acum=acum+S[i];
	 	i++;
	}
	i=0;
	while(i<n){
		printf("%.2f ",S[i]);
		if(i<n-1)
	 		printf(" + ");
		i++;
	}
	printf("= %.2f\n", acum);
	printf("Con do-while\n");
	i=0;
	acum=0;
	do{
		printf("S[%d]= ", (i+1));
	 	scanf("%f",& S[i]);
	 	acum=acum+S[i];
	 	i++;	
	}while(i<n);
	i=0;
	do{
		printf("%.2f ",S[i]);
		if(i<n-1)
	 		printf(" + ");
		i++;
	}while(i<n);
	printf("= %.2f\n", acum);
	return 0;
}
