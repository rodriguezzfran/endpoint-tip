#ifndef DECLARE_AT_HPP
#define DECLARE_AT_HPP



struct Pepe
{
    int x;
    int y;
    int z;
};

struct Juan
{
    Pepe& pp;
    int a;

    // Costructor
    Juan(Pepe& p, int val) : pp(p), a(val) {}

};



#endif 