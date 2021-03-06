#pragma once
#include "PSIMCallBack.h"
//#include <vector>

// 终端SDK 访问的抽象类;
class CPSIMCall
{
public:
	CPSIMCall() {};
	virtual ~CPSIMCall() {};

	// 初始化;
	virtual bool Init() = 0;
	// 反初始化;
	virtual bool UnInit() = 0;

	// 登录;
	virtual void MsgLogin(IN const char* strAppID,
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const int iDeviceType,
		IN const char* strDeviceToken) = 0;
	// 注销;
	virtual void MsgLogout() = 0;

	// 查询已加入群的列表;
	//virtual void GetGroupList(IN const char* strUserID) = 0;

	// 添加群;
	virtual void CreateGroup(IN const PSGroupInfo& groupInfo) = 0;
	// 删除群;
	virtual void DeleteGroup(IN const char* strGroupID) = 0;
	// 修改群信息;
	//virtual void UpdateGroup(IN const PSGroupInfo& groupInfo) = 0;
	// 查询群信息;
	//virtual void GetGroupInfo(IN const char* strGroupID) = 0;

	// 获取群成员;
	//virtual void GetGroupUsers(IN const PSGroupInfo& groupUsers) = 0;
	// 添加群成员;
	virtual void AddGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iAddCount) = 0;
	// 移除群成员;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iRemoveCount) = 0;

	// 添加子群;
	virtual void AddGroupChilds(IN const char* strGroupID, IN const PSGroupInfo* pGroups, IN const int iAddCount) = 0;
	// 移除子群;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSGroupInfo* pUsers, IN const int iRemoveCount) = 0;

	// 管理员同意、拒绝
	// 管理员踢人
	// 群主设置、取消管理员

	// 设置群成员角色
	//virtual void SetGroupUserRole() = 0;

	//// 禁言
	//virtual void Shutup(const char* strGroupID) = 0;
	//// 解禁
	//virtual void UnShutup(const char* strGroupID) = 0;
	//// 获取禁言列表
	//virtual void GetShutupList(const char* strGroupID) = 0;

	//// 邀请群成员
	//virtual void InviteGroupUsers(const char* strGroupID) = 0;

	// 发送文本消息
	virtual void SendTextMessage(OUT int& iReqID,
		IN const PS_SendMode& eSendMode,
		IN const char* strFrom,
		IN const char* strTo,
		IN const PSString& strContent,
		IN const char* strPushInfo) = 0;

	// 获取离线消息;
	virtual void GetOfflineMsgs(IN const PSVector<PSOffMsgDesc>& vecOffMsgDescs) = 0;

	// 消息撤回
	virtual void RevokeMsg() = 0;
};

class CPSIMCallFactory
{
public:
	// 创建时,需要传递回调接口;
	static void CreateInstance(CPSIMCallBack* pCallBack);

	// 获取 m_pInstance;
	static CPSIMCall* GetInstance();

	static const char* GetPSIMVersion();

	// 释放 m_pInstance;
	static void ReleaseInstance();

private:
	static CPSIMCall* m_pInstance;
};

#define AfxGetPSIMCall	CPSIMCallFactory::GetInstance