/*******************************************************************
*
*  DESCRIPTION: Atomic Model Cajero
*
*******************************************************************/

/** include files **/
#include "cajero.h"      // class Cajero
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Cajero
********************************************************************/
Cajero::Cajero( const string &name ): Atomic( name )
, monedas( addInputPort( "monedas" ) )
, detectoPase( addInputPort( "detectoPase" ) )
, yaSalio( addInputPort( "yaSalio" ) )
, devolver( addOutputPort( "devolver" ) )
, pago( addOutputPort( "pago" ) )
, multar( addOutputPort( "multar" ) )
, pagoTime( 0, 0, 0, 0 )
, devolviendoTime( 0, 0, 0, 0 )
, pagandoTime( 0, 1, 0, 0 )
{
   cantMonedas5 = (int) str2Value(MainSimulator::Instance().getParameter( description(), "cantMonedas5")) ;
   cantMonedas10 = (int) str2Value(MainSimulator::Instance().getParameter( description(), "cantMonedas10")) ;
   cantMonedas50 = (int) str2Value(MainSimulator::Instance().getParameter( description(), "cantMonedas50")) ;
   cantMonedas100 = (int) str2Value(MainSimulator::Instance().getParameter( description(), "cantMonedas100")) ;
   costoPeaje = (float) str2Value(MainSimulator::Instance().getParameter( description(), "costoPeaje")) ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &Cajero::initFunction()
{
   modo = ESPERANDO;
   plataPagada = 0;
   vuelto = 0;
   ultimaMoneda = 0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
********************************************************************/
Model &Cajero::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == monedas )
	{
      if ((modo == ESPERANDO) || (modo == PAGANDO) || (modo == PAGO))
      {
         if (msg.value() == 0.05)
            cantMonedas5 += 1;

         if (msg.value() == 0.10)
            cantMonedas10 += 1;

         if (msg.value() == 0.50)
            cantMonedas50 += 1;

         if (msg.value() == 1.00)
            cantMonedas100 += 1;

         tipoPago = MONEDAS;
      }

      if (modo == ESPERANDO)
      {
         plataPagada += msg.value();

         if (plataPagada == costoPeaje)
         {
            modo = PAGO;
            plataPagada = 0;
            holdIn( active, pagoTime);
         }
         else
         {
            if (plataPagada > costoPeaje)
            {
               modo = DEVOLVIENDO;
               vuelto = plataPagada - costoPeaje;
               plataPagada = 0;

               if (noHayParaDarVuelto())
                  ultimaMoneda = msg.value();

               holdIn( active, devolviendoTime);
            }
            else
            {
               modo = PAGANDO;
               holdIn( active, pagandoTime);
            }
         }
      }

      if (modo == PAGANDO)
      {
         plataPagada += msg.value();

         if (plataPagada == costoPeaje)
         {
            modo = PAGO;
            plataPagada = 0;
            holdIn( active, pagoTime);
         }
         else
         {
            if (plataPagada > costoPeaje)
            {
               modo = DEVOLVIENDO;
               vuelto = plataPagada - costoPeaje;
               plataPagada = 0;

               if (noHayParaDarVuelto())
                  ultimaMoneda = msg.value();

               holdIn( active, devolviendoTime);
            }
            else
            {
               modo = PAGANDO;
               holdIn( active, nextChange());
            }
         }
      }

      if (modo == PAGO)
      {
         ultimaMoneda = msg.value();
         modo = DEVOLVIENDO;
         holdIn( active, devolviendoTime);
      }
 	}

	if( msg.port() == detectoPase )
   {
      if (modo == ESPERANDO)
      {
         modo = PAGO;
         tipoPago = PASE;
         holdIn( active, pagoTime);
      }
   }

	if( msg.port() == yaSalio )
   {
      if (modo == PAGO)
      {
         modo = ESPERANDO;
         passivate();
      }
   }

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
********************************************************************/
Model &Cajero::internalFunction( const InternalMessage & )
{
   if (modo == DEVOLVIENDO)
   {
      if (ultimaMoneda == 0)
      {
         if (tengoMonedaQueCancelaVuelto())
         {
            modo = PAGO;
            holdIn( active, pagoTime);
         }
         else
            holdIn( active, devolviendoTime);
      }
      else
      {
         modo = PAGO;
         holdIn( active, pagoTime);
      }
   }

   if (modo == PAGANDO)
   {
      plataPagada = 0;
      modo = ESPERANDO;
      passivate();
   }                  

   if (modo == PAGO)
   {
      modo = ESPERANDO;
      passivate();
   }                  

	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
********************************************************************/
Model &Cajero::outputFunction( const InternalMessage &msg )
{
float monedaVuelto;

   if (modo == PAGO)
   {
	   sendOutput(msg.time(), pago, tipoPago) ;
   }

   if (modo == DEVOLVIENDO)
   {
      if (ultimaMoneda == 0)
      {
         monedaVuelto = mayorMonedaEnStockMenorQueVuelto();
	      sendOutput(msg.time(), devolver, monedaVuelto);
         vuelto -= monedaVuelto;

         if (monedaVuelto == 0.05)
            cantMonedas5 -= 1;

         if (monedaVuelto == 0.10)
            cantMonedas10 -= 1;

         if (monedaVuelto == 0.50)
            cantMonedas50 -= 1;

         if (monedaVuelto == 1.00)
            cantMonedas100 -= 1;
      }
      else
      {
	      sendOutput(msg.time(), devolver, ultimaMoneda);

         if (ultimaMoneda == 0.05)
            cantMonedas5 -= 1;

         if (ultimaMoneda == 0.10)
            cantMonedas10 -= 1;

         if (ultimaMoneda == 0.50)
            cantMonedas50 -= 1;

         if (ultimaMoneda == 1.00)
            cantMonedas100 -= 1;

         ultimaMoneda = 0;
         vuelto = 0;
      }
   }

   if (modo == PAGANDO)
   {
	   sendOutput(msg.time(), multar, 0) ;
   }

	return *this ;
}

/*******************************************************************
* Function Name: NoHayParaDarVuelto
********************************************************************/
int Cajero::noHayParaDarVuelto()
{
int auxMonedas5 = cantMonedas5;
int auxMonedas10 = cantMonedas10;
int auxMonedas50 = cantMonedas50;
int auxMonedas100 = cantMonedas100;
float auxVuelto = vuelto;
int seguir = 1;

   while ((auxVuelto > 0) && seguir)
   {
      if ((auxVuelto >= 1) && (auxMonedas100 > 0))
      {
         auxMonedas100 -= 1;
         auxVuelto -= 1;
         continue;
      }

      if ((auxVuelto >= 0.5) && (auxMonedas50 > 0))
      {
         auxMonedas50 -= 1;
         auxVuelto -= 0.5;
         continue;
      }

      if ((auxVuelto >= 0.1) && (auxMonedas10 > 0))
      {
         auxMonedas10 -= 1;
         auxVuelto -= 0.1;
         continue;
      }

      if ((auxVuelto >= 0.05) && (auxMonedas5 > 0))
      {
         auxMonedas5 -= 1;
         auxVuelto -= 0.05;
         continue;
      }

      seguir = 0;
   }

   return seguir;
}

/*******************************************************************
* Function Name: TengoMonedaQueCancelaVuelto
********************************************************************/
int Cajero::tengoMonedaQueCancelaVuelto()
{
   if ((vuelto == 1) && (cantMonedas100 > 0))
      return 0;

   if ((vuelto == 0.5) && (cantMonedas50 > 0))
      return 0;

   if ((vuelto == 0.1) && (cantMonedas10 > 0))
      return 0;

   if ((vuelto == 0.05) && (cantMonedas5 > 0))
      return 0;

   return 1;
}

/*******************************************************************
* Function Name: MayorMonedaEnStockMenorQueVuelto
********************************************************************/
float Cajero::mayorMonedaEnStockMenorQueVuelto()
{
   if ((vuelto > 1) && (cantMonedas100 > 0))
      return 1;

   if ((vuelto > 0.5) && (cantMonedas50 > 0))
      return 0.5;

   if ((vuelto > 0.1) && (cantMonedas10 > 0))
      return 0.1;

   if ((vuelto > 0.05) && (cantMonedas5 > 0))
      return 0.05;

   return 0;
}

