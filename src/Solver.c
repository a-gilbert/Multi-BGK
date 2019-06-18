#include<string.h>
#include<stdio.h>
#include "Solver.h"

void init_solver_info(struct SolverInfo *sinfo){
    sinfo->rhst = EXPLICIT;
    sinfo->runstyle = KINETIC;
    sinfo->order = 1;
    sinfo->rhs_tol = 0.5;
    sinfo->rhs_min = 1.0e37;
}

void set_rhs_type(struct SolverInfo *sinfo, char *line){
    if(strcmp(line, "RHS_Type = Explicit") == 0){
        sinfo->rhst = EXPLICIT;
    }else if(strcmp(line, "RHS_Type = Implicit") == 0){
        sinfo->rhst = IMPLICIT;
    }
}

void set_runstyle(struct SolverInfo *sinfo, char *line){
    if(strcmp(line, "Run_Style = Kinetic") == 0){
        sinfo->runstyle = KINETIC;
    }else if(strcmp(line, "Run_Style = Hydro") == 0){
        sinfo->runstyle = HYDRO;
    }
}

void set_order(struct SolverInfo *sinfo, char *line){
    sscanf(line, "Order = %d", &sinfo->order);
}

void set_collision_tol(struct SolverInfo *sinfo, char *line){
    sscanf(line, "RHS_Tol = %g", &sinfo->rhs_tol);
}

void set_collision_min(struct SolverInfo *sinfo, char *line){
    sscanf(line, "RHS_Min = %g", &sinfo->rhs_min);
}
