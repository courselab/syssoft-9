/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 KSalmaze <pedrohsalmaze@usp.br>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  KSalmaze <pedrohsalmaze@usp.br>
 */

#include <stdio.h>

unsigned char bcd2bin(unsigned char bcd);

int main(void)   
{
  printf ("Hello World\n\r");

  unsigned int t = get_time();
  unsigned char h = bcd2bin((t >> 16) & 0xFF);
  unsigned char m = bcd2bin((t >> 8) & 0xFF);
  unsigned char s = bcd2bin(t & 0xFF);
  
  char horas[4];
  horas[0] = '0' + (h / 10);
  horas[1] = '0' + (h % 10);
  horas[2] = ':';    
  horas[3] = '\0';

  char minutos[4];
  minutos[0] = '0' + (m / 10);
  minutos[1] = '0' + (m % 10);
  minutos[2] = ':';
  minutos[3] = '\0';

  char segundos[4];
  segundos[0] = '0' + (s / 10);
  segundos[1] = '0' + (s % 10);
  segundos[2] = ' '; 
  segundos[3] = '\0';

  printf ("Horario: ");
  printf (horas);
  printf (minutos);
  printf (segundos);

  return 0;
}

unsigned char bcd2bin(unsigned char bcd) {
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}




