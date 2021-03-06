/*
 NodeMCU Blink test by Narsimulu Cinasi
 Blink the blue LED on the NodeMCU module
 This example code is in the public domain
 
 The blue LED on the NODEMCU module is connected to GPIO1 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
 Copyrighted to Tekcircuits R&D Lab
*/

void setup() {
  pinMode(16 , OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(16, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  delay(1000);                      // Wait for a second
  digitalWrite(16, HIGH);  // Turn the LED off by making the voltage HIGH
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
