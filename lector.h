/*******************************************************************
*
*  DESCRIPTION: Atomic Model Lector
*
*******************************************************************/

#ifndef __LECTOR_H
#define __LECTOR_H

#include "atomic.h"     // class Atomic

class Lector : public Atomic
{
public:
	Lector( const string &name = "Lector" );	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &paso;
	Port &detecto;
	Time activoTime;
   enum valoresEstados{ACTIVO, PASIVO};
   int estado;

};	// class Lector

inline
string Lector::className() const
{
	return "Lector" ;
}

#endif   //__LECTOR_H
