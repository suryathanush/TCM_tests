#include <Arduino.h>
#include <MAX17048.h>
#include "BluetoothSerial.h"

MAX17048 pwr_mgmt;

BluetoothSerial SerialBT;


void setup()
{
    Serial.begin(115200);
    Wire.begin(17, 19);
    pwr_mgmt.attatch(Wire);
    SerialBT.begin("RemoteTest"); //Bluetooth device name
}

void loop()
{
    SerialBT.print("VCELL ADC : ");
    SerialBT.println(pwr_mgmt.adc());
    SerialBT.print("VCELL V   : ");
    SerialBT.println(pwr_mgmt.voltage());
    SerialBT.print("VCELL SOC : ");
    SerialBT.print(pwr_mgmt.accuratePercent());
    SerialBT.println(" \%");
    SerialBT.println();
    delay(1000);
}