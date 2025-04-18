
#define B1 8
#define B2 9
#define B3 10
#define B4 11

int count = 0;

void setup() {

	pinMode( B1, OUTPUT );
	pinMode( B2, OUTPUT );
	pinMode( B3, OUTPUT );
	pinMode( B4, OUTPUT );
	
	step( 0, 0, 0, 0 );

}

void loop() {

	if( count < 256 ){

		step(1,0,0,0);
		step(0,1,0,0);
		step(0,0,1,0);
		step(0,0,0,1);

	} else {
	  
		step(0,0,0,1);
		step(0,0,1,0);
		step(0,1,0,0);
		step(1,0,0,0);

		if( count > 512 ) count = 0;

	}

	count++;
  
}

void step( int b1, int b2, int b3, int b4 ) {
	
	digitalWrite( B1, b1 );
	digitalWrite( B2, b2 );
	digitalWrite( B3, b3 );
	digitalWrite( B4, b4 );

	delay( 10 );

}
