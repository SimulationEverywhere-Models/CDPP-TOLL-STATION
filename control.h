/*******************************************************************
*
*  DESCRIPTION: Atomic Model Control
*
*******************************************************************/

#ifndef __CONTROL_H
#define __CONTROL_H

#include "atomic.h"     // class Atomic

class Control : public Atomic
{
public:
	Control( const string &name = "Control" );	//Default constructor

	~Control();

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );
   void abrirArchivo();
   void cerrarArchivo();
   void escribirArchivoLog();

private:
	const Port &pago;
	const Port &yaSalio;
	const Port &timeout;
	const Port &yaEntro;
	const Port &multar;
	Port &levantarBarrera;
	Port &logInfo;
	Time levantarTime;
	Time timeoutTime;
   enum valoresModos{LEVANTAR, TIMEOUT, PASIVO};
   int modo;
   Time horaEntrada;
   float cantAutosPase;
   float cantAutosMonedas;
   Time sumaDemoras;
   float cantMultados;
   enum parametrosInfo{CANTMONEDAS, CANTPASE, DEMORAS, MULTADOS};
   int parametroInfo;
   enum valoresPago{PASE, MONEDAS};
   FILE* logInfoFile;

};	// class Control

inline
string Control::className() const
{
	return "Control" ;
}

#endif   //__CONTROL_H
