#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "CContainer.h" //<librairies standart> "librairiesPerso"
#include "ControlComp.h"
#include "CThread.h"
#include "CCommComp.h"

#include "CCalibration.h"
#include "SCalibData.h"

using namespace std;// evite de réecrire devant chaque fct qu'on appelle

CContainer container();

int main()
{
	CContainer container = CContainer(); // equivalent à CContainer container{}
	ControlComp control(container);
	CCommComp communication(container);

	CThread threadControl(&control, CThread::PRIORITY_ABOVE_NORM); //on met &control car le constructeur CThread utilise un pointeur et pas l'objet controlComp
	CThread threadComm(&communication, CThread::PRIORITY_ABOVE_NORM);

	threadControl.start();
	threadComm.start();

	threadControl.join();
	threadComm.join(); // concretement, permet d'attendre que .start ai fini ...mais c'est une boucle infinie ==> mettre à la fin
	
	return 0;
}