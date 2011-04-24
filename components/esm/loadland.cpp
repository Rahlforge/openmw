#include "loadland.hpp"

namespace ESM
{
void Land::load(ESMReader &esm)
{
    // Get the grid location
    esm.getSubNameIs("INTV");
    esm.getSubHeaderIs(8);
    esm.getT<int>(X);
    esm.getT<int>(Y);

    esm.getHNT(flags, "DATA");

    // Store the file position
    context = esm.getContext();

    hasData = false;
    int cnt = 0;

    // Skip these here. Load the actual data when the cell is loaded.
    if(esm.isNextSub("VNML")) {esm.skipHSubSize(12675);cnt++;}
    if(esm.isNextSub("VHGT")) {esm.skipHSubSize(4232);cnt++;}
    if(esm.isNextSub("WNAM")) esm.skipHSubSize(81);
    if(esm.isNextSub("VCLR")) esm.skipHSubSize(12675);
    if(esm.isNextSub("VTEX")) {esm.skipHSubSize(512);cnt++;}

    // We need all three of VNML, VHGT and VTEX in order to use the
    // landscape.
    hasData = (cnt == 3);
}
}