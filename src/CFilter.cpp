#include <iostream>

#include "CFilter.h"

CFilter::CFilter ()
{
    T = 0.02; //sec
    alpha = 0.98;
    phi_nminus1 = 0.0f;
    isFirstCalculation = true;
}

SStateVectorData CFilter::filter(SStateVectorData inputVector)
{
    SStateVectorData outputVector {};
    outputVector.mPhi_d = inputVector.mPhi_d;
    outputVector.mPsi_d = inputVector.mPsi_d;
    if (isFirstCalculation)
    {
        isFirstCalculation = false;
        outputVector.mPhi_A = inputVector.mPhi_A;
        phi_nminus1 = inputVector.mPhi_A;
    }else{
        outputVector.mPhi_A = alpha*(phi_nminus1+T*inputVector.mPhi_d) + (1-alpha)*inputVector.mPhi_A;
        phi_nminus1 = outputVector.mPhi_A;
    }
    return outputVector;
}