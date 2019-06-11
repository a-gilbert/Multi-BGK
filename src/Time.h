#ifndef _TIME_H
#define _TIME_H

struct TimeInfo {
    double dt;
    double t;
    double tfinal;
    int nT;
};

void init_timeInfo(struct TimeInfo* tinfo);

void set_timestep(struct TimeInfo* tinfo, char *line);

void set_time(struct TimeInfo* tinfo, double atime);

void set_tfinal(struct TimeInfo* tinfo, char *line);

void update_time(struct TimeInfo* tinfo);

void update_timestep(struct TimeInfo* tinfo);

#endif //_TIME_H