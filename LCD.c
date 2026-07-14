
#include "LCD.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <xc.h>
#include "mcc_generated_files\i2c_host/mssp1.h"
#include "mcc_generated_files\i2c_host\src/mssp1.c"
	
#define LCD_adres 0x27
#define LCD_RS 1U
#define LCD_Enable 4U
#define LCD_aydinla 8U



    void I2C_gonder(uint8_t veri ){
        uint8_t dizi[]={veri | LCD_Enable | LCD_aydinla, (veri & ~LCD_Enable) | LCD_aydinla};
        I2C1_Write(LCD_adres, &dizi[0], 1);
        __delay_us(500); 
        I2C1_Write(LCD_adres, &dizi[1], 1);
        __delay_ms(5);
        }
    /*
     LCD'ye veri gönderir. Kumut için RS=0, yazı için RS=LCD_RS olmalıdır.
     */
    void LCD_gonder(uint8_t bilgi, uint8_t RS){
        I2C_gonder((bilgi & 0xF0) | RS);        //Üst 4 bit
        I2C_gonder(((bilgi << 4) & 0xF0) | RS); //Alt 4 bit
    }
    
    
    
    /*  LCD ekranı başlatır. Önce bu fonksiyon çağrılmalıdır.  */
    void LCD_baslat(void){
        __delay_ms(50); 
        I2C_gonder(0x30);
        I2C_gonder(0x30);
        I2C_gonder(0x30);
        I2C_gonder(0x20);
        LCD_gonder(0x28, 0x00);      
        LCD_gonder(0x08, 0x00);
        LCD_gonder(0x01, 0x00);
        LCD_gonder(0x06, 0x00);
        LCD_gonder(0x0C, 0x00);
        __delay_ms(50);
        
        
    }
    
    
    /*	 İmleçi verilen satır sütun numarasına götürür  */

void lcd_git(uint8_t satir, uint8_t sutun) {
    uint8_t temp;
    switch (satir) {
        case 1:
            temp = sutun - 1 + 0x80;
            break;
        case 2:
            temp = sutun - 1 + 0xc0;
            break;
    }
    LCD_gonder(temp, 0x00);
}

 /*	Verilen satır sütun numarasından başlayarak ekrana mesaj yazar*/
 
void lcd_mesajyaz(uint8_t satir, uint8_t sutun, const char *mesaj) {
	lcd_git(satir, sutun);
    do {
        LCD_gonder(*mesaj++, LCD_RS);
        __delay_us(200);
    } while (*mesaj);
}
