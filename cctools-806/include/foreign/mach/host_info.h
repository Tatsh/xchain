#ifndef _MACH_HOST_INFO_H_
#define _MACH_HOST_INFO_H_

typedef integer_t       *host_info_t;           /* varying array of int. */

typedef integer_t       host_flavor_t;
#define HOST_BASIC_INFO         1       /* basic info */
#define HOST_SCHED_INFO         3       /* scheduling info */
#define HOST_RESOURCE_SIZES     4       /* kernel struct sizes */
#define HOST_PRIORITY_INFO      5       /* priority information */
#define HOST_SEMAPHORE_TRAPS    7       /* Has semaphore traps */
#define HOST_MACH_MSG_TRAP      8       /* Has mach_msg_trap */

struct host_basic_info {
  integer_t               max_cpus;               /* max number of CPUs possible */
  integer_t               avail_cpus;             /* number of CPUs now available */
  natural_t               memory_size;            /* size of memory in bytes, capped at 2 GB */
  cpu_type_t              cpu_type;               /* cpu type */
  cpu_subtype_t           cpu_subtype;            /* cpu subtype */
  cpu_threadtype_t        cpu_threadtype;         /* cpu threadtype */
  integer_t               physical_cpu;           /* number of physical CPUs now available */
  integer_t               physical_cpu_max;       /* max number of physical CPUs possible */
  integer_t               logical_cpu;            /* number of logical cpu now available */
  integer_t               logical_cpu_max;        /* max number of physical CPUs possible */
  uint64_t                max_mem;                /* actual size of physical memory */
};

typedef struct host_basic_info  host_basic_info_data_t;
typedef struct host_basic_info  *host_basic_info_t;
#define HOST_BASIC_INFO_COUNT \
                (sizeof(host_basic_info_data_t)/sizeof(integer_t))


struct host_sched_info {
  integer_t       min_timeout;    /* minimum timeout in milliseconds */
  integer_t       min_quantum;    /* minimum quantum in milliseconds */
};

typedef struct host_sched_info  host_sched_info_data_t;
typedef struct host_sched_info  *host_sched_info_t;
#define HOST_SCHED_INFO_COUNT \
                (sizeof(host_sched_info_data_t)/sizeof(integer_t))


#endif
