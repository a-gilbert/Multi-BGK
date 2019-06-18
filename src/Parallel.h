#ifndef _PARALLEL_H
#define _PARALLEL_H

enum ParallelScheme {SPATIAL, ALL};

struct ParallelInfo {
    enum ParallelScheme pscheme;
    int rank;
    int tot_ranks;
    int **neighbor_ranks;
    int *loc_npoints;
    int *glob_nlims;
};

void init_parallel_info(struct ParallelInfo *pinfo);

void set_parallelism(struct ParallelInfo *pinfo, char *line);




#endif //_PARALLEL_H