/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : systeminfo_proc.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��16��
  ����޸�   :
  ��������   : systeminfo_proc.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2014��4��16��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/

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

/*----------------------------------------------*
 * �궨��                                       *
 *----------------------------------------------*/

#ifndef __SYSINFO_PROC_H__
#define __SYSINFO_PROC_H__

#include "common/gbldef.inc"


#include "libxml/Packet.h"

#include <vector>
#include <string>
using namespace std;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

#define VMRSS_LINE 15//VMRSS������
#define PROCESS_ITEM 14//����CPUʱ�俪ʼ������

    //cpu Ӳ����Ϣ
    typedef struct cpuinfo
    {
        char system_type[128];
        char cpu_model[128];
        char BogoMIPS[32];
    } cpu_info;

    //CPU ״̬
    typedef struct cpustatus
    {
        long total;
        float user;
        float nice;
        float system;
        float idle;
    } cpu_status;

    typedef struct          //����һ��occupy�Ľṹ��
    {
        unsigned int user;  //��ϵͳ������ʼ�ۼƵ���ǰʱ�̣������û�̬������ʱ�䣬������ niceֵΪ�����̡�
        unsigned int nice;  //��ϵͳ������ʼ�ۼƵ���ǰʱ�̣�niceֵΪ���Ľ�����ռ�õ�CPUʱ��
        unsigned int system;//��ϵͳ������ʼ�ۼƵ���ǰʱ�̣����ں���̬������ʱ��
        unsigned int idle;  //��ϵͳ������ʼ�ۼƵ���ǰʱ�̣���IO�ȴ�ʱ������������ȴ�ʱ��iowait (12256) ��ϵͳ������ʼ�ۼƵ���ǰʱ�̣�IO�ȴ�ʱ��(since 2.5.41)
    } total_cpu_occupy_t;

    typedef struct
    {
        pid_t pid;//pid��
        unsigned int utime;   //���������û�̬���е�ʱ�䣬��λΪjiffies
        unsigned int stime;   //�������ں���̬���е�ʱ�䣬��λΪjiffies
        unsigned int cutime;  //���������߳����û�̬���е�ʱ�䣬��λΪjiffies
        unsigned int cstime;  //���������ں���̬���е�ʱ�䣬��λΪjiffies
    } process_cpu_occupy_t;

    //memory
    typedef struct meminfo
    {
        char total[20];
        char free[20];
    } mem_info;

    //process memory
    typedef struct processmeminfo
    {
        char mem[20];  /* �����ڴ� */
        char vmem[20]; /* �����ڴ� */
    } process_mem_info;

    extern int AddCPUInfoToSysInfoXML(CPacket * pOutPacket);
    extern int AddDeviceInfoToBoardSearchXML(CPacket * pOutPacket);
    extern int AddFanInfoToSysInfoXML(CPacket * pOutPacket);
    extern int AddMemoryInfoToSysInfoXML(CPacket * pOutPacket);
    extern int AddNetWorkInfoToBoardSearchXML(CPacket * pOutPacket, DOMElement * ItemAccNode);
    extern int AddNetWorkInfoToSysInfoXML(CPacket * pOutPacket);
    extern int AddSystemDateTimeInfoToSysInfoXML(CPacket * pOutPacket);
    extern int BoardSearchCmdProc(char * pcSerialNumber, std::string & outBuff);
    extern int BoardSearchProc(char * pcInBuff, int iInLen, std::string & outBuff);
    extern int BoardSearchRebootCMSProc();
    extern int BoardSearchRebootDBProc();
    extern int BoardSearchRebootKeyBoardProc();
    extern int BoardSearchRebootMediaServiceProc();
    extern int BoardSearchRestoreFactorySettingsProc();
    extern int BoardSearchSetIPAddrProc(CPacket & inPacket, std::string & outBuff);
    extern int CreateXMLHeadResponseForSystemRunState(CPacket** pOutPacket, char * strCmdType, char * pcSerialNumber);
    extern int find_pid_by_name(char* ProcName, int* foundpid);
    extern int GeneratingErrorResponseForSystemRunState(char * strCmdType, char * pcSerialNumber, int iErrorCode, char * strErrorReason, std::string & outBuff);
    extern int GetDeviceInfoProc(char* pcSerialNumber, std::string& outBuff);
    extern int GetEthNameByMac(char* pcMac, char* pEthName);
    extern int getLocalNetInfo(void);
    extern int GetSystemInfoProc(char* pcSerialNumber, std::string& outBuff);
    extern int GetSystemIPAddr(int port);
    extern int GetSystemRunStateProc(const std::string& inBuff, std::string& outBuff);
    extern int GetTaskInfoProc(char* pcSerialNumber, std::string& outBuff);
    extern int GetTSUInfoProc(char* pcSerialNumber, std::string& outBuff);
    extern int GetUserInfoProc(char* pcSerialNumber, std::string& outBuff);
    extern int get_cpu_info(cpu_info* cpuinfo);
    extern unsigned int get_cpu_process_occupy(const pid_t p);
    extern void get_cpu_status(cpu_status* cpu_stat, int process_num);
    extern unsigned int get_cpu_total_occupy();
    extern void get_eth_gateway(char* eth_name, char* gateway_addr);
    extern const char* get_items(const char* buffer, int ie);
    extern void get_mem_info(mem_info* minfo);
    extern float get_pcpu(pid_t p);
    extern int get_phy_mem(const pid_t p);
    extern float get_pmem(pid_t p);
    extern int get_progress_cpu_usage(char* ProcName, float* pfcpu);
    extern int get_progress_memory_usage(char* ProcName, process_mem_info* proc_mem);
    extern int get_total_mem();
    extern int IsIPAddrIsLocalIP(char* strEthName, char* strIPAddr);
    extern int SendSystemDiskErrorToAllClientUser();
    extern int SetIPAddrProc(CPacket& inPacket, std::string& outBuff);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __GBLFUNC_PROC_H__ */