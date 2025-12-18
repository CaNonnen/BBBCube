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
    SStateVectorData outputVector = inputVector;
    if (isFirstCalculation)
    {
        isFirstCalculation = false;
        phi_nminus1 = inputVector.mPhi_A;
    }else{
        phi_nminus1 = alpha*(phi_nminus1+T*inputVector.mPhi_d) + (1-alpha)*inputVector.mPhi_A;
    }

    outputVector.mPhi_C = phi_nminus1;
    return outputVector;
}