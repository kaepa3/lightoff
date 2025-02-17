
class CheckPin {
  public:
    CheckPin(int pin);
    bool IsOn();
  private:
    int _pin;
    int _before;
};

CheckPin::CheckPin(int pin) {
  _pin = pin;
  pinMode(_pin, INPUT);
}
bool CheckPin::IsOn() {
  bool val = digitalRead(_pin) == HIGH;
  bool isChange = val != _before;
  _before = val;
  return val&&isChange;
}

CheckPin gpio(5);

#define LED_BUILTIN 8
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("init end");
}

void loop() {
  delay(1000);
  if (gpio.IsOn()) {
    Serial.println("GPIO 13 is on");
    digitalWrite(LED_BUILTIN, HIGH);
  } else{
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("GPIO 13 is off");
  }
}


