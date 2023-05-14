# MegunoLink WiFi configuration Arduino library

This very simple library (it contains only one header file!) provides a handy store for WiFi credentials. Simply: 

1. enter your WiFi network SSID and password into [`WiFiConfig\src\WiFiConfig.h`](https://github.com/Megunolink/WiFiConfig/blob/master/src/WiFiConfig.h), and
2. `#include "WiFiConfig.h"` at the top of your sketch.

This makes two global variables available to your sketch for easily [creating wireless connections](https://www.megunolink.com/articles/wireless/how-do-i-connect-to-a-wireless-network-with-the-esp32/) in examples and during prototyping without the risk of accidentally committing the credentials to git or similar. For example, while prototyping with Espressif's [ESP32](https://www.espressif.com/en/products/hardware/esp32/overview) connecting to a wireless network becomes as simple as:

```c++
#include "WiFi.h" // ESP32 WiFi include
#include "WiFiConfig.h" // My WiFi configuration.

void ConnectToWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, WiFiPassword);
  Serial.print("Connecting to "); Serial.println(SSID);

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(500);

    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }

  Serial.print(F("Connected. My IP address is: "));
  Serial.println(WiFi.localIP());
}
```

Of course, the header does store your credentials in plain text, so make sure:

* no nefarious evil-doers have access to your computer to discover your wireless secrets!
* you don't upload the library to a public repository!

