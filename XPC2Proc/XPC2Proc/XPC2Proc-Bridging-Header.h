#ifndef MachLaunchD_Bridging_Header_h
#define MachLaunchD_Bridging_Header_h

#include <xpc/xpc.h>
#include <mach/mach.h>
#include <mach/mach_init.h>

// Forward declarations for the XPC and Mach functions
typedef void* xpc_pipe_t;

// We'll grab the bootstrap port directly here (see slide 25 of our talk)
extern mach_port_t bootstrap_port;

extern xpc_pipe_t xpc_pipe_create_from_port(mach_port_t port, uint64_t flags);
extern int xpc_pipe_routine(xpc_pipe_t pipe, xpc_object_t message, xpc_object_t* reply);
extern const char* xpc_strerror(int error);
extern kern_return_t mach_ports_lookup(task_t task, mach_port_t **ports, mach_msg_type_number_t *portsCnt);

#endif /* XPC2Proc-Bridging-Header-h */
