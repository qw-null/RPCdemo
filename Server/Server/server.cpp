//引入rpcrt4.lib依赖包，操作过程为：
//右键工程属性，在Linker->Input->Additional Dependencies中添加rpcrt4.lib
//否则无法编译成功

#include <iostream>
using namespace std;

#include "hello_h.h"

int main(void)
{
 RPC_STATUS status = 0;


 //RpcServerUseProtseqEp()详解：
 //The RpcServerUseProtseqEp function tells the RPC run-time library to use the specified protocol sequence combined with the specified endpoint for receiving remote procedure calls.
//RPC_STATUS RpcServerUseProtseqEp(
//RPC_CSTR     Protseq,  //Pointer to a string identifier of the protocol sequence to register with the RPC run-time library.
// unsigned int MaxCalls,//Backlog queue length for the ncacn_ip_tcp protocol sequence. All other protocol sequences ignore this parameter. Use RPC_C_PROTSEQ_MAX_REQS_DEFAULT to specify the default value.
//  RPC_CSTR   Endpoint,//Pointer to the endpoint-address information to use in creating a binding for the protocol sequence specified in the Protseq parameter.
//  void     *SecurityDescriptor//Pointer to an optional parameter provided for the security subsystem. Used only for ncacn_np and ncalrpc protocol sequences. All other protocol sequences ignore this parameter. Using a security descriptor on the endpoint in order to make a server secure is not recommended. This parameter does not appear in the DCE specification for this API.
//);
 
 //使用TCP方式作为RPC的通道，绑定端口号13521
 status = RpcServerUseProtseqEp((RPC_CSTR)"ncacn_ip_tcp",RPC_C_PROTSEQ_MAX_REQS_DEFAULT,(RPC_CSTR)"8080",NULL);
 if(status != 0){
  cout<<"RpcServerUseProtseqEp returns: "<<status<<endl;
  return -1;
 }

 // RpcServerRegisterIfEx()详解：
//The RpcServerRegisterIfEx function registers an interface with the RPC run-time library.
//RPC_STATUS RpcServerRegisterIfEx(
//  RPC_IF_HANDLE      IfSpec,//MIDL-generated structure indicating the interface to register.//使用内容在自动生成文件hello_h.h中
//  UUID               *MgrTypeUuid,//Pointer to a type UUID to associate with the MgrEpv parameter. Specifying a null parameter value (or a nil UUID) registers IfSpec with a nil-type UUID.
//  RPC_MGR_EPV        *MgrEpv,//Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a null value. For more information, please see RPC_MGR_EPV.
//  unsigned int       Flags,//Flags. For a list of flag values, see Interface Registration Flags.
//  unsigned int       MaxCalls,//If the number of concurrent calls is not a concern, you can achieve slightly better server-side performance by specifying the default value using RPC_C_LISTEN_MAX_CALLS_DEFAULT. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.
//  RPC_IF_CALLBACK_FN *IfCallback//Security-callback function, or NULL for no callback. Each registered interface can have a different callback function. See Remarks for more details.
//);

//在hello_h.h文件中可以看到hello.idl中所定义的接口实体，一个全局句柄变量（handle_t）
 //以及客户端与服务端的接口句柄名INTERFACENAME_v1_0_c_ifspec（客户端使用）和INTERFACENAME_v1_0_s_ifspec（服务器端使用）。

 //从windowsXP SP2开始，增强安全性的要求，如果用的RpcServerRegisterIf()注册接口的话
 //客户端调用会出现RpcExceptionCode()==5,即AccessDenied的错误，因此，必须用
 //RpcServerRegisterIfEx()带RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,标志允许客户端直接调用
 //status = RpcServerRegisterIf(INTERFACENAME_v1_0_s_ifspec, NULL, NULL);
 status = RpcServerRegisterIfEx(INTERFACENAME_v1_0_s_ifspec,NULL,NULL,RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,0,NULL);
 if(status != 0){
  cout<<"RpcServerRegisterIf returns: "<<status<<endl;
  return -1;
 }

 cout<<"Rpc Server Begin Listening..."<<endl;

 //RpcServerListen()详解：
 //The RpcServerListen function signals the RPC run-time library to listen for remote procedure calls. This function will not affect auto-listen interfaces; use RpcServerRegisterIfEx if you need that functionality.
 //RPC_STATUS RpcServerListen(
 // unsigned int MinimumCallThreads,//Hint to the RPC run time that specifies the minimum number of call threads that should be created and maintained in the given server. This value is only a hint and is interpreted differently in different versions of Windows. 
 // unsigned int MaxCalls,//Recommended maximum number of concurrent remote procedure calls the server can execute. To allow efficient performance, the RPC run-time libraries interpret the MaxCalls parameter as a suggested limit rather than as an absolute upper bound.Use RPC_C_LISTEN_MAX_CALLS_DEFAULT to specify the default value.
 // unsigned int DontWait//Flag controlling the return from RpcServerListen. A value of nonzero indicates that RpcServerListen should return immediately after completing function processing. A value of zero indicates that RpcServerListen should not return until the RpcMgmtStopServerListening function has been called and all remote calls have completed.
//);
 status = RpcServerListen(1, 20, FALSE);
 if(status != 0){
  cout<<"RpcServerListen returns: "<<status<<endl;
  return -1;
 }

 cin.get();
 return 0;
}


/************************************************************************/
//    MIDL malloc & free                      
//为满足链接需求编写，没有的话会出现连接错误
void * __RPC_USER MIDL_user_allocate(size_t len)
{
 return (malloc(len));
}

void __RPC_USER MIDL_user_free(void*ptr)
{
 free(ptr);
}

/************************************************************************/
//Interfaces   
//为来自hello.idl中的函数

int HelloProc(PERSON p)
{
	//int response;
	cout<<"嘿！一份小可爱的个人信息已经到来，请注意查收！！"<<endl;
	cout<<"小可爱的编号："<<(p).code<<endl;
	cout<<"小可爱的名字："<<(p).name<<endl;
	cout<<"小可爱的备注信息："<<(p).note<<endl;
	cout<<"小可爱的信息已经处理完成，请及时回复！"<<endl;
	return (int)((p).code);
}

void ShutDown(void)
{
 RPC_STATUS status = 0;

 status = RpcMgmtStopServerListening(NULL);
 if(status != 0){
  cout<<"RpcMgmtStopServerListening returns: "<<status<<"!"<<endl;
 }

 status = RpcServerUnregisterIf(NULL, NULL, FALSE);
 if(status != 0){
  cout<<"RpcServerUnregisterIf returns: "<<status<<"!"<<endl;
 }
}