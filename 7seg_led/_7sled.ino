
void setup() {              
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, 0);  // start with the "dot" off
}

void loop() {
  
// write 'J'
 digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 delay(500);
// write 'A'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 delay(500);
// write 'Q'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 digitalWrite(9, 1);
 delay(500);
// write 'U'
 digitalWrite(2, 0);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(500);
// write 'E'
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 0);
 delay(500);

// write ''
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(500);


// write 'E'
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1500);
 digitalWrite(9, 0);
 delay(500);
 

// write ''
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(500);

 
// write 't'
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 0);
 delay(500);
// write 'h'
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 1);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 digitalWrite(9, 0);
 delay(500);
// write 'I'
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(500);
// write 'A'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 0);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 delay(500);
// write 'G'
 digitalWrite(2, 1);
 digitalWrite(3, 0);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 1);
 delay(500);
// write 'O'
 digitalWrite(2, 1);
 digitalWrite(3, 1);
 digitalWrite(4, 1);
 digitalWrite(5, 1);
 digitalWrite(6, 1);
 digitalWrite(7, 1);
 digitalWrite(8, 0);
 delay(500);

// write ''
 digitalWrite(2, 0);
 digitalWrite(3, 0);
 digitalWrite(4, 0);
 digitalWrite(5, 0);
 digitalWrite(6, 0);
 digitalWrite(7, 0);
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(1000);

}
