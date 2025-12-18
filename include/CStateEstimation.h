#pragma once

#include <iostream>
#include <cmath>
#include "SStateVectorData.h"
#include "SCalibData.h"

class CStateEstimation
{
    public:
        CStateEstimation();
        SStateVectorData estimate(SCalibData);

    private:
        float Abstand_AS1; //en m
        float Abstand_AS2; //en m
};