#pragma once

#include "AComponentBase.h"
#include "CContainer.h"
#include "CBBBHardware.h"

class ControlComp : public AComponentBase //: classe permet d'hériter la partie publique de AComponentBase
{
public : 
    ControlComp (CContainer& container);
    
    void init() override; //void init existe déjà en virtuel dans classe héritage AComponentBase ==> override pour écrire par dessus cette def.
    void run() override;
    
private : 
    CContainer& container_ref; // Reference à CContainer (~adresse)
    CBBBHardware hardware_; // Instance de CBBBHardware (declarer un objet qui est type CBBBHardware)

};
