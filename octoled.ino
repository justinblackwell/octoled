#include <Wire.h>
#include <FastLED.h>

#define LED_TYPE WS2812 // type of LED circuit

// unique to LED spec (I think)
#define COLOR_ORDER GRB

// rings on the costume 
#define NUM_RINGS 32

// leds in each ring
#define NUM_LEDS_PER_RING 6

// needed by some FastLed functions(?)
#define NUM_LEDS NUM_RINGS * NUM_LEDS_PER_RING

// number of pins to which strips are connected
#define NUM_PINS 8

// visual vars
#define FADE_RATE 250
#define BRIGHTNESS 80
#define FRAMES_PER_SECOND 128
#define RING_PIN_1 3
#define RING_PIN_2 4

// holder for all leds
CRGB leds[NUM_RINGS * NUM_LEDS_PER_RING];

// array of rings
CRGBArray<NUM_LEDS_PER_RING> rings[NUM_RINGS];

int lit_stack[NUM_RINGS];

int ring_pins[NUM_PINS] = {
  3,
  4,
  5,
  6
};

// pins to ring map 
int ring_map[NUM_PINS][2] = {
  {
    0, 7
  },
  {
    8, 15
  },
  {
    16, 23
  },
  {
    24, 31
  }
};

void setup()
{
  
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(rings[0], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(rings[1], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(rings[2], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 3, COLOR_ORDER>(rings[3], NUM_LEDS_PER_RING);

  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(rings[4], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(rings[5], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(rings[6], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 4, COLOR_ORDER>(rings[7], NUM_LEDS_PER_RING);

  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(rings[8], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(rings[9], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(rings[10], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 5, COLOR_ORDER>(rings[11], NUM_LEDS_PER_RING);

  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(rings[12], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(rings[13], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(rings[14], NUM_LEDS_PER_RING);
  FastLED.addLeds<LED_TYPE, 6, COLOR_ORDER>(rings[15], NUM_LEDS_PER_RING);

//  for(int ring_pin = 0 ; ring_pin < NUM_PINS ; ring_pin++)
//  {
//    for(int ring_number = ring_map[ring_pin][0] ; ring_number <= ring_map[ring_pin][1] ; ring_number++)
//    {
//      // cannot use expression in constant expression
//      FastLED.addLeds<LED_TYPE, ring_pins[ring_pin], COLOR_ORDER>(rings[ring_number], NUM_LEDS_PER_RING);
//    }
//  }

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  // power mgmt
  set_max_power_in_volts_and_milliamps(5, 500);
  
//  for(int x = 0 ; x < NUM_RINGS ; x++)
//  {
//    for(int y = 0 ; y < NUM_LEDS_PER_RING ; y++)
//    {
//      rings[x][y] = leds[x * NUM_LEDS_PER_RING + y];
//    }
//  }

}

void loop()
{
  // put your main code here, to run repeatedly:
    EVERY_N_MILLISECONDS( 1000/FRAMES_PER_SECOND ) {  } // slowly cycle the "base color" through the rainbow
}

void strobeRing(uint8_t ringNumber)
{
  rings[ringNumber].fill_solid(CRGB::DarkTurquoise);
  FastLED.delay(FADE_RATE);
  rings[ringNumber].fadeToBlackBy(FADE_RATE);
}
