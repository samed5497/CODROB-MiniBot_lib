#include <MINIBOT.h> // 📌 MINIBOT Kütüphanesi / MINIBOT Library

MINIBOT minibot; // 📌 MINIBOT Nesnesi / MINIBOT Object

// 📡 WiFi Settings | 📡 WiFi Ayarları
#define WIFI_SSID "WIFI_SSID" // Enter the name of the Wi-Fi network you want to connect to here. | Buraya bağlanmak istediğiniz Wi-Fi ağının adını yazınız.
#define WIFI_PASS "WiFi_PASS" // Enter the password of the Wi-Fi network you want to connect to here. | Buraya bağlanmak istediğiniz Wi-Fi ağının şifresini yazınız.

// 📌 **Erişim Noktası (AP) Modu İçin Wi-Fi Bilgileri**
#define AP_SSID "CODROB Server" // 📌 AP Modu için SSID / AP Mode SSID
#define AP_PASS "12345678"      // 📌 AP Modu için Şifre / AP Mode Password (En az 8 karakter)

// 📌 **Web Sayfası İçeriği (HTML, CSS, JavaScript)**
// ✅ **JavaScript (Web Sayfası İçin)**
// Kullanıcı butona tıkladığında bir mesaj gösterecek.
const char WEBPageScript[] PROGMEM = R"rawliteral(
<script>
  function sayHello() {
    alert("Merhaba MINIBOT!");
  }
</script>
)rawliteral";

// ✅ **CSS (Web Sayfası Stili)**
// Web sayfasının görünümünü ayarlamak için CSS kullanıyoruz.
const char WEBPageCSS[] PROGMEM = R"rawliteral(
<style>
  body { text-align: center; font-family: Arial, sans-serif; }
  button { font-size: 20px; padding: 10px; margin: 20px; }
</style>
)rawliteral";

// ✅ **HTML (Web Sayfası İçeriği)**
// MINIBOT tarafından sunulacak HTML kodu
const char WEBPageHTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="tr">
<head>
  <meta charset="UTF-8">
  <title>MINIBOT Web Server</title>
  %s <!-- CSS Dosyası Buraya Eklenir -->
  %s <!-- JavaScript Dosyası Buraya Eklenir -->
</head>
<body>
  <h1>MINIBOT Web Sayfası</h1>
  <button onclick="sayHello()">Tıklayın</button>
</body>
</html>
)rawliteral";

// 📌 **Kurulum Fonksiyonu (Setup)**
void setup()
{
  // 📌 **Seri Haberleşmeyi Başlat / Start Serial Communication**
  minibot.serialStart(115200);

  // 📌 **STA veya AP Modunda Bağlantı Kur**
  minibot.serverStart("STA", WIFI_SSID, WIFI_PASS);

  // 📌 **Eğer STA bağlantısı başarısız olursa AP moduna geç**
  if (!minibot.wifiConnectionControl())
  {
    minibot.serverStart("AP", AP_SSID, AP_PASS);
  }

  // 📌 **MINIBOT Üzerinde Web Sayfasını Yayınla**
  minibot.serverCreateLocalPage("demopage", WEBPageScript, WEBPageCSS, WEBPageHTML); // Cihaza Bağlanın ve linke gidin: 192.168.4.1/demo / Connect to device and goto link: 192.168.4.1/demo
}

// 📌 **Ana Döngü (Loop)**
void loop()
{
  minibot.serverContinue(); // 📌 **AP modunda DNS yönlendirmeyi sürdür**
}
