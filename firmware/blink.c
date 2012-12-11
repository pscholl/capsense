#include <avr/io.h>
#include <inttypes.h>
#include <stdint.h>
#include <util/delay.h>

#define BLUE_LED _BV(2); /* PB2 */

int main()
{
  DDRB  |= BLUE_LED; /* set as output */
  PORTB |= BLUE_LED; /* and turn on   */

  for (;;) {
    _delay_ms(50);
    PORTB |= BLUE_LED;
    _delay_ms(50);
    PORTB &= ~BLUE_LED;
  }
}
