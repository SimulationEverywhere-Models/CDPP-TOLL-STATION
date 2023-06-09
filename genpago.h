/*******************************************************************
*
*  DESCRIPTION: Atomic Model GenPago
*
*******************************************************************/

#ifndef __GENPAGO_H
#define __GENPAGO_H

#include "atomic.h"     // class Atomic

class GenPago : public Atomic
{
public:
	GenPago( const string &name = "GenPago" );	//Default constructor

   ~GenPago();

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage &msg);
	Model &internalFunction( const InternalMessage &msg);
	Model &outputFunction( const InternalMessage &msg);
   void elegirFilaAlAzar();
   void abrirArchivo();
   void cerrarArchivo();
   void valorMoneda();

private:
	const Port &generar;
	Port &monedas;
	Port &pase;
	Time eligiendoPagoTime;
	Time mandandoMonedasTime;
	Time mandandoPaseTime;
   enum valoresModos{ELIGIENDOPAGO, ESPERANDO, MANDANDOMONEDAS, MANDANDOPASE};
   int modo;
   float monedaActual;
   float probabilidadPase;
   FILE* secuenciaMoneda;

};	// class GenPago

inline
string GenPago::className() const
{
	return "GenPago" ;
}

#endif   //__GENPAGO_H
