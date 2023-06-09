/*******************************************************************
*
*  DESCRIPTION: Atomic Model Lector
*
*******************************************************************/

/** include files **/
#include "lector.h"      // class Lector
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Lector
********************************************************************/
Lector::Lector( const string &name ): Atomic( name )
, paso( addInputPort( "paso" ) )
, detecto( addOutputPort( "detecto" ) )
, activoTime( 0, 0, 0, 0 )
{
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Lector::initFunction()
{
   estado = PASIVO;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Lector::externalFunction( const ExternalMessage &msg )
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
Model &Lector::internalFunction( const InternalMessage & )
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
Model &Lector::outputFunction( const InternalMessage &msg )
{
   if (estado == ACTIVO)
   {
	   sendOutput(msg.time(), detecto, 0) ;
   }
	return *this ;
}
