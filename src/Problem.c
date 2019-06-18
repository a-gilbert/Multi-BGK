#include<stdio.h>
#include<string.h>
#include "Problem.h"

void init_problem_info(struct ProblemInfo *pinfo){
    pinfo->Te_init = 100.0;
    pinfo->Te_final = 100.0;
    pinfo->clog = GMS;
    pinfo->nu_style = StantonMurillo;
    pinfo->rhs_style = BGK_TR;
    pinfo->pot_style = CLASSIC;
}

void set_etemp_init(struct ProblemInfo *pinfo, char *line){
    sscanf(line, "Te_init = %g", &pinfo->Te_init);
}

void set_etemp_final(struct ProblemInfo *pinfo, char *line){
    sscanf(line, "Te_final = %g", &pinfo->Te_final);
}

void set_clog(struct ProblemInfo *pinfo, char *line){
    if(strcmp(line, "Coulomb_Log = GMS") == 0){
        pinfo->clog = GMS;
    } else if(strcmp(line, "Coulomb_Log = NRL") == 0){
        pinfo->clog = NRL;
    }
}

void set_nu(struct ProblemInfo *pinfo, char *line){
    if(strcmp(line, "Ion_Coll_Type = StantonMurillo") == 0){
        pinfo->nu_style = StantonMurillo;
    } else if(strcmp(line, "Ion_Coll_Type = NRL") == 0){
        pinfo->nu_style = NRL;
    }
}

void set_closure(struct ProblemInfo *pinfo, char *line){
    if(strcmp(line, "Closure_Type = Vlasov") == 0){
        //vlasov means no rhs, makes no comment on the mean field. 
        pinfo->rhs_style = VLASOV;
    }else if(strcmp(line, "Closure_Type = BGK_MT") == 0){
        pinfo->rhs_style = BGK_MT;
    }else if(strcmp(line, "Closure_Type = BGK_TR") == 0){
        pinfo->rhs_style = BGK_TR;
    }else if(strcmp(line, "Closure_Type = BGK_GREENE") == 0){
        pinfo->rhs_style = BGK_GREENE;
    }else if(strcmp(line, "Closure_Type = BGK_NRL") == 0){
        pinfo->rhs_style = BGK_NRL;
    }
}

void set_poisson(struct ProblemInfo *pinfo, char *line){
    if(strcmp(line, "Poisson = None") == 0){
        pinfo->pot_style=NONE;
    }else if(strcmp(line, "Poisson = Classic") == 0){
        pinfo->pot_style=CLASSIC;
    }else if(strcmp(line, "Poisson = Boltzmann") == 0){
        pinfo->pot_style=BOLZTMANN;
    }else if(strcmp(line, "Poisson = Debye_Huckel") == 0){
        pinfo->pot_style=DEBYE_HUCKEL;
    }else if(strcmp(line, "Poisson = Thomas_Fermi") == 0){
        pinfo->pot_style=THOMAS_FERMI;
    }else if(strcmp(line, "Poisson = Linear_Thomas_Fermi") == 0){
        pinfo->pot_style=LINEAR_THOMAS_FERMI;
    }
}
