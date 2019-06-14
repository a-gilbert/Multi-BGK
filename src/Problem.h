#ifndef _PROBLEM_H
#define _PROBLEM_H

enum CoulombLog{GMS, NRL};
enum CollisionRate{StantonMurillo, NRL};
enum Closure{VLASOV, BGK_MT, BGK_TR, BGK_GREENE, BGK_NRL};
enum PoissonType{CLASSIC, BOLZTMANN, DEBYE_HUCKEL, THOMAS_FERMI, LINEAR_THOMAS_FERMI};
enum IC{INTERVAL, RESTART};

struct ProblemInfo {
    double Te_init;
    double Te_final;
    enum CoulombLog clog;
    enum CollisionRate nu_style; //don't clog my nu_style. 
    enum Closure rhs_style; //pick yer poison.
    enum PoissonType pot_style;
};

void init_problemInfo(struct ProblemInfo *pinfo);

void set_etemp_init(struct ProblemInfo *pinfo, char *line);

void set_etemp_final(struct ProblemInfo *pinfo, char *line);

void set_clog(struct ProblemInfo *pinfo, char *line);

void set_nu(struct ProblemInfo *pinfo, char *line);

void set_closure(struct ProblemInfo *pinfo, char *line);

void set_poisson(struct ProblemInfo *pinfo, char *line);

#endif //_PROBLEM_H