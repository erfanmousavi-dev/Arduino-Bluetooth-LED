# 💡 Bluetooth Controlled LED Effects

<div align="center">
  
  [**English**](#english) | [**فارسی**](#persian)
  
</div>

---

<a name="english"></a>
## 📖 Description (English)

This project is a Bluetooth-controlled LED effect generator using Arduino and an HC-05/HC-06 Bluetooth module. You can select different light patterns remotely via a smartphone app.

### Features
- **Wave Effect:** LEDs light up sequentially from left to right and back.
- **Knight Rider Effect:** LEDs sweep back and forth (like KITT from Knight Rider).
- **Pulse Effect:** All LEDs blink together 3 times.
- **Explosion Effect:** LEDs expand from the center outward, then all turn off.
- **Spiral Fast Effect:** LEDs turn on and off in sequence rapidly, repeated 3 times.
- Control via simple single-character Bluetooth commands.

### Components Required
- Arduino board (Uno, Nano, etc.)
- 10 LEDs (any color)
- 10 resistors (220Ω – 330Ω)
- HC-05 / HC-06 Bluetooth module
- Jumper wires and breadboard
- Power supply (USB or battery)

### Wiring

| Component | Arduino Pin |
|-----------|-------------|
| Bluetooth TX | Pin 2 (SoftwareSerial RX) |
| Bluetooth RX | Pin 3 (SoftwareSerial TX) |
| LED 1        | 4  |
| LED 2        | 5  |
| LED 3        | 6  |
| LED 4        | 7  |
| LED 5        | 8  |
| LED 6        | 9  |
| LED 7        | 10 |
| LED 8        | 11 |
| LED 9        | 12 |
| LED 10       | 13 |

> **Note:** All LEDs connect their anode (+) through a resistor to the Arduino pin, and cathode (-) to GND.  
> The Bluetooth module uses SoftwareSerial on pins 2 (RX) and 3 (TX) – **this is reversed compared to normal labeling** (module TX → Arduino pin 2, module RX → Arduino pin 3).

### Bluetooth Commands

| Character | Effect |
|-----------|--------|
| `a` | Wave Effect (speed: 60ms) |
| `b` | Knight Rider Effect (speed: 40ms) |
| `c` | Pulse Effect (150ms delay) |
| `d` | Explosion Effect (80ms step) |
| `e` | Spiral Fast Effect (30ms step, 3 cycles) |

### How to Use
1. **Connect** the circuit as shown above.
2. **Upload** the code to Arduino.
3. **Pair** the Bluetooth module (default password: 1234 or 0000).
4. **Install** a Bluetooth terminal app (e.g., "Arduino Bluetooth Controller" or "Serial Bluetooth Terminal").
5. **Connect** to the module and send characters `a`, `b`, `c`, `d`, or `e` to trigger different LED effects.

> **Tip:** Each effect runs once per command. To repeat an effect, send the command again.

### Code Structure
- **SoftwareSerial** on pins 2 (RX) and 3 (TX) for Bluetooth communication.
- `leds[]` array stores pins 4 through 13.
- `allOff()` turns off all LEDs.
- Each effect is a separate function: `waveEffect()`, `knightRider()`, `pulseEffect()`, `explosionEffect()`, `spiralFast()`.
- In `loop()`, when a character is received, the corresponding effect runs.

### Customization
- **Change speed:** Modify the delay parameter in each effect function (e.g., `waveEffect(60)`).
- **Add more effects:** Create your own function and map it to a new character.
- **Change number of LEDs:** Adjust `ledCount` and the `leds[]` array.

### License
MIT License – free to use, modify, and distribute.

---

<a name="persian"></a>
## 📖 توضیحات (فارسی)

این پروژه یک افکت‌ساز LED است که با استفاده از Arduino و ماژول بلوتوث HC-05/HC-06 کنترل می‌شود. با ارسال دستورات ساده از طریق اپلیکیشن موبایل، می‌توانید الگوهای نوری مختلف را اجرا کنید.

### امکانات
- **افکت موج (Wave):** LEDها به ترتیب از چپ به راست و بالعکس روشن می‌شوند.
- **افکت نایت رایدر (Knight Rider):** LEDها به صورت رفت و برگشت (مانند ماشین نایت رایدر) حرکت می‌کنند.
- **افکت ضربان (Pulse):** همه LEDها سه بار همزمان چشمک می‌زنند.
- **افکت انفجار (Explosion):** LEDها از مرکز به سمت بیرون روشن می‌شوند، سپس همه خاموش می‌گردند.
- **افکت مارپیچ سریع (Spiral Fast):** LEDها به ترتیب و با سرعت بالا روشن و خاموش می‌شوند (۳ دور).
- کنترل با دستورات تک کاراکتری از طریق بلوتوث.

### قطعات مورد نیاز
- برد Arduino (Uno، Nano یا مشابه)
- ۱۰ عدد LED (هر رنگی)
- ۱۰ عدد مقاومت ۲۲۰ تا ۳۳۰ اهم
- ماژول بلوتوث HC-05 یا HC-06
- برد بورد و سیم جامپر
- منبع تغذیه (USB یا باتری)

### اتصالات

| قطعه | پین آردوینو |
|------|--------------|
| TX بلوتوث | پین 2 (RX نرم‌افزاری) |
| RX بلوتوث | پین 3 (TX نرم‌افزاری) |
| LED 1 | 4  |
| LED 2 | 5  |
| LED 3 | 6  |
| LED 4 | 7  |
| LED 5 | 8  |
| LED 6 | 9  |
| LED 7 | 10 |
| LED 8 | 11 |
| LED 9 | 12 |
| LED 10| 13 |

> **نکته:** آند (+) هر LED از طریق یک مقاومت به پین آردوینو و کاتد (-) به GND متصل می‌شود.  
> ماژول بلوتوث با SoftwareSerial روی پین‌های 2 (RX) و 3 (TX) کار می‌کند – **توجه کنید که این برخلاف نام‌گذاری معمول است** (TX ماژول → پین 2 آردوینو، RX ماژول → پین 3 آردوینو).

### دستورات بلوتوث

| کاراکتر | افکت |
|----------|------|
| `a` | افکت موج (سرعت: ۶۰ میلی‌ثانیه) |
| `b` | افکت نایت رایدر (سرعت: ۴۰ میلی‌ثانیه) |
| `c` | افکت ضربان (تأخیر ۱۵۰ میلی‌ثانیه) |
| `d` | افکت انفجار (گام ۸۰ میلی‌ثانیه) |
| `e` | افکت مارپیچ سریع (گام ۳۰ میلی‌ثانیه، ۳ دور) |

### نحوه استفاده
1. **مدار** را مطابق جدول بالا ببندید.
2. **کد** را روی Arduino آپلود کنید.
3. **ماژول بلوتوث** را جفت‌سازی کنید (رمز پیش‌فرض ۱۲۳۴ یا ۰۰۰۰).
4. **یک اپلیکیشن ترمینال بلوتوث** (مانند "Arduino Bluetooth Controller" یا "Serial Bluetooth Terminal") نصب کنید.
5. **به ماژول متصل شوید** و کاراکترهای `a`، `b`، `c`، `d` یا `e` را ارسال کنید تا افکت‌های مختلف اجرا شوند.

> **نکته:** هر افکت فقط یک بار با هر دستور اجرا می‌شود. برای تکرار، دوباره دستور را ارسال کنید.

### ساختار کد
- **SoftwareSerial** روی پین‌های 2 (RX) و 3 (TX) برای ارتباط بلوتوث.
- آرایه `leds[]` شامل پین‌های ۴ تا ۱۳.
- تابع `allOff()` برای خاموش کردن همه LEDها.
- هر افکت در یک تابع جداگانه تعریف شده: `waveEffect()`، `knightRider()`، `pulseEffect()`، `explosionEffect()`، `spiralFast()`.
- در `loop()`، هنگام دریافت کاراکتر، افکت متناسب اجرا می‌شود.

### سفارشی‌سازی
- **تغییر سرعت:** پارامتر تأخیر در هر تابع افکت را تغییر دهید (مثلاً `waveEffect(60)`).
- **افزودن افکت جدید:** تابع خود را بنویسید و به یک کاراکتر جدید متصل کنید.
- **تغییر تعداد LEDها:** مقدار `ledCount` و آرایه `leds[]` را اصلاح کنید.

### مجوز
مجوز MIT – آزاد برای استفاده، تغییر و توزیع.

---

**Enjoy the light show! 🚀**  
**از نمایش نور لذت ببرید!**
