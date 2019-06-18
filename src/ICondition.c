#ifndef _ICONDITION_H
#define _ICONDITION_H

enum ICInputs{MOMENTS, DFUNC}; //inputs based on moments, or based on distribution function values? 
enum ICStyle{RESTART, REGION};

struct RestartIC {
    char *input_file;
    enum ICStyle inputs;
};

struct RegionIC {
    int nregions;
    double **rlims; //rlims[region] = {dim0lo, ...,dimNlo, dim0hi, ..., dimNhi}
    double **T_int;//T_int[region][species]
    double **n_int;//n_int[region][species]
    double ***ui_int;//ui_int[region][species][vdim]
};

union ICVals {
    struct RestartIC restart_ics;
    struct RegionIC region_ics;
};

struct ICInfo{
    enum ICStyle istyle;
    union ICVals ivals;
};

void set_istyle(struct ICInfo *icinfo, char *line);

void set_instyle(struct ICInfo *icinfo, char *line);

void set_infile(struct ICInfo *icinfo, char *line);

void set_nregions(struct ICInfo *icinfo, char *line);

void set_region_temp(struct ICInfo *icinfo, int regionID, char *line);

void set_region_dens(struct ICInfo *icinfo, int regionID, char *line);

void set_region_u(struct ICInfo *icinfo, int regionID, char *line);

#endif //_ICONDITION_H