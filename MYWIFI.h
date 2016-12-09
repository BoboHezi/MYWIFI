#ifndef MYWiFi_h
#define MYWiFi_h

#include "Arduino.h"
#include "SoftwareSerial.h"

class MYWIFI{
public:
	MYWIFI(void);
	static void Reset();						//重启模块
	static bool Begin(String ssid,String pwd);	//连接至网络
	static String IPConfig();					//IPConfig
	static bool Conf(String AT,int delay);		//设置简单命令
	static bool Conf(String AT,String END,int delay);
	static bool Conf(String AT,String success,String fail,int delay);
	
	static bool TCPSERVER(void);				//启动TCP服务(333端口)
	static bool TCPSERVER(int port);			//启动TCP服务(自选端口)
	static bool TCPCLIENT(String ip,int port);	//连接至TCP服务器

	static bool UDPSERVER(int targetport,int localport);	//启动UDP服务
	static bool UDPSEND(String ip,int port,String msg);	//发送UDP报文

private:
	static void init(void);
};

#endif