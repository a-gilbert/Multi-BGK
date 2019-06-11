#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "units/unit_data.c"
#include "Species.h"

void init_speciesInfo(struct SpeciesInfo *sinfo){
    sinfo->ionFix = fixed;
    sinfo->ecouple = dynamic;
    sinfo->nspec = 1; //electrons are dynamic
    sinfo->m = malloc(sizeof(double));
    sinfo->m[0] = M_ELEC_CGS;
    sinfo->Z = malloc(sizeof(double));
    sinfo->Z[0] =  -1.0;
}

void set_ionType(struct SpeciesInfo *sinfo, char *line){
    if(strcmp("ion_fix = fixed", line) == 0) {
        sinfo->ionFix = fixed;
    } else if(strcmp("ion_fix = averageAtom", line) == 0) {
        sinfo->ionFix = averageAtom;
    }
}

void set_ecoupling(struct SpeciesInfo *sinfo, char *line){
    if(strcmp("ecouple = dynamic", line) == 0) {
        sinfo->ecouple = dynamic;
    } else if(strcmp("ecouple = sticky", line) == 0) {
        sinfo->ecouple = sticky;
    }
}

void set_nspec(struct SpeciesInfo *sinfo, char *line){
    sscanf(line, "nspec = %d", &sinfo->nspec);
    if(sinfo->ecouple == dynamic){
        sinfo->nspec += 1;
    }
    sinfo->m = malloc(sinfo->nspec*sizeof(double));
    sinfo->Z = malloc(sinfo->nspec*sizeof(double));
}

void set_mass(struct SpeciesInfo *sinfo, int species, char *line){
    sscanf(line, "%g", &sinfo->m[species]);
}

void set_z(struct SpeciesInfo *sinfo, int species, char *line){
    sscanf(line, "%g", &sinfo->Z[species]);
}
