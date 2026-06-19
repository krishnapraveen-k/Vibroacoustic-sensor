
#include <WiFiNINA.h>

void init_network(void);

char ssid[] = "NOWTVPF1ZK";                // your network SSID (name), NOWTVPF1ZK, GalaxyS228EE4
char pass[] = "iuWqycGfqbkJ";                // your network password (use for WPA, or use as key for WEP), iuWqycGfqbkJ, zyqo9657
//======================================================================= WIFI
int packetSize; //received udp packet size
char packetBuffer[256]; //buffer to hold incoming packet
char *strings[3]; // an array of pointers to the pieces of the above array after strtok()
char *ptr = NULL;
int status = WL_IDLE_STATUS;             // the Wi-Fi radio's status
int a=0;
unsigned int average1 = 0;
unsigned int average2 = 0;


char pc_ip[] = "192.168.0.15";         //192.168.96.55, 192.168.0.15
unsigned int localPort = 4000;
//IPAddress ip;
WiFiUDP Udp;
unsigned char  ReplyBuffer[10];
//=======================================================================
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  init_network();
}

void loop() 
{
  // put your main code here, to run repeatedly:
  unsigned int sensor1 = analogRead(A0);
  unsigned int sensor2 = analogRead(A1);
  Serial.println(sensor1);

  ReplyBuffer[0] = sensor1;
  ReplyBuffer[1] = sensor1 >> 8;
  ReplyBuffer[4] = sensor2;
  ReplyBuffer[5] = sensor2 >> 8;
  
  delay(5);
  
  if (a<50)
  {
    average1 = average1 + sensor1;
    average2 = average2 + sensor2;
    a = a+1;
  }
  else if(a==50)
  {
    average1 = average1/50;
    average2 = average2/50;
    a=a+1;
  }
  else
  {
    ReplyBuffer[2] = average1;
    ReplyBuffer[3] = average1 >> 8;
    ReplyBuffer[6] = average2;
    ReplyBuffer[7] = average2 >> 8;
    
    Udp.beginPacket(pc_ip, 4001);
    Udp.write(ReplyBuffer,10);
    Udp.endPacket();  
  }

}


void init_network(void)// Wifi function block
{
// attempt to connect to Wi-Fi network:
  while (status != WL_CONNECTED) 
  {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
  Serial.println("---------------------------------------");


  delay(1000);
      Serial.println("Board Information:");
    // print your board's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    // print your network's SSID:
    Serial.println();
    Serial.println("Network Information:");
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.println(rssi);
    Serial.println("---------------------------------------");

    Udp.begin(localPort);     // local port = 4000

}

