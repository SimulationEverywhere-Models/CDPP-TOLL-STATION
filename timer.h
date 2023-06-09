/*******************************************************************
*
*  DESCRIPTION: Atomic Model Timer
*
*******************************************************************/

#ifndef __TIMER_H
#define __TIMER_H

#include "atomic.h"    // class Atomic

class Timer : public Atomic
{
public:
	Timer( const string &name = "Timer" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &timeout;
	Time activeTime;

};	// class Timer

inline
string Timer::className() const
{
	return "Timer" ;
}

#endif   //__TIMER_H
