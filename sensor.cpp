/*******************************************************************
*
*  DESCRIPTION: Atomic Model Sensor
*
*******************************************************************/

/** include files **/
#include "sensor.h"     // class Sensor
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Sensor
********************************************************************/
Sensor::Sensor( const string &name ): Atomic( name )
, paso( addInputPort( "paso" ) )
, detecto( addOutputPort( "detecto" ) )
, activoTime( 0, 0, 0, 0 )
{
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Sensor::initFunction()
{
   estado = PASIVO;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Sensor::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == paso )
	{
      estado = ACTIVO;
	   holdIn( active, activoTime ) ;
 	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Sensor::internalFunction( const InternalMessage & )
{
   if (estado == ACTIVO)
   {
   	estado = PASIVO;
      passivate();
   }
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Sensor::outputFunction( const InternalMessage &msg )
{
   if (estado == ACTIVO)
   {
	   sendOutput(msg.time(), detecto, 0) ;
   }
	return *this ;
}
