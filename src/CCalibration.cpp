#include "CCalibration.h"

CCalibration::CCalibration()
{
    coeff_a_dpsi = 0.076660156f;
    coeff_b_dpsi = -156.1238f ;

    coeff_a_ddx1 = 0.001195686f;
    coeff_b_ddx1 = -0.006337136f;//diff

    coeff_a_ddx2 = 0.001195314;
    coeff_b_ddx2 = 0.48171169f;

    coeff_a_ddy1 = -0.001203456f;
    coeff_b_ddy1 = 0.256937926f;

    coeff_a_ddy2 = -0.001201981f;
    coeff_b_ddy2 = 0.313116015f;
    
    coeff_a_dphi = 0.00106;
    coeff_b_dphi1 = 0.002245;
    coeff_b_dphi2 = -0.091161;

    // coeff_a_dpsi = 0.076660156f;
    // coeff_b_dpsi = -157.0f;
    // coeff_a_ddx1 = 0.001195686f;
    // coeff_b_ddx1 = -0.006337136f;
    // coeff_a_ddx2 = -0.001195314;
    // coeff_b_ddx2 = 0.48171169f;
    // coeff_a_ddy1 = -0.001203456f;
    // coeff_b_ddy1 = 0.256937926f;
    // coeff_a_ddy2 = -0.001201981f;
    // coeff_b_ddy2 = 0.313116015f;   
    // coeff_a_dphi = 0.00106;
    // coeff_b_dphi1 = 0.002245;
    // coeff_b_dphi2 = -0.091161;
}

SCalibData CCalibration::calibrate (SContent content)
{
    SCalibData calibData_ {0};
    auto mPsi_d = content.mADCValue;

    auto S1_mAx = content.mSensor1Data.mA_x;
    auto S1_mAy = content.mSensor1Data.mA_y;

    auto S2_mAx = content.mSensor2Data.mA_x;
    auto S2_mAy = content.mSensor2Data.mA_y;

    auto S1_mWz = content.mSensor1Data.mW_z;
    auto S2_mWz = content.mSensor2Data.mW_z;


    calibData_.d_psi = coeff_a_dpsi*mPsi_d+coeff_b_dpsi;

    calibData_.dd_x1 = coeff_a_ddx1*S1_mAx+coeff_b_ddx1;
    calibData_.dd_y1 = coeff_a_ddy1*S1_mAy+coeff_b_ddy1;

    calibData_.dd_x2 = coeff_a_ddx2*S2_mAx+coeff_b_ddx2;
    calibData_.dd_y2 = coeff_a_ddy2*S2_mAy+coeff_b_ddy2;

    calibData_.d_phi1 = -(coeff_a_dphi*S1_mWz+coeff_b_dphi1);
    calibData_.d_phi2 = -(coeff_a_dphi*S2_mWz+coeff_b_dphi2);

    return calibData_;
}