#ifndef _PARALLEL_H
#define _PARALLEL_H

struct ParallelInfo {
    int rank;
    int tot_ranks;
    int **neighbor_ranks;
    int *loc_npoints;
    int *glob_nlims;

}


#endif //_PARALLEL_H