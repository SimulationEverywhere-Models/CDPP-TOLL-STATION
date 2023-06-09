/*******************************************************************
*
*  DESCRIPTION: Atomic Model Sensor
*
*******************************************************************/

#ifndef __SENSOR_H
#define __SENSOR_H

#include "atomic.h"     // class Atomic

class Sensor : public Atomic
{
public:
	Sensor( const string &name = "Sensor" );	//Default constructor

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

};	// class Sensor

inline
string Sensor::className() const
{
	return "Sensor" ;
}

#endif   //__SENSOR_H
