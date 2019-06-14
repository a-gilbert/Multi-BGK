#ifndef _DOMAIN_H
#define _DOMAIN_H

enum BoundaryCondition{periodic, fixed};

struct DomainInfo {
    int sdims;
    enum BoundaryCondition bcs;
    double *slims; //1 index->dimension (x, y, z)
    int *Nx; //1 index->dimension
    int vdims;
    double **vmag_lims; //2 indexes-> species, vdim (vx, vy, vz)
    int *Nv;
    double vsigma;
    double *vref;
};

void init_domainInfo(struct DomainInfo *dinfo, int *nspec);

void set_sdims(struct DomainInfo *dinfo, char *line);

void set_bc(struct DomainInfo *dinfo, char *line);

void set_slims(struct DomainInfo *dinfo, char *line);

void set_sgrid(struct DomainInfo *dinfo, char *line);

void set_vdims(struct DomainInfo *dinfo, int *nspec, char *line);

void set_vgrid(struct DomainInfo *dinfo, char *line);

void set_vsigma(struct DomainInfo *dinfo, char *line);

void set_vref(struct DomainInfo *dinfo, double *T);

void set_vmag_lims(struct DomainInfo *dinfo);

#endif //_DOMAIN_H