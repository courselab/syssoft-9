/*
 *    SPDX-FileCopyrightText: 2025 KSalmaze <pedrohsalmaze@usp.br>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  KSalmaze <pedrohsalmaze@usp.br>
 */

#ifndef E8_H
#define E8_H

void __attribute__((fastcall, naked)) printf(const char *); 

unsigned int __attribute__((fastcall, naked)) get_time();

#endif	
