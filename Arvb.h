#ifndef ARVB_H_INCLUDED
#define ARVB_H_INCLUDED
#include "NohB.h"

class ArvB
{
    private:
    NohB *root; // ponteiro a ra�z
    int maxO; // ordem m�xima

    public:
    // Construtor, passando a ordem como parametro
    ArvB(int o);
    void cross();
    NohB* searchNoh(int k1);
    void inserti(int a1);
};

#endif // ARVB_H_INCLUDED
