#include <avr/io.h>
#include <avr/power.h>
#include <stdint.h>
#include <util/delay.h>

#define BLUE_LED _BV(2) /* PB2 */
#define ADDR0    _BV(0) /* PA0 */
#define ADDR1    _BV(1)
#define SWITCH   _BV(2)
#define ENABLE   _BV(3)
#define I2C_A0   _BV(4)
#define I2C_A1   _BV(5)
#define I2C_A2   _BV(6)

int main()
{
  clock_prescale_set(clock_div_1);

  DDRB  |=  BLUE_LED; /* set as output  */
  PORTB &= ~BLUE_LED; /* and switch off */

  DDRA  |=  ENABLE;
  PORTA |=  ENABLE;

  for (;;) {
    if (PINA& SWITCH)
      PORTB |= BLUE_LED;
    else
      PORTB &= ~BLUE_LED;
  }
}
