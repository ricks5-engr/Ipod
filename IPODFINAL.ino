#include <HardwareSerial.h>
#include <DFRobotDFPlayerMini.h>
const int rx = 20;
const int tx = 21;
const int pp = 3;
const int skip = 4;

int paused = 0;


HardwareSerial ant(1);
DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(115200);
  ant.begin(9600, SERIAL_8N1, rx, tx);
  delay(1000);

  if (!player.begin(ant))
  {
    Serial.println("Connecting to DFPlayer Mini Failed!");
  }

player.volume(20);
player.enableLoopAll();
player.start();


pinMode(pp, INPUT_PULLUP);
pinMode(skip, INPUT_PULLUP);
}

//LOOPIN

void loop() 

{
if (paused == 0 && digitalRead(pp) == 0)
{
  player.pause();
  paused = 1;
  delay(1000);
}

if (paused == 1 && digitalRead(pp) == 0)
{
  player.start();
  paused = 0;
  delay(1000);
}

if (paused == 0 && digitalRead(skip) == 0)
{
  player.next();
  delay(1000);
}

if (paused == 1 && digitalRead(skip) == 0)
{
  player.next();
  delay(1000);
  paused = 0;
}





}