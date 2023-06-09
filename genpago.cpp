/*******************************************************************
*
*  DESCRIPTION: Atomic Model GenPago
*
*******************************************************************/

/** include files **/
#include "genpago.h"    // class GenPago
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include "real.h"       // class Real ....
#include "realfunc.h"   // function Binomial, ....
#include "strutil.h"    // str2Value( ... )
#include "stdio.h"      // entrada/salida

/** public functions **/

/*******************************************************************
* Function Name: GenPago
********************************************************************/
GenPago::GenPago( const string &name ): Atomic( name )
, generar( addInputPort( "generar" ) )
, monedas( addOutputPort( "monedas" ) )
, pase( addOutputPort( "pase" ) )
, eligiendoPagoTime( 0, 0, 0, 0 )
, mandandoMonedasTime( 0, 0, 0, 0 )
, mandandoPaseTime( 0, 0, 0, 0 )
{
   probabilidadPase = str2Value(MainSimulator::Instance().getParameter( description(), "probabilidadPase")) ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &GenPago::initFunction()
{
   modo = ESPERANDO;
   abrirArchivo();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &GenPago::externalFunction( const ExternalMessage &msg )
{
	if (msg.port() == generar)
	{
      if (modo == ESPERANDO)
      {
         modo = ELIGIENDOPAGO;
   	   holdIn(active, eligiendoPagoTime) ;
      }
 	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &GenPago::internalFunction( const InternalMessage &msg)
{
   if (modo == ELIGIENDOPAGO)
   {
      if (binomial(1, probabilidadPase) == 1)
      {
         modo = MANDANDOPASE;
	      holdIn(active, mandandoPaseTime);
      }
      else
      {
         modo = MANDANDOMONEDAS;
         elegirFilaAlAzar();
	      holdIn(active, mandandoMonedasTime);
      }
   }

   if (modo == MANDANDOMONEDAS)
   {
      /*******************************************************************
      * La lectura del archivo se realiza una única vez en oututFunction
      * por el corrimiento del puntero del archivo
      *******************************************************************/

      if (monedaActual == 0)
      {
         modo = ESPERANDO;
         passivate();
      }
      else
         holdIn(active, mandandoMonedasTime);
   }

   if (modo == MANDANDOPASE)
   {
      modo = ESPERANDO;
      passivate();
   }

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &GenPago::outputFunction( const InternalMessage &msg )
{

   if (modo == MANDANDOPASE)
   {
	   sendOutput(msg.time(), pase, 0) ;
   }

   if (modo == MANDANDOMONEDAS)
   {
      valorMoneda();
      if (monedaActual > 0)
      {
   	   sendOutput(msg.time(), monedas, monedaActual) ;
      }
   }

	return *this ;
}

/*******************************************************************
* Function Name: ~GenAutos
********************************************************************/
GenPago::~GenPago()
{
   cerrarArchivo();
}

/*******************************************************************
* Function Name: ElegirFilaAlAzar
********************************************************************/
void GenPago::elegirFilaAlAzar()
{
int fila;
char* aux = NULL;

   fila = (int) randInt(Real(20)).value();
   fseek(secuenciaMoneda, 0, SEEK_SET);

   for (int i=1; i<fila; i++) {
      fgets(aux, 255, secuenciaMoneda);
   }
}

/*******************************************************************
* Function Name: AbrirArchivo
********************************************************************/
void GenPago::abrirArchivo()
{
   secuenciaMoneda = fopen("monedas.txt", "r");
}

/*******************************************************************
* Function Name: CerrarArchivo
********************************************************************/
void GenPago::cerrarArchivo()
{
   fclose(secuenciaMoneda);
}

/*******************************************************************
* Function Name: ValorMoneda
********************************************************************/
void GenPago::valorMoneda()
{
   fscanf(secuenciaMoneda, "%f", &monedaActual);
}



