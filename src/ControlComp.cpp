#include "ControlComp.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono;

ControlComp::ControlComp(CContainer& container)
    : container_ref(container) // Initialisation de container_ref. Pareil que = mais ici il faut ()
    , hardware_()
{
} //Tout a été initialisé avant, rien dans crochets. Jamais de return dans constructeur.

void ControlComp :: init()
{
}

void ControlComp :: run()
{
    UInt16 adcValue = 0; //adc ressort que des valeurs positives
	CIMUData sensor1Data = {0};
	CIMUData sensor2Data = {0};

    SContent content;
    SCalibData data;
    SStateVectorData stateVector;

    /*
    CIMUData* pStruct = &sensor1Data;  Ici, pStruct est le pointeur qui pointe sur l'adresse (&) de sensor1Data
    pStruct->mA_x  "->" n'est utilisée que sur des struct ou classes et permet de lire une valeur pointée par un pointeur.
    Sinon, on écrit juste sensor1Data.mA_x
    */

    int i =0;
    auto tstart = steady_clock::now();

    while (true) //Lire les valeurs que toutes les 20ms !!!
    {

        if(!hardware_.fetchValues(adcValue, sensor1Data, sensor2Data)) //if pb en lisant valeurs
        {
            std::cerr << "Erreur while reading sensor's data. (in ControlComp.run())" << std::endl;
        }

        std::cout<<"\n\nCycle nb: "<<i<< "\n"<<std::endl;

        // //Affichage console
        // std::cout << "adcValue : " << adcValue << std::endl;
        // std::cout << "sensor1Data : " << std::endl;
        // std::cout << "mA_x: " << sensor1Data.mA_x << std::endl;
        // std::cout << "mW_x: " << sensor1Data.mW_x << std::endl;
        // std::cout << "mW_y: " << sensor1Data.mW_y << std::endl;
        // std::cout << "mW_z: " << sensor1Data.mW_z << std::endl;
        // std::cout << "mA_x: " << sensor1Data.mA_x << std::endl;
        // std::cout << "mA_y: " << sensor1Data.mA_y << std::endl;
        // std::cout << "mA_z: " << sensor1Data.mA_z << std::endl;
        // std::cout << "mPhi_d: " << sensor1Data.mPhi_d << std::endl;
        // std::cout << "mX_dd: " << sensor1Data.mX_dd << std::endl;
        // std::cout << "mY_dd: " << sensor1Data.mY_dd << std::endl;
        // std::cout << "mZ_dd: " << sensor1Data.mZ_dd << std::endl;

        // std::cout << "sensor2Data : " << std::endl;
        // std::cout << "mA_x: " << sensor2Data.mA_x << std::endl;
        // std::cout << "mW_x: " << sensor2Data.mW_x << std::endl;
        // std::cout << "mW_y: " << sensor2Data.mW_y << std::endl;
        // std::cout << "mW_z: " << sensor2Data.mW_z << std::endl;
        // std::cout << "mA_x: " << sensor2Data.mA_x << std::endl;
        // std::cout << "mA_y: " << sensor2Data.mA_y << std::endl;
        // std::cout << "mA_z: " << sensor2Data.mA_z << std::endl;
        // std::cout << "mPhi_d: " << sensor2Data.mPhi_d << std::endl;
        // std::cout << "mX_dd: " << sensor2Data.mX_dd << std::endl;
        // std::cout << "mY_dd: " << sensor2Data.mY_dd << std::endl;
        // std::cout << "mZ_dd: " << sensor2Data.mZ_dd << std::endl;

        //Ecriture dans container
        container_ref.writeADCValue(adcValue);
        container_ref.writeSensor1Data(sensor1Data);
        container_ref.writeSensor2Data(sensor2Data);

        //Ecrire dans Scontent:
        content.mADCValue = adcValue;
        content.mSensor1Data = sensor1Data;
        content.mSensor2Data = sensor2Data;

        data = calibration.calibrate(content);
        stateVector = estimation.estimate(data);
        stateVector = filter.filter(stateVector);

        container_ref.writeStateData(stateVector);

        auto tnow = steady_clock::now();

        container_ref.writeTime(duration_cast<milliseconds>(tnow - tstart).count());
        container_ref.signalReader();

        std::this_thread::sleep_for(milliseconds(20));
        i++;

    }
}