TI Launchpads connected with nRF24L01+ 
====================================

## Wiring
| 		  |				  |
|:--------|:-------------:|
| ![MSP430G2553](storage/blogs_imgs/nrf24l001_imgs/tbm_msp-exp430g2_mspexp430g2.png) | GND (`PIN1`) - `GND`<br/>VCC (`PIN2`) - `3V3`<br/>CE (`PIN3`) - GPIO (`P2.5`)<br/>CSN (`PIN4`) - GPIO (`P2.2`)<br/>SCK (`PIN5`) - SCK (`P1.5`)<br/>MOSI(`PIN6`) - MISO (`P1.6`)<br/>MISO(`PIN7`) - MOSI (`P1.7`) <p><p/> <b>Debugging</b> (<a href="https://goo.gl/f7I005" target="_blank">CP2102 USB to TTL</a>) <br/>TXD - RXD (`P1.1`)<br/>RXD - TXD (`P1.2`)<br/>GND - GND |

<br/>

| 		  |				  |
|:--------|:-------------:|
| ![MSP430F5529LP](storage/blogs_imgs/nrf24l001_imgs/tbm_msp-exp430f5529lp_5529.png) | GND (`PIN1`) - `GND`<br/>VCC (`PIN2`) - `3V3`<br/>CE (`PIN3`) - GPIO (`P2.0`)<br/>CSN (`PIN4`) - GPIO (`P2.1`)<br/>SCK (`PIN5`) - UCB0CLK (`P3.2`)<br/>MOSI(`PIN6`) - UCB0SIMO (`P3.0`)<br/>MISO(`PIN7`) - UCB0SOMI (`P3.1`) <p><p/> <b>Debugging</b> (<a href="https://goo.gl/f7I005" target="_blank">CP2102 USB to TTL</a>) <br/>TXD - UCA0RXD (`P3.4`)<br/>RXD - UCA0TXD (`P3.3`)<br/>GND - GND |

<br/>

| 		  |				  |
|:--------|:-------------:|
| ![EK-TM4C1294](storage/blogs_imgs/nrf24l001_imgs/tbm_ek-tm4c1294xl_tm4c1294.png)   | GND (`PIN1`) - `GND`<br/>VCC (`PIN2`) - `3V3`<br/>CE (`PIN3`) - GPIO (`PM5`)<br/>CSN (`PIN4`) - GPIO (`PM4`)<br/>SCK (`PIN5`) - SSI2Clk (`PD5`)<br/>MOSI(`PIN6`) - SSI2Tx (`PD1`)<br/>MISO(`PIN7`) - SSI2Rx (`PD0`) <p><p/> <b>Debugging</b> (<a href="https://goo.gl/f7I005" target="_blank">CP2102 USB to TTL</a>) <br/>TXD - U6Rx (`PP0`) / U7Rx (`PC4`)<br/>RXD - U6Tx (`PP1`) / U7Tx (`PC5`)<br/>GND - GND |


More info & Help
-------------------------
* Original documentation: http://tmrh20.github.io/RF24
* TI-Launchpads documentation: https://goo.gl/an7oPB
* nRF24L01+ datasheet: https://www.nordicsemi.com/eng/Products/2.4GHz-RF/nRF24L01P

Credit
-------------------------
Based on: https://github.com/TMRh20/RF24