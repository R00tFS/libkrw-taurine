#ifndef    _kernrw_daemon_user_
#define    _kernrw_daemon_user_

/* Module kernrw_daemon */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>
    
/* BEGIN VOUCHER CODE */

#ifndef KERNEL
#if defined(__has_include)
#if __has_include(<mach/mig_voucher_support.h>)
#ifndef USING_VOUCHERS
#define USING_VOUCHERS
#endif
#ifndef __VOUCHER_FORWARD_TYPE_DECLS__
#define __VOUCHER_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
 "C" {
#endif
     boolean_t voucher_mach_msg_set(mach_msg_header_t *msg) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif // __VOUCHER_FORWARD_TYPE_DECLS__
#endif // __has_include(<mach/mach_voucher_types.h>)
#endif // __has_include
#endif // !KERNEL
    
/* END VOUCHER CODE */

    
/* BEGIN MIG_STRNCPY_ZEROFILL CODE */

#if defined(__has_include)
#if __has_include(<mach/mig_strncpy_zerofill_support.h>)
#ifndef USING_MIG_STRNCPY_ZEROFILL
#define USING_MIG_STRNCPY_ZEROFILL
#endif
#ifndef __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#define __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__
#ifdef __cplusplus
 "C" {
#endif
     int mig_strncpy_zerofill(char *dest, const char *src, int len) __attribute__((weak_import));
#ifdef __cplusplus
}
#endif
#endif /* __MIG_STRNCPY_ZEROFILL_FORWARD_TYPE_DECLS__ */
#endif /* __has_include(<mach/mig_strncpy_zerofill_support.h>) */
#endif /* __has_include */
    
/* END MIG_STRNCPY_ZEROFILL CODE */


#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry   *function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef    kernrw_daemon_MSG_COUNT
#define    kernrw_daemon_MSG_COUNT    7
#endif    /* kernrw_daemon_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mig.h>
#include <mach/mig.h>
#include <mach/mach_types.h>

#ifdef __BeforeMigUserHeader
__BeforeMigUserHeader
#endif /* __BeforeMigUserHeader */

#include <sys/cdefs.h>
__BEGIN_DECLS


/* Routine read32 */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_read32
(
    mach_port_t server_port,
    uint64_t kaddr,
    uint32_t *val
);

/* Routine read64 */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_read64
(
    mach_port_t server_port,
    uint64_t kaddr,
    uint64_t *val
);

/* Routine write32 */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_write32
(
    mach_port_t server_port,
    uint64_t kaddr,
    uint32_t val
);

/* Routine write64 */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_write64
(
    mach_port_t server_port,
    uint64_t kaddr,
    uint64_t val
);

/* Routine kernelBase */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_kernelBase
(
    mach_port_t server_port,
    uint64_t *val
);

/* Routine kernelProc */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_kernelProc
(
    mach_port_t server_port,
    uint64_t *val
);

/* Routine allProc */
#ifdef    mig_external
mig_external
#else

#endif    /* mig_external */
kern_return_t krw_allProc
(
    mach_port_t server_port,
    uint64_t *val
);

__END_DECLS

/********************** Caution **************************/
/* The following data types should be used to calculate  */
/* maximum message sizes only. The actual message may be */
/* smaller, and the position of the arguments within the */
/* message layout may vary from what is presented here.  */
/* For example, if any of the arguments are variable-    */
/* sized, and less than the maximum is sent, the data    */
/* will be packed tight in the actual message to reduce  */
/* the presence of holes.                                */
/********************** Caution **************************/

/* typedefs for all requests */

#ifndef __Request__kernrw_daemon_subsystem__defined
#define __Request__kernrw_daemon_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        uint64_t kaddr;
    } __Request__read32_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        uint64_t kaddr;
    } __Request__read64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        uint64_t kaddr;
        uint32_t val;
    } __Request__write32_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        uint64_t kaddr;
        uint64_t val;
    } __Request__write64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
    } __Request__kernelBase_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
    } __Request__kernelProc_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
    } __Request__allProc_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Request__kernrw_daemon_subsystem__defined */

/* union of all requests */

#ifndef __RequestUnion__krw_kernrw_daemon_subsystem__defined
#define __RequestUnion__krw_kernrw_daemon_subsystem__defined
union __RequestUnion__krw_kernrw_daemon_subsystem {
    __Request__read32_t Request_krw_read32;
    __Request__read64_t Request_krw_read64;
    __Request__write32_t Request_krw_write32;
    __Request__write64_t Request_krw_write64;
    __Request__kernelBase_t Request_krw_kernelBase;
    __Request__kernelProc_t Request_krw_kernelProc;
    __Request__allProc_t Request_krw_allProc;
};
#endif /* !__RequestUnion__krw_kernrw_daemon_subsystem__defined */
/* typedefs for all replies */

#ifndef __Reply__kernrw_daemon_subsystem__defined
#define __Reply__kernrw_daemon_subsystem__defined

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
        uint32_t val;
    } __Reply__read32_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
        uint64_t val;
    } __Reply__read64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
    } __Reply__write32_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
    } __Reply__write64_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
        uint64_t val;
    } __Reply__kernelBase_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
        uint64_t val;
    } __Reply__kernelProc_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif

#ifdef  __MigPackStructs
#pragma pack(push, 4)
#endif
    typedef struct {
        mach_msg_header_t Head;
        NDR_record_t NDR;
        kern_return_t RetCode;
        uint64_t val;
    } __Reply__allProc_t __attribute__((unused));
#ifdef  __MigPackStructs
#pragma pack(pop)
#endif
#endif /* !__Reply__kernrw_daemon_subsystem__defined */

/* union of all replies */

#ifndef __ReplyUnion__krw_kernrw_daemon_subsystem__defined
#define __ReplyUnion__krw_kernrw_daemon_subsystem__defined
union __ReplyUnion__krw_kernrw_daemon_subsystem {
    __Reply__read32_t Reply_krw_read32;
    __Reply__read64_t Reply_krw_read64;
    __Reply__write32_t Reply_krw_write32;
    __Reply__write64_t Reply_krw_write64;
    __Reply__kernelBase_t Reply_krw_kernelBase;
    __Reply__kernelProc_t Reply_krw_kernelProc;
    __Reply__allProc_t Reply_krw_allProc;
};
#endif /* !__RequestUnion__krw_kernrw_daemon_subsystem__defined */

#ifndef subsystem_to_name_map_kernrw_daemon
#define subsystem_to_name_map_kernrw_daemon \
    { "read32", 600 },\
    { "read64", 601 },\
    { "write32", 602 },\
    { "write64", 603 },\
    { "kernelBase", 604 },\
    { "kernelProc", 605 },\
    { "allProc", 606 }
#endif

#ifdef __AfterMigUserHeader
__AfterMigUserHeader
#endif /* __AfterMigUserHeader */

#endif     /* _kernrw_daemon_user_ */
