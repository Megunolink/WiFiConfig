/* ******************************************************
* WiFiConfig.h
* Define credentials used for connecting to local network
* services. Typically only used for testing & prototyping
*
* More information: 
* https://www.megunolink.com/articles/wireless/how-do-i-connect-to-a-wireless-network-with-the-esp32/
*
* CAUTION:
* WiFi connection information is stored in plain-text
* here and in any Arduino sketch that uses this. Anyone
* with access to this file or the Arduino device using 
* it could find out your WiFi password!
* ****************************************************** */
const char *SSID = "Your SSID";
const char *WiFiPassword = "Your Password";