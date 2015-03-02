#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
   
const int P=10;//число рабочих процессов (не используется в MPI)
const int N=10;
double a[N][N],b[N][N],c[N][N];

int main (int argc, char *argv[])
{
	int th_id, nthreads;
	/*
	// инициализация
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)a[i][j]=N*i+j;

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)b[i][j]=N*i+j;
	*/
	#pragma omp parallel private(th_id)
	{
		th_id = omp_get_thread_num();
		printf("Hello World from thread %d\n", th_id);
		
		#pragma omp barrier

		if(th_id == 0){
			nthreads = omp_get_num_threads();
			printf("There are %d threads\n",nthreads);
		}
	}
	return EXIT_SUCCESS;
}


