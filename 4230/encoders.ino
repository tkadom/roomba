/* Encoder is on pin 2, since it accepts interrupts */
/* Roomba motor wires for my 4230 series. (On my model at least) :

Blue = IR Anode
Brown = IR Cathode
Black = Emitter
Gray = Detector

*/

int encoderPin = 2;  /* encoder wire from Roomba motor */
int counter;
int counting;

void setup()
{
  counter = 0;

  Serial.begin(9600);

/* Setup encoder pin as inputs */
    pinMode(encoderPin, INPUT); 

// encoder pin on interrupt 0
  attachInterrupt(0, decoder, FALLING);

}

void loop()
{
//using while statement to stay in the loop for continuous
//interrupts
if (counting) // CW motion in the rotary encoder
{
  counting = 0;
  counter++;
  Serial.println(counter);
}

}

void decoder()
// should trigger on Falling value of encoder Port
{
  counting = 1;
}
