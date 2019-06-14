#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "Domain.h"

void init_domainInfo(struct DomainInfo *dinfo, int *nspec){
    dinfo->sdims = 1;
    dinfo->bcs = periodic;
    dinfo->slims = malloc(sizeof(double));
    dinfo->Nx = malloc(sizeof(int));
    dinfo->slims[0] = 1000e-6;
    dinfo->Nx[0] = 32;
    dinfo->vdims = 3;
    //set Nv in each direction
    dinfo->Nv = malloc(3*sizeof(int));
    for(int i = 0; i<3; i++){
        dinfo->Nv[i] = 40;
    }
    dinfo->vsigma = 6.0;
    dinfo->vref = malloc(*nspec*sizeof(double));
    dinfo->vmag_lims = malloc(*nspec*sizeof(double *));
    for(int i = 0; i<*nspec; i++){
        dinfo->vmag_lims[i] = malloc(sizeof(double));
    }
}

void set_sdims(struct DomainInfo *dinfo, char *line){
    sscanf(line, "sdims = %d", &dinfo->sdims);
    //techinically some savings could be made here if dinfo->sdims=0
    dinfo->slims = realloc(dinfo->slims, dinfo->sdims*sizeof(double));
    dinfo->Nx = realloc(dinfo->Nx, dinfo->sdims*sizeof(int));
}

void set_bc(struct DomainInfo *dinfo, char *line){
    if(strcmp(line, "boundary = periodic") == 0){
        dinfo->bcs = periodic;
    } else if(strcmp(line, "boundary = fixed") == 0){
        dinfo->bcs = fixed;
    }
}

void set_slims(struct DomainInfo *dinfo, char *line){
    if(dinfo->sdims > 0){
        if(dinfo->sdims == 1){
            sscanf(line, "slims = %g", &dinfo->slims[0]);
        //next two cases assume you want the same limit in each direction. Mildly convenient...
        } else if(dinfo->sdims == 2){
            int i = sscanf(line, "slims = %g %g", &dinfo->slims[0], &dinfo->slims[1]);
            if(i < 2) {
                dinfo->slims[1] = dinfo->slims[0];
            }
        } else if(dinfo->sdims == 3){
            int i = sscanf(line, "slims = %g %g %g", &dinfo->slims[0], &dinfo->slims[1], &dinfo->slims[2]);
            if(i < 3){
                dinfo->slims[1] = dinfo->slims[0];
                dinfo->slims[2] = dinfo->slims[0];
            }
        }
    }
}

void set_sgrid(struct DomainInfo *dinfo, char *line){
    if(dinfo->sdims > 0){
        if(dinfo->sdims == 1){
            sscanf(line, "Nx = %d", &dinfo->Nx[0]);
        } else if(dinfo->sdims == 2){
            int i = sscanf(line, "Nx = %d %d", &dinfo->Nx[0], &dinfo->Nx[1]);
            if(i < 2){
                dinfo->Nx[1] = dinfo->Nx[0];
            }
        } else if(dinfo->sdims == 3){
            int i = sscanf(line, "Nx = %d %d %d", &dinfo->Nx[0], &dinfo->Nx[1], &dinfo->Nx[2]);
            if(i < 3){
                dinfo->Nx[1] = dinfo->Nx[0];
                dinfo->Nx[2] = dinfo->Nx[0];
            }
        }
    }
}

void set_vdims(struct DomainInfo *dinfo, int *nspec, char *line){
    sscanf(line, "vdims = %d", &dinfo->vdims);
    dinfo->Nv = realloc(dinfo->Nv, dinfo->vdims*sizeof(int));
    for(int i = 0; i<*nspec; i++){
        dinfo->vmag_lims[i] = realloc(dinfo->vmag_lims[i], dinfo->vdims*sizeof(double));
    }
}

void set_vgrid(struct DomainInfo *dinfo, char *line){
    if(dinfo->vdims > 0){
        if(dinfo->vdims == 1){
            sscanf(line, "Nv = %d", &dinfo->Nv[0]);
        } else if(dinfo->sdims == 2){
            int i = sscanf(line, "Nx = %d %d", &dinfo->Nv[0], &dinfo->Nv[1]);
            if(i < 2){
                dinfo->Nv[1] = dinfo->Nv[0];
            }
        } else if(dinfo->sdims == 3){
            int i = sscanf(line, "Nx = %d %d %d", &dinfo->Nv[0], &dinfo->Nv[1], &dinfo->Nv[2]);
            if(i < 3){
                dinfo->Nx[1] = dinfo->Nv[0];
                dinfo->Nx[2] = dinfo->Nv[0];
            }
        }
    }
}

void set_vsigma(struct DomainInfo *dinfo, char *line){
    sscanf(line, "vsigma = %g", &dinfo->vsigma);
}

//write after making moment structure
void set_vref(struct DomainInfo *dinfo, double *T){

}

//write after making moment structure
void set_vmag_lims(struct DomainInfo *dinfo){

}