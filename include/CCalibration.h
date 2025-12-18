#pragma once

#include <iostream>
#include "SCalibData.h"
#include "SContent.h"


class CCalibration {

    public: 
        CCalibration();
        SCalibData calibrate(SContent content);

    private:
        float coeff_a_dpsi;
        float coeff_b_dpsi;
        float coeff_a_ddx1;
        float coeff_b_ddx1;
        float coeff_a_ddx2;
        float coeff_b_ddx2;
        float coeff_a_ddy1;
        float coeff_b_ddy1;
        float coeff_a_ddy2;
        float coeff_b_ddy2;
        float coeff_a_dphi;
        float coeff_b_dphi1;
        float coeff_b_dphi2;
};