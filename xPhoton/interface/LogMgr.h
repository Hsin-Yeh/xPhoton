#ifndef __LOGMGR_H__
#define __LOGMGR_H__
#include <stdio.h>

// current setting
//#define __print_debug__
#define __print_info__



#ifdef __print_debug__
    #define LOG_DEBUG(format, args...)   fprintf(stderr, "-debug-    %s  : " format "\n", __PRETTY_FUNCTION__,  ##args)
    #define __print_info__
    #define __print_critical__
    #define __print_warning__
    #define __print_fatal__
#else
    #define LOG_DEBUG(format, args...)
#endif

#ifdef __print_info__
    #define LOG_INFO(format, args...)    fprintf(stderr, "-info-     %s  : " format "\n", __PRETTY_FUNCTION__,  ##args)
    #define __print_critical__
    #define __print_warning__
    #define __print_fatal__
#else
    #define LOG_INFO(format, args...)
#endif

#ifdef __print_critical__
    #define LOG_CRITICAL(format, args...)fprintf(stderr, "-critical- %s  : " format "\n", __PRETTY_FUNCTION__,  ##args)
    #define __print_warning__
    #define __print_fatal__
#else
    #define LOG_INFO(format, args...)
#endif

#ifdef __print_warning__
    #define LOG_WARNING(format, args...) fprintf(stderr, "-warning-  %s  : " format "\n", __PRETTY_FUNCTION__,  ##args)
    #define __print_fatal__
#else
    #define LOG_WARNING(format, args...)
#endif

#ifdef __print_fatal__
    #define LOG_FATAL(format, args...)  {fprintf(stderr, "-fatal-    %s  : " format "\n", __PRETTY_FUNCTION__,  ##args); exit(1); }
#else
    #define LOG_FATAL(format, args...)
#endif





#endif
