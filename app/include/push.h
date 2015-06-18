/*
 * driver.h
 *
 *  Created on: 2015��5��16��
 *      Author: Sunday
 */

#ifndef APP_INCLUDE_PUSH_H_
#define APP_INCLUDE_PUSH_H_

#include <c_types.h>


/*
 * �ͻ�������ֵ��uint8�ͣ���������ֵ����255��������Ч��
 */
enum VERTYPE {
	VER_UNKNOWN = 0,
	VER_AT = 1,
	VER_NODEMCU = 2,
	VER_SDK = 3,
	VER_OTHER = 4,
};


/*
 * ���ݻص�, pdataΪ�������ݻ�������lenΪ���ݳ��ȣ��ص��������յ��������ݺ��첽���á�
 */
typedef void(*msg_cb)(uint8* pdata, uint32 len);

/*
 * ATָ��Զ��ִ�лص�, �յ�ATָ���Ŀǰ��ͬ��ִ��
 */
typedef void(*atcmd_cb)(uint8* atcmd, uint32 len);
void ICACHE_FLASH_ATTR espush_atcmd_cb(atcmd_cb func);

/*
 * LuaԶ��ִ�лص�
 */
typedef void(*luafile_cb)(uint8* filebuf, uint32 len);
void ICACHE_FLASH_ATTR espush_luafile_cb(luafile_cb func);


/*
 * appid �� appkeyΪƽ̨����ֵ
 * devid Ϊ�豸Ψһ��־�룬32�ֽڣ���ʹ��uuid�Զ�����
 * ��������֣�Ϊ��ҵ���־����ʹ�÷����SDK�Ե����豸����Ψһ��λ
 */
typedef struct push_config_t {
	uint32 appid;
	uint8 appkey[32];
	uint8 devid[32];
	enum VERTYPE vertype;
	msg_cb msgcb;
}push_config;


enum CONN_STATUS {
	STATUS_CONNECTING = 0,
	STATUS_DNS_LOOKUP = 1,
	STATUS_CONNECTED = 2,
	STATUS_DISCONNECTED = 3
};


/* flash map, 2nd boot, user app
 */
typedef struct regist_info_t {
	uint8 flashmap;
	uint8 second_boot;
	uint8 boot_app;
	uint8 _pad;
}regist_info_s;


/*
 * ע�ᵽespushƽ̨��appid��appkeyΪ�豸�����ʶ���������appkeyΪ32�ֽ��ַ�����ʽ
 * vertype������ enum VERTYPE��ѡ�VER_AT��VER_NODEMCUΪ AT�̼���NodeMCU�̼�ר�ã����ÿ��ܵ��´���
 * devid����Ϊ�豸Ψһʶ���룬����ʹ��оƬ��chipid�����ж��壬������NULL����ԣ�ϵͳ���Զ�ʹ��оƬchipid��ΪΨһʶ����
 * msgcb����Ϊ�յ����ݵĻص���
 */
void ICACHE_FLASH_ATTR espush_register(uint32 appid, char appkey[32], char devid[32], enum VERTYPE type, msg_cb msgcb);


/*
 * ���͵Ĺ̼�ע�����ݳ�ʼ�����ο� regist_info_s �Ķ��塣
 * ��Ҫ�ǹ̼� 2nd boot���̼�SPI_SIZE�ȡ�
 */
void ICACHE_FLASH_ATTR espush_init_regist_info(regist_info_s* info);


/*
 * ��ƽ̨�Ͽ����ӣ����ӶϿ����޷��ٴη������ݣ�Ҳ���������յ�ƽ̨��֪ͨ��Ҫ����ƽ̨��������ʹ��push_regist���µ��롣
 */
void ICACHE_FLASH_ATTR espush_unregister();

/*
 * ��������������
 */
sint8 ICACHE_FLASH_ATTR espush_msg(uint8* buf, uint16 len);

/*
 * ��������״̬, �ο� enum CONN_STATUS �Ķ��塣
 */
sint8 ICACHE_FLASH_ATTR espush_server_connect_status();


#endif /* APP_INCLUDE_PUSH_H_ */
