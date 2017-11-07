/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : rcconfig.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : rcconfig.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __GBLCONFIG_PROC_H__
#define __GBLCONFIG_PROC_H__

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include "../../../common/include/EV9000_CommonManage.h"
#include "libsip.h"
#include "libxml/Packet.h"

#include "common/gbldef.inc"
#include "common/DBOper.h"

#include <vector>
#include <string>

using namespace std;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/

    /* ����IP��ַ�ṹ��Ϣ */
    typedef struct ip_pair_t
    {
        char eth_name[MAX_IP_LEN];       /* ������������ */
        ip_addr_type_t ip_type;          /* ip��ַ���� */
        char local_ip[MAX_IP_LEN];       /* ����IP��ַ */
        int local_port;                  /* ���ض˿ں�*/
    } ip_pair_t;

    /* �������ṹ��Ϣ */
    typedef struct primary_group_t
    {
        char group_id[32 + 4];                  /* ���� ID */
        char group_name[64 + 4];                /* �������ƣ������������(�ɳ���) */
        char parent_id[32 + 4];                 /* �ϼ� ID */
        int iSortID;                            /* ����ID */
        char civil_code[8 + 4];                 /* ����������, 8λ */
        char group_code[MAX_ID_LEN + 4];        /* �������(������֯����)��20λ */
        char parent_code[MAX_ID_LEN + 4];       /* �ϼ��������(������֯����)��20λ */
        int iNeedToUpLoad;                      /* �Ƿ���Ҫ�ϱ����ϼ�ƽ̨ */
        int del_mark;                           /* ɾ����ʶ */
    } primary_group_t;

    /* �߼��豸������Ϣ���� */
    typedef std::map <string, primary_group_t*> PrimaryGroup_MAP;
    typedef std::map <string, primary_group_t*>::iterator PrimaryGroup_Iterator;

    /* �߼��豸�����ϵ��Ϣ�ṹ�� */
    typedef struct _device_group_map_t
    {
        char group_id[32 + 4];                  /* ����ID */
        unsigned int device_index;              /* ��λ���� */
        int iSortID;                            /* ����ID */
        int del_mark;                           /* ɾ����ʶ */
    } device_group_map_t;

    /* �߼��豸�����ϵ��Ϣ���� */
    typedef std::map <unsigned int, device_group_map_t*> DeviceGroupMap_MAP;
    typedef std::map <unsigned int, device_group_map_t*>::iterator DeviceGroupMap_Iterator;

    typedef struct _gbl_conf_t
    {
        unsigned int board_index;                           /* CMS�������� */
        char board_id[MAX_ID_LEN + 4];                      /* CMS ������ */
        char mms_id[MAX_ID_LEN + 4];                        /* MMS ������ */

        char center_code[12];                               /* ���ı��� */

        char province_code[4];                              /* ʡ������,2λ */

        char city_code[8];                                  /* �м�����,4λ */

        char region_code[12];                               /* ���ر���,6λ */

        char civil_code[8 + 4];                             /* ����������� */

        PrimaryGroup_MAP PrimaryGroupList;                  /* ���ػ��������� */
        DeviceGroupMap_MAP DeviceGroupMapList;              /* ���ص��߼��豸�����ϵ���� */

        char trade_code[4];                                 /* ��ҵ���� */
        char type_code[4];                                  /* ���ͱ��� */
        char serial_number[8];                              /* ��� */

        char register_region[12];                           /* ע���� */

        char alarm_server_ip[MAX_IP_LEN];                   /* �澯������ip��ַ */
        char ntp_server_ip[MAX_IP_LEN];                     /* NTP ������ip��ַ */
        char db_server_ip[MAX_IP_LEN];                      /* ���ݿ� ������ip��ַ */

        osip_list_t* pLocalIPAddrList;                      /* ����IP��ַ���� */

        char default_eth_name[MAX_IP_LEN];                  /* Ĭ�ϵ�IP��ַ�������� */

        char cms_name[MAX_128CHAR_STRING_LEN + 4];          /* CMS���� */

        /* SPY */
        char spy_username[MAX_128CHAR_STRING_LEN + 4];      /* telnet ��¼�û��� */
        char spy_password[MAX_128CHAR_STRING_LEN + 4];      /* telnet ��¼���� */
        int spy_port;                                       /* telnet ����˿�*/

        unsigned int iAuthFlag;                             /* ��֤��ʶ:0:����Ҫ��֤��1:��Ҫ��֤ */

        unsigned int uPresetBackTime;                       /* Ԥ��λ�Զ���λʱ�� */
        unsigned int uDeviceUnLockTime;                     /* ��λ�Զ�����ʱ�� */

        unsigned int register_retry_interval;               /* δע��ɹ�������ע��ʱ����, Ĭ��60�� */
        unsigned int registry_cleanuprate;                  /* ע��ˢ�����ڣ�Ĭ��180�� */
        unsigned int session_expires;                       /* �Ự��ʱʱ�䣬Ĭ��300�� */
        unsigned int subscribe_expires;                     /* ���ĳ�ʱʱ�䣬Ĭ��3600�� */
        unsigned int keep_alive_interval;                   /* ������ʱ�䣬Ĭ��60�� */
        unsigned int failed_keep_alive_count;               /* ����ʧ�ܴ�����Ĭ��3�� */
        unsigned int keep_alive_expires;                    /* ���ʱʱ�䣬Ĭ��3���� */
        unsigned int alarm_duration;                        /* �澯��ʱʱ�䣬Ĭ��30�� */

        char shdb_agent_id[MAX_16CHAR_STRING_LEN + 4];      /* �Ϻ��ر���ƽ̨ע��ID */
        char shdb_server_ip[MAX_IP_LEN];                    /* �Ϻ��ر���ƽ̨������IP */
        unsigned int shdb_prex_seconds;                     /* �Ϻ��ر걨��ͼƬ�ϴ�ǰN��, Ĭ��60�� */
        unsigned int shdb_next_seconds;                     /* �Ϻ��ر걨��ͼƬ�ϴ���M�룬Ĭ��60�� */
        unsigned int shdb_interval_seconds;                 /* �Ϻ��ر걨��ͼƬ�ϴ����P�룬Ĭ��3�� */

        unsigned int sys_exit_flag;                         /* ϵͳ�˳���ʶ��0�������˳���1���쳣�˳� */
        unsigned int showcode;                              /* showcode = 0 �ǹ���汾��ShowCode = 1�������� Ϊ����汾*/
    } gbl_conf_t;

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/

