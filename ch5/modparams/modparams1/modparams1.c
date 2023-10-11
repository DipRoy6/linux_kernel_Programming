/*
 * ch5/modparams/modparams1/modparams1.c
 ***************************************************************
 * This program is part of the source code released for the book
 *  "Linux Kernel Programming" 2E
 *  (c) Author: Kaiwan N Billimoria
 *  Publisher:  Packt
 *  GitHub repository:
 *  https://github.com/PacktPublishing/Linux-Kernel-Programming_2E
 *
 * From: Ch 5: Writing your First Kernel Module- LKMs Part 2
 ****************************************************************
 * Brief Description:
 * A simple demo of passing a couple of parameters to our kernel module.
 *
 * For details, please refer the book, Ch 5.
 */
#define pr_fmt(fmt) "%s:%s(): " fmt, KBUILD_MODNAME, __func__

#include <linux/init.h>
#include <linux/module.h>

MODULE_AUTHOR("Kaiwan N Billimoria");
MODULE_DESCRIPTION("LKP2E book:ch5/modparams/modparams1: module parameters demo LKM #1");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.2");

/* Module parameters */
static int mp_debug_level;
module_param(mp_debug_level, int, 0660);
//module_param(mp_debug_level, int, S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP);
MODULE_PARM_DESC(mp_debug_level,
"Debug level [0-2]; 0 => no debug messages, 2 => high verbosity");

static char *mp_strparam = "My string param";
module_param(mp_strparam, charp, 0660);
MODULE_PARM_DESC(mp_strparam, "A demo string parameter");

static int __init modparams1_init(void)
{
	pr_info("inserted\n");
	pr_info("module parameters passed: mp_debug_level=%d mp_strparam=%s\n",
		mp_debug_level, mp_strparam);
	return 0;		/* success */
}

static void __exit modparams1_exit(void)
{
	pr_info("module parameters passed: mp_debug_level=%d mp_strparam=%s\n",
		mp_debug_level, mp_strparam);
	pr_info("removed\n");
}

module_init(modparams1_init);
module_exit(modparams1_exit);
