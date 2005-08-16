 /*
 * rastr.h 
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE COMMON PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Common Public License from
 * http://www.opensource.org/licenses/cpl1.0.php
 *
 * Author:  Glauber de Oliveira Costa <gocosta@br.ibm.com>
 *
 * Contributors:
 *
 * Description: header file for the string utilities 
 *
 */ 

#ifndef _STR_H_
#define _STR_H_

char *lstrip(char *);
char *rstrip(char *);
char *strip(char *);
char *noquotes(char *);
char *preproc(char *);
char *handler_name(char *);


#endif 