/*******************************************************************
*
*  DESCRIPTION: Atomic Model Timer
*
*******************************************************************/

/** include files **/
#include "timer.h"      // class Timer
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Timer
********************************************************************/
Timer::Timer( const string &name )
: Atomic( name )
, timeout( addOutputPort( "timeout" ) )
, activeTime( 1, 0, 0, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "activeTime" ) ) ;

	if( time != "" )
		activeTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Timer::initFunction()
{
	holdIn( active, activeTime ) ;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Timer::externalFunction( const ExternalMessage &msg )
{
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Timer::internalFunction( const InternalMessage & )
{
	holdIn( active, activeTime ) ;
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Timer::outputFunction( const InternalMessage &msg )
{
 	sendOutput( msg.time(), timeout, 0) ;
	return *this ;
}

