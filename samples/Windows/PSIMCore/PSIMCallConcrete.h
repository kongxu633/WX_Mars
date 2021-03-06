#pragma once
#include "PSIMCall.h"

// 磐石IMCall的具体实现
class CPSIMCallConcrete: public CPSIMCall
{
private:
	CPSIMCallConcrete();

public:
	CPSIMCallConcrete(CPSIMCallBack* pPSIMCallBack);
	virtual ~CPSIMCallConcrete();

	CPSIMCallBack* GetIMPSCallBack();

	// 初始化;
	virtual bool Init();
	// 反初始化;
	virtual bool UnInit();

	// 登录;
	virtual void MsgLogin(IN const char* strAppID,
		IN const char* strAppToken,
		IN const char* strUserID,
		IN const char* strUserName,
		IN const int iDeviceType,
		IN const char* strDeviceToken);
	// 注销;
	virtual void MsgLogout();

	// 创建群组;
	virtual void CreateGroup(IN const PSGroupInfo& groupInfo);
	// 删除群;
	virtual void DeleteGroup(IN const char* strGroupID);

	// 获取群成员;
	//virtual void GetGroupUsers(IN const PSGroupInfo& groupUsers);
	//virtual void GetGroupUsers(const char* strGroupID, const int iPageNum, const int iPageSize);
	// 添加群成员;
	virtual void AddGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iAddCount);
	// 移除群成员;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSUserInfo* pUsers, IN const int iRemoveCount);

	// 添加子群;
	virtual void AddGroupChilds(IN const char* strGroupID, IN const PSGroupInfo* pGroups, IN const int iAddCount);
	// 移除子群;
	virtual void RemoveGroupUsers(IN const char* strGroupID, IN const PSGroupInfo* pUsers, IN const int iRemoveCount);

	// 设置群成员角色
	virtual void SetGroupUserRole(const char* strGroupID);

	// 禁言
	virtual void Shutup(const char* strGroupID);
	// 解禁
	virtual void UnShutup(const char* strGroupID);
	// 获取禁言列表
	virtual void GetShutupList(const char* strGroupID);

	// 邀请群成员
	virtual void InviteGroupUsers(const char* strGroupID);

	// 发送文本消息
	virtual void SendTextMessage(OUT int& iReqID,
		IN const PS_SendMode& eSendMode,
		IN const char* strFrom,
		IN const char* strTo,
		IN const PSString& strContent,
		IN const char* strPushInfo);

	// 获取离线消息;
	virtual void GetOfflineMsgs(IN const PSVector<PSOffMsgDesc>& vecOffMsgDescs);

	// 消息撤回
	virtual void RevokeMsg();

private:
	// Core Back
	CPSIMCallBack*	m_pPSIMCallBack;
};

