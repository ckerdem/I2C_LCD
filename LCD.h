/* 
 * File:   LCD.h
 * Author: Celal
 *
 * Created on March 29, 2026, 1:48 PM
 */

#include <stdint.h>

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

/*  Fonksiyon prototipleri
 */
    void I2C_gonder(uint8_t veri);
    void LCD_gonder(uint8_t bilgi, uint8_t RS);
    void LCD_baslat (void);
    void lcd_git(uint8_t satir, uint8_t sutun);
    void lcd_mesajyaz(uint8_t satir, uint8_t sutun, const char *mesaj);
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

