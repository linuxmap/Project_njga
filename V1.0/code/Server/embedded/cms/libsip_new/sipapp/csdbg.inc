/******************************************************************************

                  ��Ȩ���� (C), 2001-2013, ������Ѷ�������޹�˾

 ******************************************************************************
  �� �� ��   : csdbg.h
  �� �� ��   : ����
  ��    ��   : yanghaifeng
  ��������   : 2013��4��1��
  ����޸�   :
  ��������   : csdbg.c ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2013��4��1��
    ��    ��   : yanghaifeng
    �޸�����   : �����ļ�

******************************************************************************/
#ifndef __CSDBG_H__
#define __CSDBG_H__

/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <osip2/internal.h>
#include <osip2/osip.h>

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

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/
    /* ��־���� */
#define LOG_ALL     1    /* ��ӡ������־ */

#define LOG_DEBUG   2    /* ��ӡ������־ */
#define LOG_TRACE   3    /* ��ӡ������־ */
#define LOG_INFO    4    /* ��ӡһ����־ */
#define LOG_WARN    5    /* ��ӡ�澯��־ */
#define LOG_ERROR   6    /* ��ӡ������־ */
#define LOG_FATAL   7    /* ��ӡ������־ */

#define LOG_OFF     8    /* �ر���־ */

#define __LOG4SIPSTACK_FUNC__ "X::X()"

extern void SIPDebugTrace(int iLevel, const char* FILENAME, const char* FUNCTIONNAME, int CODELINE, const char* fmt, ...);

#ifdef WIN32   /* vc6��֧�ֿɱ���� modified by chenyu 130705 */
#define SIP_DEBUG_TRACE(x)   
#else
#define SIP_DEBUG_TRACE(level, fmt, args...) \
    SIPDebugTrace(level, __FILE__, __LOG4SIPSTACK_FUNC__, __LINE__, fmt, ##args)
#endif

extern void SIPMessageTrace(int type, int iDirect, char* ipaddr, int port, char* msg);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __CSDBG_H__ */