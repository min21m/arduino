/* Create our own reg */
uint8_t Rin;  // Range 0 to 255 or in binary 0000_0000 to 1111_1111
uint8_t Rout;
int Rout_display;

// uint8_t bshift = 3;
// uint8_t mask_shifting = 1 << bshift;  // Shifting to create the mask programmatically
uint8_t bit3_mask = 0b00001000;   // Allows changing bit 3 (manually created mask)
uint8_t bit4_mask = 0b11101111;   // Allows changing bit 4 (manually created mask)


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  Rout = 0b00000000;

}

void loop() {
  // put your main code here, to run repeatedly:
  Rout = 0b01010101; //parallel assignment -- all bits change at the same time

  // Masking allows changing one or any number of bits
  // We want to change bit 3 from LOW to HIGH (output_bit = 1 | 1;)
  Rin = Rout | bit3_mask;   // At this point Rin = 0b01011101  (Rin = 0b01010101 | 0b00001000)

  // Do an AND with Rout & bit4_mask

  Rout = Rin;
  Serial.print(Rout, BIN);    // Display, not conversion, Rout as Binary
  Serial.print(" = ");
  Serial.print(Rout, HEX);    // Display, not conversion, Rout as Hex
  Serial.print(" = ");
  Serial.println(Rout);       // Print the final information (Rout) followed by a new line (ln)

  delay(1000);
}
