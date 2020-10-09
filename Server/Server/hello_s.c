

/* this ALWAYS GENERATED file contains the RPC server stubs */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Oct 02 11:33:41 2020
 */
/* Compiler settings for hello.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>
#include "hello_h.h"

#define TYPE_FORMAT_STRING_SIZE   29                                
#define PROC_FORMAT_STRING_SIZE   61                                
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _hello_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } hello_MIDL_TYPE_FORMAT_STRING;

typedef struct _hello_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } hello_MIDL_PROC_FORMAT_STRING;

typedef struct _hello_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } hello_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};

extern const hello_MIDL_TYPE_FORMAT_STRING hello__MIDL_TypeFormatString;
extern const hello_MIDL_PROC_FORMAT_STRING hello__MIDL_ProcFormatString;
extern const hello_MIDL_EXPR_FORMAT_STRING hello__MIDL_ExprFormatString;

/* Standard interface: INTERFACENAME, ver. 1.0,
   GUID={0x296bd6eb,0x2ca9,0x4321,{0x87,0x5f,0x5f,0x4c,0xfc,0x10,0xec,0xbe}} */


extern const MIDL_SERVER_INFO INTERFACENAME_ServerInfo;

extern const RPC_DISPATCH_TABLE INTERFACENAME_v1_0_DispatchTable;

static const RPC_SERVER_INTERFACE INTERFACENAME___RpcServerInterface =
    {
    sizeof(RPC_SERVER_INTERFACE),
    {{0x296bd6eb,0x2ca9,0x4321,{0x87,0x5f,0x5f,0x4c,0xfc,0x10,0xec,0xbe}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    (RPC_DISPATCH_TABLE*)&INTERFACENAME_v1_0_DispatchTable,
    0,
    0,
    0,
    &INTERFACENAME_ServerInfo,
    0x04000000
    };
RPC_IF_HANDLE INTERFACENAME_v1_0_s_ifspec = (RPC_IF_HANDLE)& INTERFACENAME___RpcServerInterface;

extern const MIDL_STUB_DESC INTERFACENAME_StubDesc;


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const hello_MIDL_PROC_FORMAT_STRING hello__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure HelloProc */

			0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x46c ),	/* x86 Stack size/offset = 1132 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter p */

/* 24 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 26 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 28 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x468 ),	/* x86 Stack size/offset = 1128 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShutDown */

/* 36 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x48,		/* Old Flags:  */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x1 ),	/* 1 */
/* 44 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	0x40,		/* Oi2 Flags:  has ext, */
			0x0,		/* 0 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

			0x0
        }
    };

static const hello_MIDL_TYPE_FORMAT_STRING hello__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x26,		/* FC_CSTRING */
			0x5c,		/* FC_PAD */
/*  4 */	NdrFcShort( 0x64 ),	/* 100 */
/*  6 */	
			0x26,		/* FC_CSTRING */
			0x5c,		/* FC_PAD */
/*  8 */	NdrFcShort( 0x400 ),	/* 1024 */
/* 10 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 12 */	NdrFcShort( 0x468 ),	/* 1128 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	NdrFcShort( 0x0 ),	/* Offset= 0 (16) */
/* 18 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xffed ),	/* Offset= -19 (2) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 24 */	0x0,		/* 0 */
			NdrFcShort( 0xffed ),	/* Offset= -19 (6) */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const unsigned short INTERFACENAME_FormatStringOffsetTable[] =
    {
    0,
    36
    };


static const MIDL_STUB_DESC INTERFACENAME_StubDesc = 
    {
    (void *)& INTERFACENAME___RpcServerInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    0,
    0,
    0,
    0,
    0,
    hello__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

static const RPC_DISPATCH_FUNCTION INTERFACENAME_table[] =
    {
    NdrServerCall2,
    NdrServerCall2,
    0
    };
static const RPC_DISPATCH_TABLE INTERFACENAME_v1_0_DispatchTable = 
    {
    2,
    (RPC_DISPATCH_FUNCTION*)INTERFACENAME_table
    };

static const SERVER_ROUTINE INTERFACENAME_ServerRoutineTable[] = 
    {
    (SERVER_ROUTINE)HelloProc,
    (SERVER_ROUTINE)ShutDown
    };

static const MIDL_SERVER_INFO INTERFACENAME_ServerInfo = 
    {
    &INTERFACENAME_StubDesc,
    INTERFACENAME_ServerRoutineTable,
    hello__MIDL_ProcFormatString.Format,
    INTERFACENAME_FormatStringOffsetTable,
    0,
    0,
    0,
    0};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

