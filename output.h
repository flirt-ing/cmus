/*
 * Copyright 2005 Timo Hirvonen
 */

#ifndef _OUTPUT_H
#define _OUTPUT_H

#include <sf.h>

extern void op_init_plugins(void);

/*
 * errors: OP_ERROR_{}
 */
extern int op_init(void);

/*
 * errors: OP_ERROR_{}
 */
extern int op_exit(void);

/*
 * select output plugin and open its mixer
 *
 * errors: OP_ERROR_{ERRNO, NO_PLUGIN}
 */
extern int op_select(const char *name);

/*
 * open selected plugin
 *
 * errors: OP_ERROR_{}
 */
extern int op_open(sample_format_t sf);

/*
 * returns:
 *     0 if sample format didn't change
 *     1 if sample format did change
 *     OP_ERROR_{} on error
 */
extern int op_set_sf(sample_format_t sf);

extern int op_second_size(void);

/*
 * drop pcm data
 *
 * errors: OP_ERROR_{ERRNO}
 */
extern int op_drop(void);

/*
 * close plugin
 *
 * errors: OP_ERROR_{}
 */
extern int op_close(void);

/*
 * returns bytes written or error
 *
 * errors: OP_ERROR_{ERRNO}
 */
extern int op_write(const char *buffer, int count);

/*
 * errors: OP_ERROR_{}
 */
extern int op_pause(void);
extern int op_unpause(void);

/*
 * returns space in output buffer in bytes or -1 if busy
 */
extern int op_buffer_space(void);

/*
 * errors: OP_ERROR_{}
 */
extern int op_reset(void);

int op_set_volume(int left, int right);
int op_get_volume(int *left, int *right, int *max_vol);

/* returns 1 if changed, 0 otherwise */
int op_volume_changed(int *left, int *right, int *max_vol);

/*
 * errors: OP_ERROR_{NO_PLUGIN, NOT_INITIALIZED, NOT_OPTION}
 */
extern int op_set_option(const char *key, const char *val);
extern int op_get_option(const char *key, char **val);

extern int op_for_each_option(void (*callback)(void *data, const char *key), void *data);
extern char *op_get_error_msg(int rc, const char *arg);
extern void op_dump_plugins(void);
extern char *op_get_current(void);

#endif