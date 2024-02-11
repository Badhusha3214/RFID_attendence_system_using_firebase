#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <SPI.h>
#include <MFRC522.h>

#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

//add wifi crad
#define WIFI_SSID "master"
#define WIFI_PASSWORD "123456789"

/* 2. Define the API Key */
#define API_KEY "AIzaSyDJrOa2wrg88LkDxxhk02XCBZviWVMuWrQ"

/* 3. Define the RTDB URL */
#define DATABASE_URL "let-me-in-cfd1b-default-rtdb.asia-southeast1.firebasedatabase.app" 

??add mail id and password as given in the firebase
#define USER_EMAIL "inovustv@gmail.com"
#define USER_PASSWORD "inovuslabs"

#define SS_PIN 21
#define RST_PIN 5
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the RFID
 
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;

char str[32] = "";

String uid;

String a[200];
int m;
int n = 1;

void setup()
{
  Serial.begin(115200);
  SPI.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback; 

  Firebase.reconnectNetwork(true);
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);

  SPI.begin();      
  rfid.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}

void loop()
{
      if (Firebase.ready() && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
      FirebaseJson json;
  for(int i =0; i < 10-1; i++){ // checking of multiple values and deleteing it
    if(a[i] != ""){
      for(int j =i+1; j < 10; j++){
        
          if(a[i] == a[j]){
          a[j] = "";
          Serial.print("deleted");
          json.add(String(j), "" );
        Serial.printf("Update node %s\n", Firebase.updateNode(fbdo, F("/test/json/round"), json) ? "ok" : fbdo.errorReason().c_str());

      }
      } 
     }
    }
if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      uid.concat(String(rfid.uid.uidByte[i] < 0x10 ? "0" : ""));
      uid.concat(String(rfid.uid.uidByte[i], HEX));
    }
    uid.toUpperCase(); // Make the UID uppercase

    Serial.print("UID Tag: ");
    Serial.println(uid);

      n =1;
    while(n <= 10){
      if(a[n] == uid){  // chaeck to delete exisiting id
        a[n] = "";
        json.add(String(n), "" );
        Serial.printf("Update node %s\n", Firebase.updateNode(fbdo, F("/test/json/round"), json) ? "ok" : fbdo.errorReason().c_str());
        Serial.print("array clear");
        uid = "";
        delay(100);
        break;
      }
      else{  //add new id
        if(a[n] == "" && uid != ""){
          a[n] = uid;
          m = n;
          json.add(String(m), String(uid) );
          Serial.printf("Update node %s\n", Firebase.updateNode(fbdo, F("/test/json/round"), json) ? "ok" : fbdo.errorReason().c_str());
          Serial.print("new tag entered");
          uid = "";
          delay(10);
          break;
        }
        
        }
        
      n++;
      delay(100);
    }
    // ------
    }
    

  }
  delay(10);
  
  
}

