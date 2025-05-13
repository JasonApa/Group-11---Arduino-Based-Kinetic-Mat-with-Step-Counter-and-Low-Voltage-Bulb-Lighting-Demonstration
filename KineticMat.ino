#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C address 0x27, 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

int stepCount = 0;
int threshold = 100; 
unsigned long lastStepTime = 0;
unsigned long debounceDelay = 300; // milliseconds

unsigned long lastVoltageUpdate = 0;
unsigned long voltageUpdateInterval = 500; // update voltage every 500ms
float voltage = 0;

// Trapezoidal Rule Integration Variables
float vout = 0.0;
float prevVout = 0.0;
float energy = 0.0;
unsigned long prevEnergyTime = 0;

void setup() {
  Serial.begin(9600);

  for (byte a = 2; a <= 6; a++) {
    pinMode(a, OUTPUT);
  }

  lcd.init();         // Initialize the LCD
  lcd.backlight();    // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Steps: 0");

  prevEnergyTime = millis();  // Initialize time for energy integration
}

void loop() {
  int value = analogRead(A1);
  Serial.println(value);

  // LED bar display
  for (int a = 1; a <= 5; a++) {
    if (value > a * 20) {
      digitalWrite(a + 1, HIGH);
    } else {
      digitalWrite(a + 1, LOW);
    }
  }

  // Step detection with debounce
  if (value > threshold && (millis() - lastStepTime > debounceDelay)) {
    stepCount++;
    lastStepTime = millis();

    // Update step count on LCD
    lcd.setCursor(0, 0);
    lcd.print("Steps: ");
    lcd.print(stepCount);
    lcd.print("    "); // Clear extra digits
  }

  // Update voltage reading and compute energy every 500 ms
  if (millis() - lastVoltageUpdate >= voltageUpdateInterval) {
    lastVoltageUpdate = millis();
    vout = (value / 1023.0) * 5.0;
    voltage = vout;

    // Trapezoidal rule integration - Numerical Method Integration 
    unsigned long currentTime = millis();
    float deltaTime = (currentTime - prevEnergyTime) / 1000.0; // Time in seconds
    energy += 0.5 * (vout + prevVout) * deltaTime;
    prevVout = vout;
    prevEnergyTime = currentTime;

    // Update LCD
    lcd.setCursor(0, 1);
    lcd.print("Volt: ");
    lcd.print(voltage, 2);
    lcd.print("V "); // Clear leftover chars

    // Optional: print energy to Serial
    Serial.print("Energy: ");
    Serial.print(energy, 2);
    Serial.println(" J");
  }

  delay(50); // Short delay for stability
}
