/*
 * libmad - MPEG audio decoder library
 * Copyright (C) 2000-2004 Underbit Technologies, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: global.h,v 1.2 2007/11/21 10:30:31 jgao Exp $
 */

# ifndef LIBMAD_GLOBAL_H
# define LIBMAD_GLOBAL_H
# define __malloc_and_calloc_defined

#if defined(WIN32) || defined(_WIN32)
#define inline __inline
#endif
/*
#define malloc(size) alloc(size)
#define calloc(size,sizeofbuf)  \
  (malloc((size) * (sizeofbuf)))
#define free(add) deAlloc(add)
#define realloc(add,size) realloc(add,size)

#define FILE FS_FILE
#define fseek(file, offset, whence)  \
(FS_FSeek((file), (offset), (whence)))
#define ftell(file)  \
  (FS_FTell((file)))

#define fopen(file,mode)  \
  (FS_FOpen((file),(mode)))
#define fclose(file)  \
  (FS_FClose((file)))
#define fread(buf,size,sizeofbuf,file)  \
  (FS_FRead((buf),(size),(sizeofbuf),(file)))
#define fwrite(buf,size,sizeofbuf,file)  \
  (FS_FWrite((buf),(size),(sizeofbuf), (file)))

*/


/* conditional debugging */

# if defined(DEBUG) && defined(NDEBUG)
#  error "cannot define both DEBUG and NDEBUG"
# endif

# if defined(DEBUG)
#  include <stdio.h>
# endif

/* conditional features */

# if defined(OPT_SPEED) && defined(OPT_ACCURACY)
#  error "cannot optimize for both speed and accuracy"
# endif

# if defined(OPT_SPEED) && !defined(OPT_SSO)
#  define OPT_SSO
# endif

# if defined(HAVE_UNISTD_H) && defined(HAVE_WAITPID) &&  \
    defined(HAVE_FCNTL) && defined(HAVE_PIPE) && defined(HAVE_FORK)
#  define USE_ASYNC
# endif

# if defined(DEBUG)
#  define release(ptr)      id3_debug_release(ptr,     __FILE__, __LINE__)
# else
#  define release(ptr)  (ptr)
# endif

# if !defined(HAVE_ASSERT_H)
#  if defined(NDEBUG)
#   define assert(x)	/* nothing */
#  else
#   define assert(x)	do { if (!(x)) abort(); } while (0)
#  endif
# endif

# endif
