#ifndef _SOLVER_H
#define _SOLVER_H

//distributing grid points so that all associated with one space point are on
//a single rank, or all points evenly distributed.
enum ParallelScheme{SPACE, ALL};
enum SolutionType{EXPLICIT, IMPLICIT};

struct SolverInfo {
    enum ParallelScheme pscheme;
    int order;


}

#endif //_SOLVER_H