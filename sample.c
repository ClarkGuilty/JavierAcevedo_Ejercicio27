#include <stdio.h>
#include "mpi.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592653589793
int main (int argc, char *argv[]){
int rank, size, i;
double u1, u2, actual;
if( argc != 4 ) {
    printf("La entrada debe ser de la forma %s N mu sigma\n", argv[0]);
    exit(0);
}
char *filename= (char*) malloc(200* sizeof(char));
//srand(time(NULL));   
//struct timeval time; 
//gettimeofday(&time,NULL);
//srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
int N = atoi(argv[1]);
int mu = atoi(argv[2]);
int sigma = atoi(argv[3]);
printf("N=%d\n",N);
/* starts MPI */
MPI_Init (&argc, &argv);
/* get current process rank */
MPI_Comm_rank (MPI_COMM_WORLD, &rank);
MPI_Comm_size (MPI_COMM_WORLD, &size);
srand(rank);
sprintf(filename, "sample_%d.dat", rank+1);
FILE *output = fopen(filename, "w+");
fprintf(output,"%d",size);
for(i=rank*N/size;i<(rank+1)*N/size;i++){
    u1 = rand()/(RAND_MAX*1.0);
    u2 = rand()/(RAND_MAX*1.0);
    actual = sqrt(-2*log(u1))*sin(2*PI*u2);
    fprintf(output, "%f\n",actual*sigma+mu); 
}
fclose(output);
MPI_Finalize(); /* ends MPI */
return 0;
}
