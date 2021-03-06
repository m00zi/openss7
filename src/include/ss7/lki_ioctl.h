/*****************************************************************************

 @(#) src/include/ss7/lki_ioctl.h

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

#ifndef __SS7_LKI_IOCTL_H__
#define __SS7_LKI_IOCTL_H__

/* This file can be processed by doxygen(1). */

#include <linux/ioctl.h>

#define LK_IOC_MAGIC 'k'

/*
 *  -----------------------------------------------------------------------
 *
 *  PROTOCOL VARIANT AND OPTIONS
 *
 *  -----------------------------------------------------------------------
 */

#define LK_IOCGOPTIONS	_IOR(  LK_IOC_MAGIC, 0, lmi_option_t )
#define LK_IOCSOPTIONS	_IOW(  LK_IOC_MAGIC, 1, lmi_option_t )

/*
 *  -----------------------------------------------------------------------
 *
 *  CONFIGURATION
 *
 *  -----------------------------------------------------------------------
 */
typedef struct lk_config {
} lk_config_t;

#define LK_IOCGCONFIG	_IOWR( LK_IOC_MAGIC, 2, lk_config_t )
#define LK_IOCSCONFIG	_IOWR( LK_IOC_MAGIC, 3, lk_config_t )
#define LK_IOCTCONFIG	_IOWR( LK_IOC_MAGIC, 4, lk_config_t )
#define LK_IOCCCONFIG	_IOWR( LK_IOC_MAGIC, 5, lk_config_t )

/*
 *  STATE
 */

typedef struct lk_statem {
} lk_statem_t;

#define LK_STATE_IDLE                     0

#define LK_IOCGSTATEM	_IOR(  LK_IOC_MAGIC, 6, lk_statem_t )
#define LK_IOCCMRESET	_IOR(  LK_IOC_MAGIC, 7, lk_statem_t )

/*
 *  -----------------------------------------------------------------------
 *
 *  STATISTICS
 *
 *  -----------------------------------------------------------------------
 */

typedef struct lk_stats {
	lmi_sta_t header;
} lk_stats_t;

/*
   FIXME: read 3.11 and recheck congestion procedures 
 */

#define LK_IOCGSTATSP	_IOR(  LK_IOC_MAGIC,  8, lmi_sta_t )
#define LK_IOCSSTATSP	_IORW( LK_IOC_MAGIC,  9, lmi_sta_t )
#define LK_IOCGSTATS	_IOR(  LK_IOC_MAGIC, 10, lk_stats_t )
#define LK_IOCCSTATS	_IOW(  LK_IOC_MAGIC, 11, lk_stats_t )

/*
 *  -----------------------------------------------------------------------
 *
 *  NOTIFICATIONS
 *
 *  -----------------------------------------------------------------------
 */

typedef struct lk_notify {
	lk_ulong events;
} lk_notify_t;

#define LK_EVENT_HEADER_LEN         16	/* for now */

#define LK_IOCGNOTIFY	_IOR(  LK_IOC_MAGIC, 12, lk_notify_t )
#define LK_IOCSNOTIFY	_IOW(  LK_IOC_MAGIC, 13, lk_notify_t )
#define LK_IOCCNOTIFY	_IOW(  LK_IOC_MAGIC, 14, lk_notify_t )

#define LK_IOC_FIRST     0
#define LK_IOC_LAST     14
#define LK_IOC_PRIVATE  32

#endif				/* __SS7_LKI_IOCTL_H__ */
