#include <SPI.h>
#include <MFRC522.h>
#include "DFRobotDFPlayerMini.h"

#define SS_PIN 5
#define RST_PIN 4

#define RXD2 16   // ESP32 RX2 <- DFPlayer TX
#define TXD2 17   // ESP32 TX2 -> DFPlayer RX

MFRC522 mfrc522(SS_PIN, RST_PIN);
DFRobotDFPlayerMini player;

// RFID Card UIDs
String cardIDS[] = {
  "43 E2 B9 E4",  // Plays 0001.mp3
  "7E C7 7D C4",  // Plays 0002.mp3
  "0E 19 A6 C4",  // Plays 0003.mp3
  "24 22 93 A7"   // Plays 0004.mp3
};

int len = sizeof(cardIDS) / sizeof(cardIDS[0]);

void setup() {

  Serial.begin(9600);

  // RFID Initialization
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("RFID Reader Ready");

  // DFPlayer Initialization
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  Serial.print("Initializing DFPlayer Mini");

  while (!player.begin(Serial2)) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nDFPlayer Mini Ready");

  player.volume(30);   // Maximum Volume

  Serial.println("SmartTunes Ready!");
}

void loop() {

  // Wait for RFID Card
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("\nUID tag :");

  String content = "";

  for (byte i = 0; i < mfrc522.uid.size; i++) {

    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);

    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();

  Serial.println();

  bool matched = false;

  for (int i = 0; i < len; i++) {

    if (content.substring(1) == cardIDS[i]) {

      Serial.print("Matched! Playing Track ");
      Serial.println(i + 1);

      player.play(i + 1);

      matched = true;
      break;
    }
  }

  if (!matched) {
    Serial.println("Card Not Registered!");
  }

  delay(2000);
}