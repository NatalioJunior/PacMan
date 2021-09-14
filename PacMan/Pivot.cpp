// ---------------------------------------------------------------------------------
//CARLOS CAVEIRINHA
//CONTROLA OS LOCAIS ONDE OS OBJETOS EM MOVIMENTOS PODEM OU NAO MUDAR DE DIREÇÃO
// ---------------------------------------------------------------------------------


#include "CarlosCaveirinha.h"
#include "Pivot.h"

// ---------------------------------------------------------------------------------

Pivot::Pivot(bool l, bool r, bool u, bool d)
{
    left  = l;
    right = r;
    up    = u;
    down  = d;

    bbox = new Rect(-4, -4, 4, 4);
    type = PIVOT;
}

// ---------------------------------------------------------------------------------

Pivot::~Pivot()
{
    delete bbox;
}

// ---------------------------------------------------------------------------------

