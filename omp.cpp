#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
   
#include <iostream>
using namespace std;

const int P=10;//число рабочих процессов (не используется в MPI)
const int N=10;
double a[N][N],b[N][N],c[N][N];

int main (int argc, char *argv[])
{
	// инициализация
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)a[i][j]=2;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)b[i][j]=3;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)c[i][j]=0.0;

	// перемножение матриц
#pragma omp parallel shared(a,b,c)
	{
		#pragma omp for
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				for(int k=0;k<N;k++)c[i][j]+=a[i][k]*b[k][j];
			}
	}
	// вывод результата параллельного умножения
	cout<<"\nC(parallel)=\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<'\n';
	}
	return EXIT_SUCCESS;
}


