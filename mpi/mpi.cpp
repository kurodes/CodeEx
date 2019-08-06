/**
 *   mpic++ mpi.cpp
 *   mpirun -np 2 ./a.out
 */
#include <mpi.h>
#include <stdio.h>

int numprocs;
int rank;

void PreParallelWork() {
    printf("pre-pre\n");
    return;
}

void PostParallelWork() {
    printf("pos-pos\n");
    return;
}

void ParallelWork() {
    printf("para-para\n");
    return;
}

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if (rank == 0) { // Do the serial part on a single MPI thread
        printf("Performing serial computation on cpu %d\n", rank);
        PreParallelWork();
    }

    ParallelWork();  // Every MPI thread will run the parallel work

    if (rank == 0) { // Do the final serial part on a single MPI thread
        printf("Performing the final serial computation on cpu %d\n", rank);
        PostParallelWork();
    }

    MPI_Finalize();
    return 0;
}
