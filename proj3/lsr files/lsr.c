#define __USE_MISC
#define _SYSTEM 1
#define _MINIX 1

#include "/usr/src/include/lsr.h"
#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"

#include <lib.h>
#include <minix/rs.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

//look up service endpoint
static int get_vfs_endpt(endpoint_t *pt)
{
  return minix_rs_lookup("vfs", pt);
}

int lsr(char *path)
{
  printf("starting lsr system call\n");
  message m;
  endpoint_t vfs_pt;
  m.m_type = LSR_MESSAGE;
  _syscall(vfs_pt, LSR, &m);
  int reply = m.m_type;
  printf("reply = %d\n", reply);
  return reply;
}


