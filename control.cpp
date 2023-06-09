/*******************************************************************
*
*  DESCRIPTION: Atomic Model Control
*
*******************************************************************/

/** include files **/
#include "control.h"      // class Control
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )
#include "stdio.h"      // entrada/salida

/** public functions **/

/*******************************************************************
* Function Name: Control
********************************************************************/
Control::Control( const string &name ): Atomic( name )
, pago( addInputPort( "pago" ) )
, yaSalio( addInputPort( "yaSalio" ) )
, timeout( addInputPort( "timeout" ) )
, yaEntro( addInputPort( "yaEntro" ) )
, multar( addInputPort( "multar" ) )
, levantarBarrera( addOutputPort( "levantarBarrera" ) )
, logInfo( addOutputPort( "logInfo" ) )
, levantarTime( 0, 0, 0, 0 )
, timeoutTime( 0, 0, 0, 0 )
{
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Control::initFunction()
{
   modo = PASIVO;
   cantAutosPase = 0;
   cantAutosMonedas = 0;
   sumaDemoras = Time::Zero;
   cantMultados = 0;
   abrirArchivo();
  	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Control::externalFunction( const ExternalMessage &msg )
{
float tiempo;

	if( msg.port() == pago )
	{
      if (modo == PASIVO)
      {
         if (msg.value() == PASE)
            cantAutosPase += 1;
         else
            cantAutosMonedas += 1;

         modo = LEVANTAR;
	      holdIn( active, levantarTime ) ;
      }
 	}

	if( msg.port() == timeout )
	{
      if (modo == PASIVO)
      {
         modo = TIMEOUT;
         parametroInfo = CANTMONEDAS;
	      holdIn( active, timeoutTime ) ;
      }
 	}

	if( msg.port() == multar )
	{
      if (modo == PASIVO)
      {
         cantMultados += 1;
         modo = LEVANTAR;
	      holdIn( active, levantarTime ) ;
      }
 	}

	if( msg.port() == yaSalio )
	{
      if (modo == PASIVO)
      {
         sumaDemoras += msg.time() - horaEntrada;
      }
 	}

	if( msg.port() == yaEntro )
	{
      if (modo == PASIVO)
      {
         tiempo = msg.value();
         horaEntrada = Time(tiempo);
      }
 	}

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Control::internalFunction( const InternalMessage & )
{
   if (modo == LEVANTAR)
   {
   	modo = PASIVO;
      passivate();
   }

   if (modo == TIMEOUT)
   {
      if (parametroInfo == CANTMONEDAS)
      {
         printf("%s", "interna monedas");
         parametroInfo = CANTPASE;
         holdIn(active, timeoutTime);
      }

      if (parametroInfo == CANTPASE)
      {
         printf("%s", "interna pase");
         parametroInfo = DEMORAS;
         float auxi = 1;
         holdIn(active, timeoutTime+Time(auxi));
      }

      if (parametroInfo == DEMORAS)
      {
         printf("%s", "interna demoras");
         parametroInfo = MULTADOS;
         holdIn(active, timeoutTime);
      }

      if (parametroInfo == MULTADOS)
      {
         printf("%s", "interna multados");
         cantAutosPase = 0;
         cantAutosMonedas = 0;
         sumaDemoras = Time::Zero;
         cantMultados = 0;
   	   modo = PASIVO;
         passivate();
      }
   }

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Control::outputFunction( const InternalMessage &msg )
{
   if (modo == LEVANTAR)
   {
	   sendOutput(msg.time(), levantarBarrera, 0) ;
   }

   if (modo == TIMEOUT)
   {
      if (parametroInfo == CANTMONEDAS)
      {
         printf("%s", "output monedas");
         escribirArchivoLog();
   	   sendOutput(msg.time(), logInfo, cantAutosMonedas);
      }

      if (parametroInfo == CANTPASE)
      {
         printf("%s", "output pase");
         escribirArchivoLog();
   	   sendOutput(msg.time(), logInfo, cantAutosPase);
      }

      if (parametroInfo == DEMORAS)
      {
         printf("%s", "output demoras");
   	   sendOutput(msg.time(), logInfo, sumaDemoras.asMsecs() / cantAutosMonedas);
      }

      if (parametroInfo == MULTADOS)
      {
         printf("%s", "output multados");
   	   sendOutput(msg.time(), logInfo, cantMultados);
      }
   }

	return *this ;
}

/*******************************************************************
* Function Name: ~Control
********************************************************************/
Control::~Control()
{
   cerrarArchivo();
}

/*******************************************************************
* Function Name: AbrirArchivo
********************************************************************/
void Control::abrirArchivo()
{
   logInfoFile = fopen("loginfo.txt", "w");
}

/*******************************************************************
* Function Name: CerrarArchivo
********************************************************************/
void Control::cerrarArchivo()
{
   fclose(logInfoFile);
}

/*******************************************************************
* Function Name: EscribirArchivoLog
********************************************************************/
void Control::escribirArchivoLog()
{
   fprintf(logInfoFile, "%s", "Cantidad de Autos con Pase: ");
   fprintf(logInfoFile, "%i\n", (int) cantAutosPase);

   fprintf(logInfoFile, "%s", "Cantidad de Autos con Monedas: ");
   fprintf(logInfoFile, "%i\n", (int) cantAutosMonedas);

   fprintf(logInfoFile, "%s", "Tiempo Promedio de Demora de Autos con Monedas: ");
   fprintf(logInfoFile, "%f\n", (sumaDemoras.asMsecs() / cantAutosMonedas) * 1000);

   fprintf(logInfoFile, "%s", "Cantidad de Autos Multados: ");
   fprintf(logInfoFile, "%i\n\n", (int) cantMultados);
}

