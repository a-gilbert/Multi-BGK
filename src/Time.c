#include<stdio.h>
#include "Time.h"

void init_time_info(struct TimeInfo* tinfo){
    tinfo->dt = 1e-16;
    tinfo->t = 0;
    tinfo->tfinal = 1e-12;
    tinfo->nT = 0;
}

void set_timestep(struct TimeInfo* tinfo, char *line){
    sscanf(line, "dt = %g", &tinfo->dt);
}

void set_time(struct TimeInfo *tinfo, double atime){
    tinfo->t = atime;
}

void set_tfinal(struct TimeInfo *tinfo, char *line){
    sscanf(line, "Final_Time = %g", &tinfo->tfinal);
}

void update_time(struct TimeInfo* tinfo){
    tinfo->t += tinfo->dt;
}

void update_timestep(struct TimeInfo* tinfo){
    tinfo->nT += 1;
}
