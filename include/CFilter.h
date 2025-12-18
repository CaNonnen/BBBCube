#pragma once

#include "SStateVectorData.h"

class CFilter
{
    public:
        CFilter();
        SStateVectorData filter(SStateVectorData);
    private:
        float T; //Abtatsperiode
        float alpha; //Faktor
        float phi_nminus1;
        bool isFirstCalculation;
};