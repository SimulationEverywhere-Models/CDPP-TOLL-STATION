/*******************************************************************
*
*  DESCRIPTION: Atomic Model GenAutos
*
*******************************************************************/

/** include files **/
#include "genautos.h"   // class GenAutos
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include "distri.h"     // class Distribution
#include "strutil.h"    // str2Value( ... )
                   
/** public functions **/

/*******************************************************************
* Function Name: GenAutos
********************************************************************/
GenAutos::GenAutos( const string &name )
: Atomic( name )
, automovil( addOutputPort( "automovil" ) )
{
   dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribucion" ) );
	for ( register int i = 0; i < dist->varCount(); i++ )
	{
		string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
		dist->setVar( i, str2Value( parameter ) ) ;
	}
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &GenAutos::initFunction()
{
	holdIn( active, Time::Zero ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &GenAutos::externalFunction( const ExternalMessage &msg )
{
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &GenAutos::internalFunction( const InternalMessage &msg )
{
	holdIn( active, Time( static_cast< float >( fabs( distribution().get() ) ) ) ) ;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &GenAutos::outputFunction( const InternalMessage &msg )
{
 	sendOutput( msg.time(), automovil, 0) ;
	return *this ;
}

GenAutos::~GenAutos()
{
	delete dist;
}
