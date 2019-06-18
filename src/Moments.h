#ifndef _MOMENTS_H
#define _MOMENTS_H


struct MomentInfo {
    double **rho;
    double ***ubulk;
    double **T;
    double **n;
};

struct AvgAtomMomentInfo {
    double **rho;
    double ***ubulk;
    double **T;
    double **n;
    double **Zbar;
};

#endif //_MOMENTS_H