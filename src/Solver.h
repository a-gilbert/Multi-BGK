#ifndef _SOLVER_H
#define _SOLVER_H

//distributing grid points so that all associated with one space point are on
//a single rank, or all points evenly distributed.
enum RHSType{EXPLICIT, IMPLICIT};
enum Style{KINETIC, HYDRO};

struct SolverInfo {
    enum RHSType rhst;
    enum Style runstyle; //hydro flag;
    int order;
    double rhs_tol;
    double rhs_min;
};

void init_solver_info(struct SolverInfo *sinfo);

void set_rhs_type(struct SolverInfo *sinfo, char *line);

void set_runstyle(struct SolverInfo *sinfo, char *line);

void set_order(struct SolverInfo *sinfo, char *line);

void set_collision_tol(struct SolverInfo *sinfo, char *line);

void set_collision_min(struct SolverInfo *sinfo, char *line);

#endif //_SOLVER_H