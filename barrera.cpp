/*******************************************************************
*
*  DESCRIPTION: Atomic Model Barrera
*
*******************************************************************/

/** include files **/
#include "barrera.h"    // class Barrera
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Barrera
********************************************************************/
Barrera::Barrera( const string &name )
: Atomic( name )
, levantar( addInputPort( "levantar" ) )
, bajar( addInputPort( "bajar" ) )
{
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Barrera::initFunction()
{
   posicion = BAJA ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Barrera::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == levantar )
	{
      if (posicion == BAJA)
      {
	      posicion = ALTA;
         passivate();
      }
 	}

	if( msg.port() == bajar )
	{
      if (posicion == ALTA)
      {
	      posicion = BAJA;
         passivate();
      }
 	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Barrera::internalFunction( const InternalMessage &msg )
{
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Barrera::outputFunction( const InternalMessage &msg )
{
	return *this;
}           



