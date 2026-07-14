2x16 LCD 11 uçla denetlenmektedir. Bu mikro denetleyicide 11 ucun kullanılmasını gerektirir.
LCD'yi I2C üzerinden çalıştırırken 2 uç kullanılması yeterlidir.
Bu program bu nedenle hazırlanmıştır. PIC18F45K22 ve MPLAB X içindir.
Kullanmak için MPLAB X'de bir proje başlatıp MCC ( MPLAB Code Configurator ) ile I2C fonksiyonları hazırlanmalıdır.
Daha sonra LCD.c ve LCD.h dosyaları projeye eklenmelidir. MCC'nin hazırladığı main.c dosyası buradaki main.c dosyasına uygun hale getirilmelidir.
Bu program her ne kadar PIC18F45K22 için hazırlanmışsada MMC kullanarak diğer PIC'ler ile de kullanılabilir.
