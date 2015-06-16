/*
 * driver.h
 *
 *  Created on: 2015��5��16��
 *      Author: Sunday
 */

#ifndef APP_INCLUDE_PUSH_H_
#define APP_INCLUDE_PUSH_H_

#include <c_types.h>


enum CONN_STATUS {
	STATUS_CONNECTING = 0,
	STATUS_DNS_LOOKUP = 1,
	STATUS_CONNECTED = 2,
	STATUS_DISCONNECTED = 3
};



enum VERTYPE {
	VER_AT = 0,
	VER_NODEMCU = 1,
	VER_SDK = 2,
	VER_OTHER = 3,
};


typedef void(*msg_cb)(uint8* pdata, uint32 len);

/*
 * ע�ᵽespushƽ̨��appid��appkeyΪ�豸�����ʶ���������appkeyΪ32�ֽ��ַ�����ʽ
 * vertype������ enum VERTYPE��ѡ�VER_AT��VER_NODEMCUΪ AT�̼���NodeMCU�̼�ר�ã����ÿ��ܵ��´���
 * devid����Ϊ�豸Ψһʶ���룬����ʹ��оƬ��chipid�����ж��壬������NULL����ԣ�ϵͳ���Զ�ʹ��оƬchipid��ΪΨһʶ����
 * msgcb����Ϊ�յ����ݵĻص���
 */
void ICACHE_FLASH_ATTR push_register(uint32 appid, char appkey[32], char devid[32], enum VERTYPE type, msg_cb msgcb);

/*
 * ��ƽ̨�Ͽ����ӣ����ӶϿ����޷��ٴη������ݣ�Ҳ���������յ�ƽ̨��֪ͨ��Ҫ����ƽ̨��������ʹ��push_regist���µ��롣
 */
void ICACHE_FLASH_ATTR push_unregister();

/*
 * ��������������
 */
sint8 ICACHE_FLASH_ATTR push_msg(uint8* buf, uint16 len);

/*
 * ��������״̬, �ο� enum CONN_STATUS �Ķ��塣
 */
sint8 ICACHE_FLASH_ATTR push_server_connect_status();


#endif /* APP_INCLUDE_PUSH_H_ */