#define MIN_REGISTER_RETRY_INTERVAL         60      /* ��С����ע����ʱ��,��λ:�� */
#define MIN_REGISTER_EXPIRE                 3600    /* ��Сע����ʱ��,��λ:�� */
#define MIN_SESSION_EXPIRE                  300     /* ��С�Ựˢ��ʱ��,��λ:�� */
#define MIN_SUBSCRIBE_EXPIRE                3600    /* ��С����ˢ��ʱ��,��λ:�� */
#define MIN_KEEP_ALIVE_INTERVAL             60      /* ��С����ʱ��,��λ:�� */

#define DEFAULT_DEVICE_KEEP_ALIVE_EXPIRES   3       /* �豸Ĭ�ϱ��ʱʱ��,��λ:���� */

#define DEFAULT_PRESET_BACK_TIME            30      /* Ĭ�ϵ�Ԥ��λ�Զ���λʱ��,��λ:�� */
#define DEFAULT_DEVICE_UNLOCK_TIME          60      /* Ĭ�ϵĵ�λ�Զ�����ʱ��,��λ:�� */
#define DEFAULT_ALARM_DURATION              30      /* Ĭ�ϵĸ澯��ʱʱ��,��λ:�� */
#define DEFAULT_TSU_SESSION_EXPIRE          30      /* Ĭ�ϵĺ�TSU�Ự�ı��ʱʱ��,��λ:���� */
#define DEFAULT_FAILED_KEEP_ALIVE_COUNT     3       /* Ĭ�ϱ���ʧ�ܴ��� */

