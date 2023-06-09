/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cola
*
*******************************************************************/

/** include files **/
#include "cola.h"      // class Cola
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Cola
********************************************************************/
Cola::Cola( const string &name )
: Atomic( name )
, llegaAuto( addInputPort( "legaAuto" ) )
, yaSalio( addInputPort( "yaSalio" ) )
, saleAuto( addOutputPort( "saleAuto" ) )
, saliendoTime( 0, 0, 0, 0 )
{
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Cola::initFunction()
{
   modo = HAYLUGAR;
   cantEncolados = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Cola::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == llegaAuto )
	{
		if (modo == HAYLUGAR)
      {
         cantEncolados += 1;
         entradas[cantEncolados] = msg.time();
         if (cantEncolados == 20)
         {
            modo = LLENA;
            passivate();
         }
      }
	}

	if( msg.port() == yaSalio )
	{
      if (modo == LLENA)
      {
         modo = SALIENDO;
	      holdIn( active, saliendoTime ) ;
      }
      else
         if ((modo == HAYLUGAR) &&  (cantEncolados > 0))
         {
            modo = SALIENDO;
	         holdIn( active, saliendoTime ) ;
         }
	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Cola::internalFunction( const InternalMessage & )
{
   if (modo == SALIENDO)
   {
      sacarPrimero();
      modo = HAYLUGAR;
      passivate();
   }

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Cola::outputFunction( const InternalMessage &msg )
{
   if (modo == SALIENDO)
   {
   	sendOutput( msg.time(), saleAuto, entradas[0].asMsecs()) ;
   }
	return *this ;
}


/*******************************************************************
* Auxiliar Functions
********************************************************************/

Model &Cola::sacarPrimero()
{
   for (int i=1; i<=cantEncolados; i++)
   {
      entradas[i-1] = entradas[i];
   }

   cantEncolados -= 1;

	return *this ;
}

