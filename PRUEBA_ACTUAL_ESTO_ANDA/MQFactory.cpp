#include "MQFactory.h"
#include "MQ7.h"
#include "MQ9.h"
#include "MQ131.h"
#include "MQ135.h"
#include "Ecuation.h"
#include <arduino.h>

MQFactory::MQFactory(double _actualTemp, double _actualHum)
{
	actualTemp = _actualTemp;
	actualHum = _actualHum;
	timeElapsed = false;
}

MQFactory::~MQFactory() {}

IMQ* MQFactory::createMQ(int sensor, int MqPin)
{
	if(timeElapsed == false)
	{
		delay(600);
		timeElapsed = true;
	}
	else if(timeElapsed == true);
	IMQ* sensora;
	switch(sensor)
	{
		case Mq7:
		sensora = new MQ7(MqPin);
		sensora->setTempYHumValues(actualTemp, actualHum);
		sensora->setRo(3525);
		break;
		case Mq9:
		sensora = new MQ9(MqPin);
		sensora->setTempYHumValues(actualTemp, actualHum);
		sensora->setRo(86);
		break;
		case Mq131:
		sensora = new MQ131(MqPin);
		sensora->setTempYHumValues(actualTemp, actualHum);
		sensora->setRo(10571195);
		break;
		case Mq135:
		sensora = new MQ135(MqPin);
		sensora->setTempYHumValues(actualTemp, actualHum);
		sensora->setRo(50800);
		break;
		default:
		sensora = 0;
		break;
	}
	return sensora;
}
