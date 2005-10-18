 /*
 * execscripts.h 
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
 * Description: header file for the scripts layer 
 *
 */ 

#ifndef _SMT_LIBRA_EXECSCRIPTS_H_
#define _SMT_LIBRA_EXECSCRIPTS_H_

#ifdef __cplusplus
extern "C" {
#endif 

#ifndef DEBUGLEVEL
	#define DEBUGLEVEL 3
#endif

#define DEBUG(a,b,c...) ( (a <= debuglevel) && ( a >= 0) ? printf(b,##c) : NULL);

int execScript(const char *);

int execScript1(const char *, const char *);
  
int execScript2(const char *, const char *, const char *);
  
int execScript3(const char *, const char *,const char *, const char *);
  
int execScript4(const char *, const char *,const char *, const char *, 
		                                         const char *);
  
#ifdef __cplusplus
}
#endif

#endif 
