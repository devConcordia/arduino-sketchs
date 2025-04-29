/**
 * teclado de membrana com piezo-eletronico
 * 
 * mini-teclado de notas musicais
 * 
 */

#define PIEZO 12

int lines[] = { 4, 5, 6, 7 };
int columns[] = { 8, 9, 10, 11 };

int keys[4][4] = {
  { 0, 246, 233, 220 },
  { 0, 207, 196, 185 },
  { 0, 174, 164, 155 },
  { 0, 146, 138, 130 }
};

int readKey() {

  int i, j;
  
  for( i = 0; i < 4; i++ ) {

    digitalWrite( columns[i], LOW );

    for( j = 0; j < 4; j++ ) {

      if( digitalRead( lines[j] ) == LOW ) {
  
          digitalWrite( columns[i], HIGH );

          return keys[i][j];
          
      }
    
    }
    
    digitalWrite( columns[i], HIGH );

  }

  return 0;
  
}

void setup() {

//  Serial.begin(57600);

	pinMode( PIEZO, OUTPUT );

	for( int i = 0; i < 4; i++ ) {

		pinMode( lines[i], INPUT_PULLUP );
		pinMode( columns[i], OUTPUT );

		digitalWrite( columns[i], HIGH );

	}
  
}

int last = 0;

void loop() {

	int f = readKey();

	if( f == 0 ) {

		noTone( PIEZO );

	} else {

		tone( PIEZO, f );

	}

	last = f;

}
