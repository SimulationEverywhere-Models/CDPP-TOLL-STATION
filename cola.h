/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cola
*
*******************************************************************/

#ifndef __COLA_H
#define __COLA_H

#include "atomic.h"    // class Atomic
#include "time.h"    // class Atomic

class Cola : public Atomic
{
public:
	Cola( const string &name = "Cola" );					//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
	Model &sacarPrimero();

private:
	const Port &llegaAuto;
	const Port &yaSalio;
	Port &saleAuto;
	Time saliendoTime;
	Time entradas[20];
   enum valoresModos{LLENA, HAYLUGAR, SALIENDO};
   int modo;
   int cantEncolados;

};	// class Cola

inline
string Cola::className() const
{
	return "Cola" ;
}

#endif   //__COLA_H
