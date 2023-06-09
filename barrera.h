/*******************************************************************
*
*  DESCRIPTION: Atomic Model Barrera
*
*******************************************************************/

#ifndef __BARRERA_H
#define __BARRERA_H

#include "atomic.h"     // class Atomic

class Barrera : public Atomic
{
public:
	Barrera( const string &name = "Barrera" );	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &levantar;
	const Port &bajar;
   enum valoresPosiciones{ALTA, BAJA};
   int posicion;
};	// class Barrera

inline
string Barrera::className() const
{
	return "Barrera" ;
}

#endif   //__BARRERA_H
