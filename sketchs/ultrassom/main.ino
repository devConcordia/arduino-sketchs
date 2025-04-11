
/// HC SRO4 - Sensor de distancia por ultassom
/// 
/// Quando disparado , emite uma rajada de pulso 
/// por ultrassom e detecta o eco dos pulsos.
/// Pelo tempo que o eco demora para voltar é
/// possivel calcular a distancia

/// Pinagem
/// 
///  O       O
///   ↓ ↓ ↓ ↓
///  5v ↓ ↓ GND
///     / \
///   OUT  IN
///  TRIG  ECHO

/// Disparo
/// 
/// No Setup coloque o pino Trigem nivel baixo (0).
/// Para disparar o Trig em nivel alto
/// por 10 microsegundos em seguida em nivel baixo 
/// por 2 microssegundos e em novel alto por 10 ms novamente.
/// 
/// Quando voltar para o nivel baixo sera feito os disparo.
/// Use
///   pulseIn(pino, HIGHT)
/// para retornar o tempo (em microssegundos)

#define PIN_TRIG 11
#define PIN_ECHO 10

void setup() {
	
	Serial.begin(57600);
	
	pinMode( PIN_TRIG, OUTPUT );
	pinMode( PIN_ECHO, INPUT );

	digitalWrite(PIN_TRIG,LOW);
	
}

void loop() {

	digitalWrite( PIN_TRIG, HIGH );
	delayMicroseconds( 10 );
	
	digitalWrite( PIN_TRIG, LOW );
	
	///
	unsigned long tempo = pulseIn( PIN_ECHO, HIGH );
	unsigned long dist = 17 * tempo / 1000;
	
	Serial.print( dist );
	Serial.print('\n');
	
	delay( 1000 );
  
}

