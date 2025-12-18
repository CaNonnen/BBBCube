#include <iostream>

#include "CStateEstimation.h"

CStateEstimation::CStateEstimation()
{
    Abstand_AS1 = 0.14;
    Abstand_AS2 = 0.061;
}

SStateVectorData CStateEstimation::estimate(SCalibData calibData)
{
    SStateVectorData vectorData_{};

    vectorData_.mPsi_d= calibData.d_psi;//direct: dpsi

    vectorData_.mPhi_d = (calibData.d_phi1+calibData.d_phi2) /2; //Mittelung Phi gyro1 und phi Gyro2.

    float r_ratio = Abstand_AS1/Abstand_AS2;
    vectorData_.mPhi_A = atan2(calibData.dd_x1 - r_ratio*calibData.dd_x2,calibData.dd_y1 - r_ratio*calibData.dd_y2);

    return vectorData_;
}
