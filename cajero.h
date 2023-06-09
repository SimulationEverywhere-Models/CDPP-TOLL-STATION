/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cajero
*
*******************************************************************/

#ifndef __CAJERO_H
#define __CAJERO_H

#include "atomic.h"     // class Atomic

class Cajero : public Atomic
{
public:
	Cajero( const string &name = "Cajero" );	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
   int noHayParaDarVuelto();
   int tengoMonedaQueCancelaVuelto();
   float mayorMonedaEnStockMenorQueVuelto();

private:
	const Port &monedas;
	const Port &detectoPase;
	const Port &yaSalio;
	Port &devolver;
	Port &pago;
	Port &multar;
	Time pagoTime;
	Time devolviendoTime;
	Time pagandoTime;
   enum valoresModos{ESPERANDO, PAGO, DEVOLVIENDO, PAGANDO};
   int modo;
   int cantMonedas5;
   int cantMonedas10;
   int cantMonedas50;
   int cantMonedas100;
   float plataPagada;
   float vuelto;
   float costoPeaje;
   float ultimaMoneda;
   enum valoresTipoPago{PASE, MONEDAS};
   int tipoPago;

};	// class Cajero

inline
string Cajero::className() const
{
	return "Cajero" ;
}

#endif   //__CAJERO_H
