
/// Joystick com botão de pressão
/// 
///         o
///   ↓  ↓  ↓  ↓  ↓
///  GND 5v x  y  botão (pino-digital)
///         ↓  ↓
///        pino-analogico
///
/// Os pinos x e y realizam leituras entre 0 e 1023
/// Porem o valor inicial pode não ser zero, por isso
/// é preciso realizar uma leitura inicial (default x e y)

#define PIN_X A0
#define PIN_Y A1

#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11

int default_x = 0;
int default_y = 0;

void setup() {

	Serial.begin(57600);

	///
	pinMode( PIN_X, INPUT );
	pinMode( PIN_Y, INPUT );

	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);

	///
	default_x = analogRead( PIN_X );
	default_y = analogRead( PIN_Y );

}

void loop() {
  
	float x = (analogRead(PIN_X) - default_x) / 5.0;
	float y = (analogRead(PIN_Y) - default_y) / 5.0;
	
// 	Serial.print(x);
// 	Serial.print('\t');
// 	Serial.print(y);
// 	Serial.print('\n');
// 	delay(1000);
	
	digitalWrite( LED1, ( x < -90.0 )? HIGH : LOW );
	digitalWrite( LED2, ( y < -80.0 )? HIGH : LOW );
	digitalWrite( LED3, ( x >  90.0 )? HIGH : LOW );
	digitalWrite( LED4, ( y >  80.0 )? HIGH : LOW );
	
}
