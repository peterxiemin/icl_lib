//
//  icl_file_opt.h
//  icllib
//
//  Created by peterxm on 14-9-1.
//  Copyright (c) 2014年 peterxm. All rights reserved.
//


#ifndef ICLLIB_ICL_FILE_OPT_H
#define ICLLIB_ICL_FILE_OPT_H

FILE *icl_fopen(const char *path, const char *mode); 

int icl_open(const char *path, int flags);
int icl_open2(const char *path, int flags, mode_t mode);

FILE *icl_fdopen(int fd, const char *mode);

int icl_fseek(FILE *stream, long off_set, int whence);
long icl_ftell(FILE *stream);
int icl_fclose(FILE *stream);

unsigned long icl_get_flsz(const char *path);

int icl_fwrite(void *ptr, int size, int nmemb, FILE *stream);
int icl_fread(void *ptr, int size, int nmemb, FILE *stream);
int icl_write(int fd, void *buf, int count);
int icl_read(int fd, void *buf, int count);
int icl_io(void *ptr, int size, int nmemb, void *stream, int flags);

#endif
