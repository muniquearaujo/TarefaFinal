#include<stdio.h>
#define N 200

main()
{
	double M[N][N]={0},MASC[N][N]={0}, soma=0;
	int i,j,t;
	
	for(i=0;i<N;i++)
	{
		M[N-1][i]=100.;
		MASC[N-1][i]=1.;
		M[i][0]=M[i][N];
		M[i][N+1]=M[i][1];
		
	}

	for(i=0;i<N/2;i++)
	{
		MASC[i][N/2]=1;
		
	}
	//Para fazer o T
	for(i=50;i<150;i++)
	{
		MASC[N/2][i]=1;
	}
	
	printf("\n");
	
	for(t=0;t<200000;t++) 
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(MASC[i][j]==0)
				{			
					soma=(M[i+1][j]+M[i-1][j]+M[i][j+1]+M[i][j-1])/4;
					M[i][j]=soma;
				}
			}
		}					
	}	
	for (i=0;i<N;i++) 
	{
	  for(j=0;j<N;j++) 
	  {
	    printf("%.2lf ",M[i][j]);
	  }
	  puts("");
	}	
}	
	
					
	//o mascara vai ate n-1 mas tem que conter o valor da nuvem Y[0]até n-1 encher de 0 1.. se a mascara 0 altera se não pula 
	//guardo quanto variou e guardo ela
