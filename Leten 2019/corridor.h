#ifndef CORRIDOR_H
#define CORRIDOR_H

struct step {
    char action; // l, r, t, a
    int answer;
};

void set_memory(int index, int value);
int get_memory(int index);

#endif
