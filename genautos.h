/*******************************************************************
*
*  DESCRIPTION: Atomic Model GenAutos
*
*******************************************************************/

#ifndef __GENAUTOS_H
#define __GENAUTOS_H

#include "atomic.h"    // class Atomic

/** forward declarations **/
class Distribution ;

class GenAutos : public Atomic
{
public:
	GenAutos( const string &name = "GenAutos" );					//Default constructor

   ~GenAutos();

	virtual string className() const 
		{return "GenAutos";}
      
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &automovil;
	Distribution *dist ;

	Distribution &distribution()
			{return *dist;}

};	// class GenAutos

#endif   //__GENAUTOS_H
