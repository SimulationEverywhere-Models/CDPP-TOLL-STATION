/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "barrera.h"    // class Barrera
#include "lector.h"     // class Lector
#include "control.h"    // class Control
#include "cajero.h"     // class Cajero
#include "timer.h"      // class Timer
#include "cola.h"       // class Cola
#include "sensor.h"     // class Sensor
#include "genpago.h"    // class GenPago
#include "genautos.h"   // class GenAutos


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Barrera>() , "Barrera" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Lector>() , "Lector" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Control>() , "Control" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cajero>() , "Cajero" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Timer>() , "Timer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Cola>() , "Cola" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Sensor>() , "Sensor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<GenPago>() , "GenPago" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<GenAutos>() , "GenAutos" ) ;
}
