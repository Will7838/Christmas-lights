#include <FastLED.h>
#define NUM_LEDS 301
#define DATA_PIN 11
CRGB leds[NUM_LEDS];
int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int H = 9;
int I = 10;
int J = 22;
int K = 23;
int L = 24;
int M = 25;
int N = 26;



int i = 0;
int incomingByte[12];

void setup()
{
  Serial.begin(1048576);

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  pinMode(I, OUTPUT);
  pinMode(J, OUTPUT);
  pinMode(K, OUTPUT);
  pinMode(L, OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(N, OUTPUT);
}

void loop() {
int cnt;
  unsigned int num_leds;
  unsigned int d1, d2, d3;

 for(;;) {
    // Set a counter to 0.  This couter keeps track of the pixel colors received.
    cnt = 0;
    //Begin waiting for the header to be received on the serial bus
    //1st character
    while(!Serial.available());
      if(Serial.read() != '>') {
        continue;
        }
    //second character
    while(!Serial.available());
      if(Serial.read() != '>') {
        continue;
        }
    //get the first digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d1 = Serial.read();
    //get the second digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d2 = Serial.read();
    //get the third digit from the serial bus for the number of pixels to be used
    while(!Serial.available());
      d3 = Serial.read();
    //get the end of the header
    while(!Serial.available());
      if(Serial.read() != '<') {
        continue;
        }
    while(!Serial.available());
      if(Serial.read() != '<') {
        continue;
        }
    // calculate the number of pixels based on the characters provided in the header digits
    num_leds = (d1-'0')*100+(d2-'0')*10+(d3-'0');
    // ensure the number of pixels does not exceed the number allowed
    if(num_leds > NUM_LEDS) {
      continue;
      }
    // Let the FastLED library know how many pixels we will be addressing
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, num_leds);
    // Loop through each of the pixels and read the values for each color
    do {
      while(!Serial.available());
        leds[cnt].r = Serial.read();
      while(!Serial.available());
        leds[cnt].g = Serial.read();
      while(!Serial.available());
        leds[cnt++].b = Serial.read();
      } 
    while(--num_leds);
    // Tell the FastLED Library it is time to update the strip of pixels
    FastLED.show();
  
  if (Serial.available() >= 12)
  {
    for (int i=0; i<12;i++)
    {
      incomingByte[i] = Serial.read();
    }
    analogWrite(A, incomingByte[0]);  // Pin 2
    analogWrite(B, incomingByte[1]);  // Pin 3
    analogWrite(C, incomingByte[2]);  // Pin 4
    analogWrite(D, incomingByte[3]);  // Pin 5
    analogWrite(E, incomingByte[4]);  // Pin 6
    analogWrite(F, incomingByte[5]);  // Pin 7
    analogWrite(G, incomingByte[6]);  // Pin 8
    analogWrite(H, incomingByte[7]);  // Pin 9
    analogWrite(I, incomingByte[8]);  // Pin 10
    analogWrite(J, incomingByte[9]);  // Pin 11
    analogWrite(K, incomingByte[10]); // Pin 12
    analogWrite(L, incomingByte[11]); // Pin 13
  }

  }
}


        
