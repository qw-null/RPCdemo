//����rpcrt4.lib����������������Ϊ��
//�Ҽ��������ԣ���Linker->Input->Additional Dependencies�����rpcrt4.lib
//�����޷�����ɹ�

#include <iostream>
using namespace std;

#include "hello_h.h"

int main(void)
{
 RPC_STATUS status = 0;


 //RpcServerUseProtseqEp()��⣺
 //The RpcServerUseProtseqEp function tells the RPC run-time library to use the specified protocol sequence combined with the specified endpoint for receiving remote procedure calls.
//RPC_STATUS RpcServerUseProtseqEp(
//RPC_CSTR     Protseq,  //Pointer to a string identifier of the protocol sequence to register with the RPC run-time library.
// unsigned int MaxCalls,//Backlog queue length for the ncacn_ip_tcp protocol sequence. All other protocol sequences ignore this parameter. Use RPC_C_PROTSEQ_MAX_REQS_DEFAULT to specify the default value.
//  RPC_CSTR   Endpoint,//Pointer to the endpoint-address information to use in creating a binding for the protocol sequence specified in the Protseq parameter.
//  void     *SecurityDescriptor//Pointer to an optional parameter provided for the security subsystem. Used only for ncacn_np and ncalrpc protocol sequences. All other protocol sequences ignore this parameter. Using a security descriptor on the endpoint in order to make a server secure is not recommended. This parameter does not appear in the DCE specification for this API.
//);
 
 //ʹ��TCP��ʽ��ΪRPC��ͨ�����󶨶˿ں�13521
 status = RpcServerUseProtseqEp((RPC_CSTR)"ncacn_ip_tcp",RPC_C_PROTSEQ_MAX_REQS_DEFAULT,(RPC_CSTR)"8080",NULL);
 if(status != 0){
  cout<<"RpcServerUseProtseqEp returns: "<<status<<endl;
  return -1;
 }

 // RpcServerRegisterIfEx()��⣺
//The RpcServerRegisterIfEx function registers an interface with the RPC run-time library.
//RPC_STATUS RpcServerRegisterIfEx(
//  RPC_IF_HANDLE      IfSpec,//MIDL-generated structure indicating the interface to register.//ʹ���������Զ������ļ�hello_h.h��
//  UUID               *MgrTypeUuid,//Pointer to a type UUID to associate with the MgrEpv parameter. Specifying a null parameter value (or a nil UUID) registers IfSpec with a nil-type UUID.
//  RPC_MGR_EPV        *MgrEpv,//Manager routines' entry-point vector (EPV). To use the MIDL-generated default EPV, specify a null value. For more information, please see RPC_MGR_EPV.
//  unsigned int       Flags,//Flags. For a list of flag values, see Interface Registration Flags.
//  unsigned int       MaxCalls,//If the number of concurrent calls is not a concern, you can achieve slightly better server-side performance by specifying the default value using RPC_C_LISTEN_MAX_CALLS_DEFAULT. Doing so relieves the RPC run-time environment from enforcing an unnecessary restriction.
//  RPC_IF_CALLBACK_FN *IfCallback//Security-callback function, or NULL for no callback. Each registered interface can have a different callback function. See Remarks for more details.
//);

//��hello_h.h�ļ��п��Կ���hello.idl��������Ľӿ�ʵ�壬һ��ȫ�־��������handle_t��
 //�Լ��ͻ��������˵Ľӿھ����INTERFACENAME_v1_0_c_ifspec���ͻ���ʹ�ã���INTERFACENAME_v1_0_s_ifspec����������ʹ�ã���

 //��windowsXP SP2��ʼ����ǿ��ȫ�Ե�Ҫ������õ�RpcServerRegisterIf()ע��ӿڵĻ�
 //�ͻ��˵��û����RpcExceptionCode()==5,��AccessDenied�Ĵ�����ˣ�������
 //RpcServerRegisterIfEx()��RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,��־����ͻ���ֱ�ӵ���
 //status = RpcServerRegisterIf(INTERFACENAME_v1_0_s_ifspec, NULL, NULL);
 status = RpcServerRegisterIfEx(INTERFACENAME_v1_0_s_ifspec,NULL,NULL,RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,0,NULL);
 if(status != 0){
  cout<<"RpcServerRegisterIf returns: "<<status<<endl;
  return -1;
 }

 cout<<"Rpc Server Begin Listening..."<<endl;

 //RpcServerListen()��⣺
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
//Ϊ�������������д��û�еĻ���������Ӵ���
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
//Ϊ����hello.idl�еĺ���

int HelloProc(PERSON p)
{
	//int response;
	cout<<"�٣�һ��С�ɰ��ĸ�����Ϣ�Ѿ���������ע����գ���"<<endl;
	cout<<"С�ɰ��ı�ţ�"<<(p).code<<endl;
	cout<<"С�ɰ������֣�"<<(p).name<<endl;
	cout<<"С�ɰ��ı�ע��Ϣ��"<<(p).note<<endl;
	cout<<"С�ɰ�����Ϣ�Ѿ�������ɣ��뼰ʱ�ظ���"<<endl;
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