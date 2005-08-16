 /*
 * execscript.c 
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
 * Description: This file contains the the basic scripting interface used in
 * the various resource access layers for the providers in the sblim project.
 * 
 */ 

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "execscripts.h"

int debuglevel = DEBUGLEVEL;

int execScript1(const char *script, const char *par1){
	int status;
	pid_t pid;

	if ((!script) || (!par1))
		return -EINVAL;

	pid = fork();
	if (pid){
		waitpid(pid,&status,0);
		return -WEXITSTATUS(status);
	}
	else{
		status = execlp(script,script,par1,NULL);
		if (status < 0)
			exit(ECHILD);
	}
	return 0;
}


int execScript2(const char *script, const char *par1,
																		const char *par2){

	int status;
	pid_t pid;

	if ((!script) || (!par1) || (!par2))
		return -EINVAL;

	pid = fork();
	if (pid){
		waitpid(pid,&status,0);
		return -WEXITSTATUS(status);
	}
	else{
		status = execlp(script,script,par1,par2,NULL);
		if (status < 0)
			exit(ECHILD);
	}
	return 0;
}

int execScript3(const char *script, const char *par1,
																		const char *par2,
																		const char *par3){
	int status;
	pid_t pid;

	if ((!script) || (!par1) || (!par2) || (!par3))
		return -EINVAL;
	

	pid = fork();
	if (pid){
		waitpid(pid,&status,0);
		return -WEXITSTATUS(status);
	}
	else{
		status = execlp(script,script,par1,par2,par3,NULL);
		if (status < 0)
			exit(ECHILD);
	}
	return 0;
}


int execScript4(const char *script, const char *par1,
																		const char *par2,
																		const char *par3,
																		const char *par4){
	int status;
	pid_t pid;

	if ((!script) || (!par1) || (!par2) || (!par3) || (!par4))
		return -EINVAL;

	pid = fork();
	if (pid){
		waitpid(pid,&status,0);
		return -WEXITSTATUS(status);
	}
	else{
		status = execlp(script,script,par1,par2,par3,par4,NULL);
		if (status < 0)
			exit(ECHILD);
	}
	return 0;
}

void *readData(const char *script,  void *(*func)(int) ){
	int ret,fd[2];
	char *pipefd;
	pipe(fd);
	asprintf(&pipefd,"%d",fd[1]);
	
	ret = execScript1(script,pipefd);
	if (ret < 0){
			errno = ret;
			return NULL;
	}
	return func(fd[0]);
}
	
														
void *readData1(const char *script, const char *par1,
																		void *(*func)(int))	{
	int ret,fd[2];
	char *pipefd;
	pipe(fd);
	asprintf(&pipefd,"%d",fd[1]);
	
	ret = execScript2(script,par1,pipefd);
	if (ret < 0){
			errno = ret;
			return NULL;
	}
	return func(fd[0]);
}
void *readData2(const char *script, const char *par1,
																		const char *par2,
																		void *(*func)(int))	{
	int ret,fd[2];
	char *pipefd;
	pipe(fd);
	asprintf(&pipefd,"%d",fd[1]);
	
	ret = execScript3(script,par1,par2,pipefd);
	if (ret < 0){
			errno = ret;
			return NULL;
	}
	return func(fd[0]);
}
void *readData3(const char *script, const char *par1,
																		const char *par2,
																		const char *par3,
																		void *(*func)(int))	{
	int ret,fd[2];
	char *pipefd;
	pipe(fd);
	asprintf(&pipefd,"%d",fd[1]);
	
	ret = execScript4(script,par1,par2,par3,pipefd);
	if (ret < 0){
			errno = ret;
			return NULL;
	}
	return func(fd[0]);
}

void *writeData(const char *script,  void *(*func)(int) ){
	int ret,fd[2];
	char *pipefd;
	pipe(fd);
	asprintf(&pipefd,"%d",fd[0]);
	
	func(fd[1]);
	ret = execScript1(script,pipefd);
	if (ret < 0){
			errno = ret;
			return NULL;
	}
}
	

	
														
																		
