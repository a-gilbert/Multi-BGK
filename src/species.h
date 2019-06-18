#ifndef _SPECIES_H
#define _SPECIES_H

enum IonizationType{fixed, averageAtom};
enum ElectronBehavior{dynamic, sticky}; //sticky as in born-oppenheimer

struct SpeciesInfo {
    enum IonizationType ionFix;
    enum ElectronBehavior ecouple;
    int nspec;
    double *m;//masses
    double *Z;//proton numbers

};

void init_species_info(struct SpeciesInfo *sinfo);

void set_ionType(struct SpeciesInfo *sinfo, char *line);

void set_ecoupling(struct SpeciesInfo *sinfo, char *line);

void set_nspec(struct SpeciesInfo *sinfo, char *line);

void set_mass(struct SpeciesInfo *sinfo, int species, char *line);

void set_z(struct SpeciesInfo *sinfo, int species, char *line);

#endif //_SPECIES_H