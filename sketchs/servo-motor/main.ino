/// Servo Motor
/// 
/// Usado para posicionar uma carga 
/// em um angulo especifico. O modelo
/// fornecido consegue girar 180 e
/// suporta até 1kg de carga.
///
/// Pinagem
/// 
/// GND - 5v - Digital
///

///
///	O exemplo a seguir é uma junção do servo motor com ultrassom
///	Quando a distancia medida for pequena, o servo rotaciona ao final, por 5s
///	
///	
///	

#include <Servo.h>

#define PIN_SERVO 10

#define PIN_TRIG 7
#define PIN_ECO 6

Servo sv;

/// Servo *sv;  sv = new Servo();

void setup() {

	//Serial.begin(57600);
	
	pinMode( PIN_TRIG, OUTPUT );
	pinMode( PIN_ECHO, INPUT );

	digitalWrite( PIN_TRIG, LOW );

	sv.attach( PIN_SERVO );
	sv.write(0);
	delay(1000);
	
}

void loop() {

	digitalWrite( PIN_TRIG, HIGH );
	delayMicroseconds(10);
	
	digitalWrite( PIN_TRIG, LOW );

	//calculo
	unsigned long tempo = pulseIn( PIN_ECHO, HIGH );
	unsigned long dist = 17 * tempo / 1000;
	
	// Serial.print(dist);
	// Serial.print('\n');
	
	if( dist < 100 ) {
		
		sv.write(90);
		delay(5000);
		
		sv.write(0);
		
	}
	
	delay(1000);
	
}