#define DEFAULT_SHDB_DURATION_SECONDS       60      /* �Ϻ��ر걨��ͼƬ�ϴ�Ĭ�ϳ���ʱ��,��λ:�� */
#define DEFAULT_SHDB_INTERVAL_SECONDS       3       /* �Ϻ��ر걨��ͼƬ�ϴ�Ĭ�ϼ��ʱ��,��λ:�� */

    extern int AddGblLogicDeviceGroupToVectorForRoute(vector<string>& GroupIDVector);
    extern int change_conf_to_config_file(char* pcName, char* pcValue);
    extern int change_conf_to_web_config_file(char* pcName, char* pcValue);
    extern int checkExpireDay(char *ExpireDay);
    extern int checklicence();
    extern int checkLoginIPIsSlaveIP(char* host);
    extern int checkTmpLicence();
    extern void check_GBLogicDeviceGroupInfoConfig_need_to_reload(DBOper* pDboper);
    extern void check_GBLogicDeviceGroupMapInfoConfig_need_to_reload(DBOper* pDboper);
    extern int conf_reset(gbl_conf_t* conf, char* pname, char* pvalue, int iRefresh);
    extern int createNewTmpLicence();
    extern int debug_device_map_group_info_list_lock(const char* file, int line, const char* func);
    extern int debug_device_map_group_info_list_unlock(const char* file, int line, const char* func);
    extern int debug_primary_group_info_list_lock(const char* file, int line, const char* func);
    extern int debug_primary_group_info_list_unlock(const char* file, int line, const char* func);
    extern char* default_eth_name_get();
    extern int DelGblLogicDeviceGroupInfoByDelMark();
    extern int DelGblLogicDeviceGroupMapInfoByDelMark();
    extern void device_group_map_free(device_group_map_t* device_group_map);
    extern int device_group_map_init(device_group_map_t** device_group_map);
    extern int device_map_group_add(char* group_id, unsigned int device_index, int sort_id);
    extern int device_map_group_info_list_lock();
    extern int device_map_group_info_list_unlock();
    extern int GBLogicDeviceGroupInfoConfig_db_refresh_proc();
    extern int GBLogicDeviceGroupMapInfoConfig_db_refresh_proc();
    extern void gbl_conf_free();
    extern int gbl_conf_init();
    extern int gbl_conf_load();
    extern int gbl_conf_reload();
    extern char* GetGBLogicDeviceCivilCode(unsigned int device_index, DBOper* pDbOper);
    extern primary_group_t* GetPrimaryGroupInfoByGBLogicDeviceIndex(unsigned int device_index, DBOper* pDbOper);
    extern char *GetRegPasswd(char *name);
    extern device_group_map_t* get_device_map_group(unsigned int device_index);
    extern char* get_ip_eth_name(char* server_ip);
    extern ip_addr_type_t get_local_ip_type(char* eth_name);
    extern primary_group_t* get_primary_group(char* group_id);
    extern int ip_pair_add(char* eth_name, ip_addr_type_t ip_type, char* local_ip, int local_port);
    extern int ip_pair_clone(const ip_pair_t* uparam, ip_pair_t** dest);
    extern void ip_pair_free(ip_pair_t* ip_pair);
    extern int ip_pair_init(ip_pair_t** ip_pair);
    extern int is_need_auth();
    extern int load_file_config();
    extern int local_alarm_duration_get();
    extern char* local_civil_code_get();
    extern char* local_cms_id_get();
    extern unsigned int local_cms_index_get();
    extern char* local_cms_name_get();
    extern int local_device_unlock_time_get();
    extern int local_failed_keep_alive_count_get();
    extern char* local_ip_get(char* eth_name);
    extern int local_keep_alive_expires_get();
    extern int local_keep_alive_interval_get();
    extern char* local_mms_id_get();
    extern int local_port_get(char* eth_name);
    extern int local_preset_back_time_get();
    extern int local_register_retry_interval_get();
    extern int local_registry_cleanuprate_get();
    extern int local_session_expires_get();
    extern int local_subscribe_expires_get();
    extern char* ntp_server_ip_get();
    extern int primary_group_add(char* group_id, char* group_name, char* civil_code, char* group_code, char* parent_code, int sort_id, char* parent_id, int iNeedToUpLoad);
    extern void primary_group_free(primary_group_t* primary_group);
    extern int primary_group_info_list_lock();
    extern int primary_group_info_list_unlock();
    extern int primary_group_init(primary_group_t** primary_group);
    extern void refresh_config_file();
    extern int reload_file_config();
    extern int SetGblLogicDeviceGroupDelFlag(int iDelFlag);
    extern int SetGblLogicDeviceGroupMapDelFlag(int iDelFlag);
    extern char* shdb_agent_id_get();
    extern int shdb_interval_sec_get();
    extern int shdb_next_sec_get();
    extern int shdb_prex_sec_get();
    extern char* shdb_server_ip_get();
    extern void show_system_civil_info(int sock);
    extern void show_system_gbl_param(int sock);
    extern void show_system_group_map_info(int sock);
    extern void show_system_ip_info(int sock);
    extern int sys_exit_flag_get();
    extern int sys_show_code_flag_get();
    extern int write_default_config_file();
    extern int write_default_web_config_file();

#ifdef ENABLE_DEBUG_LOCK
#define PRIMARY_GROUP_SMUTEX_LOCK() debug_primary_group_info_list_lock(__FILE__, __LINE__, __func__)
#define PRIMARY_GROUP_SMUTEX_UNLOCK() debug_primary_group_info_list_unlock(__FILE__, __LINE__, __func__)
#define DEVICE_MAP_GROUP_MAP_SMUTEX_LOCK() debug_device_map_group_info_list_lock(__FILE__, __LINE__, __func__)
#define DEVICE_MAP_GROUP_MAP_SMUTEX_UNLOCK() debug_device_map_group_info_list_unlock(__FILE__, __LINE__, __func__)
#else
#define PRIMARY_GROUP_SMUTEX_LOCK() primary_group_info_list_lock()
#define PRIMARY_GROUP_SMUTEX_UNLOCK() primary_group_info_list_unlock()
#define DEVICE_MAP_GROUP_MAP_SMUTEX_LOCK() device_map_group_info_list_lock()
#define DEVICE_MAP_GROUP_MAP_SMUTEX_UNLOCK() device_map_group_info_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __RCCONFIG_H__ */