#include <iostream>
#include <string>
using namespace std;

#include "hello_h.h"


void doRpcCall();
void dealWith();

int main(int argc, char** argv)
{
 int i = 0;
 RPC_STATUS status = 0;

 unsigned char * pszNetworkAddr = NULL;
 unsigned char * pszStringBinding = NULL;

 for(i = 1; i < argc; i++){
  if(strcmp(argv[i], "-ip") == 0){
   pszNetworkAddr = (unsigned char*)argv[++i];
   break;
  }
 }

 //使用TCP方式作为RPC的通道，服务器端口13521（与服务器端一致），第三个参数取NULL则为连接本机服务
 //也可以取IP,域名，severname等
 status = RpcStringBindingCompose(NULL,(RPC_CSTR) "ncacn_ip_tcp",(RPC_CSTR)"192.168.1.115",(RPC_CSTR)"8080",NULL,(RPC_CSTR*)&pszStringBinding);
 if(status != 0){
  cout<<"RpcStringBindingCompose returns: "<<status<<"!"<<endl;
  return -1;
 }

 cout<<"pszStringBinding = "<<pszStringBinding<<endl;
 status = RpcBindingFromStringBinding((RPC_CSTR)pszStringBinding, &hello_IfHandle);
 if(status != 0){
  cout<<"RpcBindingFromStringBinding returns: "<<status<<"!"<<endl;
  return -1;
 }

 doRpcCall();

 status = RpcStringFree((RPC_CSTR*)&pszStringBinding);
 if(status != 0)
  cout<<"RpcStringFree returns: "<<status<<"!"<<endl;

 status = RpcBindingFree(&hello_IfHandle);
 if(status != 0)
  cout<<"RpcBindingFree returns: "<<status<<"!"<<endl;

 cin.get();
 return 0;
}

void dealWith(void){
	PERSON pp;
	int response ;
	while(true){
   cout<<"Please input People's name:(Quit Procedure,Input'quit' or 'exit')"<<endl;
	   cin>>(pp).name;
		//输入exit或者quit退出客户端程序
	   if(strcmp((const char*)(pp).name, "exit") == 0 || strcmp((const char*)(pp).name, "quit") == 0){
				ShutDown();
		}
	   else{
		cout<<"Please input People's id:"<<endl;
		cin>>(pp).code;
		cout<<"Please input People's information:"<<endl;
		cin>>(pp).note;
		response = HelloProc(pp);
		cout<<"嘿！编号为:"<<response<<"的小可爱，你的信息已经被处理了！！"<<endl;
       }
  }
}

//客户端输入字符程序
void doRpcCall(void)
{
	RpcTryExcept{
		dealWith();
	}
	RpcExcept(1){
		unsigned long ulCode = RpcExceptionCode();   
		cout<<"RPC exception occured! code: "<<ulCode<<endl;
	}
	RpcEndExcept
}


//为满足链接需求编写，没有的话会出现连接错误
void * __RPC_USER MIDL_user_allocate(size_t len)   
{   
 return (malloc(len));   
}  

void __RPC_USER MIDL_user_free(void* ptr)   
{   
 free(ptr);   
} 