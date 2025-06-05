#ifndef PEPE_AND_JUAN_H
#define PEPE_AND_JUAN_H

struct Pepe
{
    int x;
    int y;
    int z;
    int a;
    int b;
    int c;
};

struct Juan
{
    Pepe& pp;
    int a;

    // Costructor
    Juan(Pepe& p, int val) : pp(p), a(val) {}
};

#endif // PEPE_AND_JUAN_H