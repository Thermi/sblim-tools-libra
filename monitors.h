 /*
 * monitors.h 
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
 * Description: header files for the monitors utilities
 *
 */ 

#ifndef _MONITORS_H_
#define _MONITORS_H_


#ifdef __cplusplus
extern "C" {
#endif

struct entry{
	char *filename;
	struct stat st;
};

struct monitor{
	struct entry *entries;
	int nentries;
	int maxentries;
};


void destroy_entries(struct monitor *);
struct entry *add_entry(struct monitor *,char *);
struct entry *find_entry(struct monitor *,char *);
void del_entry(struct monitor *,struct entry *);
struct monitor *init_monitor(int);
int monitor_file(struct monitor *,char *);
int unmonitor_file(struct monitor *,char *);
int check_events(struct monitor *);

#ifdef __cplusplus
}
#endif

#endif 