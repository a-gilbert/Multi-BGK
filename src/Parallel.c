#include<string.h>
#include "Parallel.h"

void init_parallel_info(struct ParallelInfo *pinfo){
    pinfo->pscheme = SPATIAL;
}

void set_parallelism(struct ParallelInfo *pinfo, char *line){
    if(strcmp(line, "parallelism = spatial") == 0){
        pinfo->pscheme=SPATIAL;
    }else if(strcmp(line, "parallelism = all") == 0){
        pinfo->pscheme=ALL;
    }
}