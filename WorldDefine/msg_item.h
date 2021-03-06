//-----------------------------------------------------------------------------
// Copyright (c) 2004 TENGWU Entertainment All rights reserved.
// filename: msg_item.h
// author: 
// actor:
// data: 2008-07-21
// last:
// brief: 客户端和服务器端间消息 -- 物品/装备相关
//-----------------------------------------------------------------------------
#pragma once

#include "msg_common_errorcode.h"
#include "ItemDefine.h"
#include "AvatarAtt.h"

#pragma pack(push, 1)
//----------------------------------------------------------------------------
// 错误码枚举
//----------------------------------------------------------------------------
enum
{
	// 该部分放到msg_common_errorcode.h中，以便各模块通用
	//E_Item_LevelLimit				= 9,		// 等级不满足要求
	//E_Item_SexLimit					= 10,		// 性别不满足要求
	//E_Item_ClassLimit				= 11,		// 职业不满足要求
	//E_Item_TalentLimit				= 12,		// 天资不满足要求
	//E_Item_ZoneRepLimit				= 13,		// 氏族声望不满足要求
	//E_Item_OtherRepLimit			= 14,		// 其他声望不满足要求
	//E_Item_RoleStatusLimit			= 15,		// 玩家状态(战斗，非战斗)不满足要求
	//E_Item_AttA_Limit				= 16,		// 一级属性不满足

	E_Equip_OnFailed				= 100,		// 装备失败
	E_Equip_NotRing					= 101,		// 装备不是ring
	E_Equip_InvalidPos				= 102,		// 装备栏位与装备类型要求栏位不符
	E_Equip_NotRingPos				= 103,		// 装备栏位中移动的目标位置不是ring栏位
	E_Equip_SamePos					= 104,		// 目标位置与当前位置同
	E_Equip_NotIdentify				= 105,		// 装备没有鉴定
	E_Equip_WeaponPos_Overlap		= 106,		// 武器位置重复
	E_Equip_Idendtifed				= 107,		// 武器已鉴定过
	E_Equip_Guard_DeadPunish		= 108,		// 装备具有死亡守护特殊属性，角色死亡不掉落
	E_Equip_Lock					= 109,		// 锁定物品
	E_Equip_VocationLimit			= 110,		// 该职业不能装备该装备
	E_Equip_CondenseLimit			= 111,		// 神格限制，不能装备

	E_BagPsd_Exist					= 150,		// 已设密码
	E_BagPsd_NoExist				= 151,		// 未设密码
	E_BagPsd_SafeCode_Error			= 152,		// 安全码错误
	E_BagPsd_Error					= 153,		// 密码错误
	E_BagPsd_OK						= 154,		// 密码正确

    E_Dye_OtherItem                 = 170,      // 只能对时装进行染色
    E_Dye_Exist                     = 171,      // 该时装已为该颜色，不需染色
    E_Dye_LvLimit                   = 172,      // 染料等级不足
	E_Dye_NotExist					= 173,		// 装备或者染料不存在

	E_GoldStone_Success				= 180,		// 点金石操作成功
	E_GoldStone_SrcItemNotExist		= 181,		// 点金石原料不存在
	E_GoldStone_NoConfigFile		= 182,		// 点金石服务器端配置文件不存在
	E_GoldStone_CreateDestItemFail	= 183,		// 创建物品失败
	E_GoldStone_MissingMatch		= 184,		// 待点化物品类型与点金石不匹配
	E_GoldStone_OtherError			= 185,		// 其他未知错误
	E_GoldStone_BagIsFull			= 186,		// 背包已满

	E_FabaoFeeding_NoFood			= 187,		// 没有妖精食物
	E_FabaoFeeding_NoFabao			= 188,		// 没有佩戴妖精
	E_FabaoFeeding_FabaoLevelLimit	= 189,	// 妖精等级不足30级
	E_FabaoFeeding_FoodLimit		= 190,		// 妖精等级与食物不匹配
	E_FabaoFeeding_Full				= 191,		// 妖精心情满，不需要吃食物

	E_FabaoStoreExp_LvlLimit			= 192,	// 妖精级别不足40级，不能进行妖精经验相关操作
	E_FabaoStoreExp_NoExpBall		= 193,  // 经验球不存在
	E_FabaoStoreExp_NoFabao			= 194,	// 没有佩戴妖精
	E_FabaoStoreExp_NoEnoughExp		= 195,	// 妖精封印经验值不足
	E_FabaoStoreExp_BagFull			= 196,	// 背包已满
	E_FabaoStoreExp_BallBinded		= 197,	// 水晶球已经约定
	E_FabaoStoreExp_NoExpPililar		= 198,	// 经验丹不存在
	E_FabaoStoreExp_NotYourExpPililar		= 199,	// 经验丹不属于玩家
	E_FabaoStoreExp_ExpPililarUseTimesLimit		= 200,	// 经验丹使用次数超过20次

	E_FabaoMating_RoleNotOnline					= 201,	// 对方不在线
	E_FabaoMating_QltyLow							= 202,	// 品级不足橙色
	E_FabaoMating_QualLow							= 203,	// 资质太低
	E_FabaoMating_CannotMating					= 204,	// 不可配对
	E_FabaoMating_BirthTimesLow					= 205,	// 配对次数限制
	E_FabaoMating_LevelLow						= 206,	// 妖精等级不足
	E_FabaoMating_OtherBagFull					= 207,	// 对方背包满
	E_FabaoMating_NotInGiveBirth					= 208,	// 还没有进入生育期
	E_FabaoMating_CannotPutIn_ErrStatus			= 209,	// 妖精状态不对，不能放入
	E_FabaoFeeding_PregnancyTimeZero				= 210,	// 妖精孕育时间为0不需要再减少
	E_FabaoFeeding_RestTimeZero					= 211,	// 妖精休息时间为0不需要再减少
	E_FabaoFeeding_MatingPregnancyCDTimeLT1h	= 212,	// 妖精孕期时间短于1小时
	E_FabaoFeeding_MatingRestCDTimeLT1h			= 213,	// 妖精休息时间短于1小时
	E_FabaoMating_DistanceTooFar					= 214,	// 妖精配对，距离太远，hh
	E_FabaoMating_NotOnline						= 215,	// 妖精配对，对方不在线

	E_FabaoFeeding_NotBirthFabao				= 216, // 不是可以生育的妖精，不能提升繁育次数、

	E_EquipGrow_ClipsInvalid	=	217, // 器魂碎片无效
	E_EquipGrow_TimesInvalid	=	218, // 输入的成长次数不合法
	E_EquipGrow_ReachTop		= 219, // 无法继续成长
	E_EquipGrow_Error	= 220, // 发生未知错误
	E_EquipGrow_EquipInvalid = 221,

	E_EquipGrowTrans_OldEquipInvalid = 222,
	E_EquipGrowTrans_NewEquipInvalid = 223,
	E_EquipGrowTrans_PositionNoMatch = 224,
	E_EquipGrowTrans_NewEquipLevelLimit = 225,
	E_EquipGrowTrans_IMInvalid = 226,
	E_EquipGrowTrans_Error = 227,

	E_EquipGrowDec_EquipInvalid = 230,
	E_EquipGrowDec_IMInvalid = 231,
	E_EquipGrowDec_NoStar = 232,

	E_EquipPerfectGrow_IMInvalid = 240,		//道具不存在或者类型不对
	E_EquipPerfectGrow_EquipInvalid = 241,	//装备不存在或者装备没有成长属性
	E_EquipXiStar_IMInvalid	= 242,			//道具不存在或者类型不对
	E_EquipXiStar_EquipInvalid = 243,		//装备不存在或者装备类型不对
	E_EquipXiStar_NumNotEnough = 244,		//紫星数量不足
	E_EquipXStar_TimeLimitEquip = 245,		//时限装备
	E_EquipPerfectGrow_TimeLimit = 246,		//时限装备

	E_NotHolyStrengthItem = 250,			//不是圣灵提升吞噬等级的道具
	E_NotHolyItem		  = 251,			//不是圣灵
	E_HolyEatNumMax		  = 252,			//扩到最大了，不能再扩了

	E_NotHolyEquipmentNumber = 253,			//不是提升圣灵可装备圣纹数量的道具
	E_HolyEquipmentNumberMax = 254,			//圣灵可装备圣纹数量已达到最大
};

//----------------------------------------------------------------------------
// 装备穿戴相关消息(注意结构中字段顺序最好保证内存对齐)
//----------------------------------------------------------------------------
CMD_START(NC_Equip)	// 装备
	EEquipPos	ePosDst;		// 装备部位(注意戒指装备部位，客户端需做判断处理)
	INT64		n64Serial;		// 装备64位序列号
CMD_END

CMD_START(NS_Equip) // 反回装备结果，相关影响由其他消息处理
	DWORD		dwErrorCode;
	INT64		n64Serial;		// 装备64位序列号
CMD_END

CMD_START(NC_Unequip)
	EEquipPos	eType;			// 武器位置
	INT16		n16PosDst;		// 待放入背包中位置
	INT16		n16Dummy;		// 对齐用
	INT64		n64Serial;		// 装备64位序列号
CMD_END

CMD_START(NS_Unequip)
	EEquipPos	eType;			// 武器位置
	DWORD		dwErrorCode;
	INT64		n64Serial;		// 装备64位序列号
CMD_END

CMD_START(NC_SwapWeapon)
CMD_END

CMD_START(NS_SwapWeapon)
	DWORD		dwErrorCode;
CMD_END

CMD_START(NS_AvatarEquipChange)	// 武器外观变化
	DWORD			dwRoleID;
	tagEquipDisplay	EquipDisplay;	// 装备外观
CMD_END

CMD_START(NS_EquipEffectChange)	// 武器挂载效果变化
	DWORD			dwRoleID;
	BYTE			byDisplayPos;	// 模型位置
	BYTE			byEquipEffect;	// 挂载效果
CMD_END

CMD_START(NC_IdentifyEquip)	// 武器鉴定
	INT64		n64SerialReel;	// 鉴定卷轴
	INT64		n64SerialEquip;	// 装备
CMD_END

CMD_START(NS_IdentifyEquip)	// 武器鉴定
	DWORD		dwErrorCode;
	INT64		n64Serial;
CMD_END

CMD_START(NS_EquipChange)
	INT64			n64Serial;
	tagEquipSpec	equipSpec;
CMD_END

CMD_START(NS_EquipSingleChange) //单个属性变化
tagEquipSingleSpec			equipSingleSpec;
CMD_END


CMD_START(NS_SuitEffect)	// 套装特效改变
	DWORD		dwRoleID;
	DWORD		dwSuitEffectID;
CMD_END

CMD_START(NS_SuitNum)		// 套装个数改变
	DWORD		dwSuitID;
	INT8		n8Num;
	INT8		n8Dummy[3];
CMD_END

//----------------------------------------------------------------------------
// 物品位置发生变化
//----------------------------------------------------------------------------
CMD_START(NC_ItemPosChange) // 物品位置移动 -- 同一个容器内
	EItemConType	eConType;		// 容器类型
	INT64			n64Serial;		// 移动位置的物品
	INT16			n16Num;			// 移动物品的个数(0表示全部移动)
	INT16			n16PosDst;		// 物品移动的目标位置
	DWORD			dwNPCID;		// 职能NPC ID(现在只有仓库使用)
CMD_END

CMD_START(NS_ItemPosChange) // 物品位置移动 -- 同一个容器内
	EItemConType	eConType;		// 容器类型
	INT64			n64Serial1;		// 移动位置的物品1
	INT64			n64Serial2;		// 受影响物品2, 当为GT_INVALID时, 表示将物品1移动到一个空位
	INT16			n16PosDst1;		// 物品1移动的目标位置
	INT16			n16PosDst2;		// 物品2移动的目标位置
	INT16			n16Num1;		// 物品1最终个数 -- 当该值为0时,需将该物品删除,服务器不另发消息
	INT16			n16Num2;		// 物品2最终个数
	BOOL			bCreateItem;	// n64Serial2是否为新创建的物品堆 -- 为新建堆时，需客户端处理，服务器不另发消息
CMD_END

CMD_START(NC_ItemPosChangeEx) // 物品位置移动 -- 不同容器内
	EItemConType	eConTypeSrc;	// 源容器类型
	INT64			n64Serial1;		// 移动位置的物品1
	EItemConType	eConTypeDst;	// 目的容器类型
	INT16			n16PosDst;		// 物品1移动的目标位置,为GT_INVALID时表示没有指定目标位置
	INT16			n16Dummy;
	DWORD			dwNPCID;		// 职能NPC ID(现在只有仓库使用)
CMD_END

CMD_START(NS_ItemPosChangeEx) // 物品位置移动 -- 不同容器内
	EItemConType	eConTypeSrc1;	// 容器类型 -- n64Serial1的原容器
	EItemConType	eConTypeSrc2;	// 容器类型 -- n64Serial2的原容器
	EItemConType	eConTypeDst1;	// 容器类型 -- n64Serial1的目标容器
	EItemConType	eConTypeDst2;	// 容器类型 -- n64Serial2的目标容器
	INT16			n16PosDst1;		// 物品1移动的目标位置
	INT16			n16PosDst2;		// 物品2移动的目标位置
	INT64			n64Serial1;		// 移动位置的物品1, 当为GT_INVALID时, 表示物品2移动到一个空位
	INT64			n64Serial2;		// 移动位置的物品2, 当为GT_INVALID时, 表示物品1移动到一个空位
	INT16			n16Num1;		// 物品1最终个数 -- 当该值为0时,需将该物品删除,服务器不另发消息
	INT16			n16Num2;		// 物品2最终个数
CMD_END

CMD_START(NC_ItemReorder)	// 行囊整理
	EItemConType	eContainerType;	// 容器类型
	DWORD			dwNPCID;		// GT_INVALID时，为仓库整理；否则为背包整理
	INT16			n16ItemNum;		// 物品个数
	INT16			n16Index[1];	// 排序前物品在容器中的位置，当前数组下标为排序后顺序
CMD_END

CMD_START(NS_ItemReorder)
	DWORD			dwErrorCode;
	EItemConType	eConType;		// 容器类型
	INT16			n16ItemNum;		// 物品个数
	INT16			n16OldIndex[1];	// 当前数组下标为排序后顺序
CMD_END

CMD_START(NC_ItemReorderEx)	// 行囊整理
	EItemConType	eContainerType;	// 容器类型
	DWORD			dwNPCID;		// GT_INVALID时，为仓库整理；否则为背包整理
	INT16			n16ItemNum;		// 物品个数
	BYTE			byData[1];		// tagItemOrder
CMD_END

CMD_START(NS_ItemReorderEx)
	DWORD			dwErrorCode;
	EItemConType	eConType;		// 容器类型
	INT16			n16ItemNum;		// 物品个数
	BYTE			byData[1];		// tagItemOrder
CMD_END


//----------------------------------------------------------------------------
// 物品位置发生变化
//----------------------------------------------------------------------------
CMD_START(NC_GroundItem)
	INT64			n64Serial;
CMD_END

CMD_START(NS_ItemAdd)
//	DWORD			dwErrorCode;
	INT64			n64Serial;
	EItemConType	eConType;
	INT16			n16Index;		// 容器中位置下标
	INT16			n16Num;			// 如果是可堆叠物品,则为该堆总数
	bool			bOverlap;		// 重叠物品是否放入已有堆，如果true，需考虑释放内存
CMD_END

CMD_START(NS_NewItemAdd)
	tagItem			Item;
CMD_END

CMD_START(NS_NewEquipAdd)
	tagEquip		Equip;
CMD_END

CMD_START(NC_ItemRemove)
	EItemConType	eConType;
	INT64			n64Serial;
CMD_END

CMD_START(NS_ItemRemove)
//	DWORD			dwErrorCode;
	EItemConType	eConType;
	INT64			n64Serial;
	INT16			n16Index;
	INT16			n16Num;			// 如果是可堆叠物品,则为剩余个数,为0表示全部删除
CMD_END

CMD_START(NS_ItemCDUpdate)
	DWORD			dwTypeID;
	DWORD			dwCDTime;
CMD_END;


//----------------------------------------------------------------------------
// 行囊加密相关
//----------------------------------------------------------------------------
CMD_START(NC_SetBagPsd)		// 设置密码
	DWORD	dwBagPsdCrc;	// 欲设置的行囊密码crc值
CMD_END;

//CMD_START(NS_SetBagPsd)
//	DWORD	dwErrorCode;
//CMD_END;

CMD_START(NC_UnsetBagPsd)	// 取消密码
	DWORD	dwSafeCodeCrc;	// 安全码的crc值
CMD_END;

//CMD_START(NS_UnsetBagPsd)
//	DWORD	dwErrorCode;
//CMD_END;

CMD_START(NC_OldBagPsd)		// 旧密码
	DWORD	dwOldBagPsdCrc;
CMD_END;

//CMD_START(NS_OldBagPsd)
//	DWORD	dwErrorCode;
//CMD_END;

CMD_START(NC_ResetBagPsd)	// 修改密码
	DWORD	dwOldBagPsdCrc;
	DWORD	dwNewBagPsdCrc;
CMD_END;

//CMD_START(NS_ResetBagPsd)
//	DWORD	dwErrorCode;
//CMD_END;

CMD_START(NC_OpenBagPsd)	// 若加密，打开背包时需先发送该消息
	DWORD	dwBagPsdCrc;
CMD_END;

//CMD_START(NS_OpenBagPsd)
//	DWORD	dwErrorCode;
//CMD_END;

CMD_START(NS_BagPsd)		// 行囊密码相关消息反馈
	DWORD	dwErrorCode;
	DWORD	dwRoleStateEx;	// 只需玩家自己知道的状态
CMD_END;


//----------------------------------------------------------------------------
// 主手武器崭新度更新
//----------------------------------------------------------------------------
CMD_START(NS_RWNewessChange)
	INT32	nAttackTimes;		// 主手武器当前使用次数
CMD_END

//----------------------------------------------------------------------------
// 龙魂能力
//----------------------------------------------------------------------------
CMD_START(NS_LongHunOn)		// 指定部位装备的龙魂能力已激活
	INT16	n16EquipPos;
CMD_END

CMD_START(NS_LongHunOff)	// 指定部位装备的龙魂能力未激活
	INT16	n16EquipPos;
CMD_END

//----------------------------------------------------------------------------
// 使用染料为时装上色相关
//----------------------------------------------------------------------------
CMD_START(NC_DyeFashion)
    INT64   n64DyeSN;       // 染料64位id
    INT64   n64EquipSerial; // 时装装备64位id
CMD_END

CMD_START(NS_DyeFashion)
    DWORD   dwErrCode;      // 错误码
CMD_END

//----------------------------------------------------------------------------
// 百宝袋记录相关
//----------------------------------------------------------------------------
CMD_START(NC_InitBaiBaoRecord)	// 向服务器发送初始化百宝袋记录请求
CMD_END

CMD_START(NS_InitBaiBaoRecord)	// 服务器返回所有的消息
	INT16	n16Num;				// 记录数量
	BYTE	byData[1];			// tagBaiBaoRecord，长度计算取n16Size，不要用sizeof
CMD_END

CMD_START(NS_SingleBaiBaoRecord)// 玩家在线时，服务器发送单条百宝袋记录
	tagBaiBaoRecord	sRecord;	// 单条记录
CMD_END

//----------------------------------------------------------------------------
// 打开随身仓库
//----------------------------------------------------------------------------
CMD_START(NC_WareOpen)
	INT64	n64ItemID;
CMD_END

CMD_START(NS_WareOpen)
	DWORD	dwErrorCode;
CMD_END

//-----------------------------------------------------------------------------
//	点金石
//-----------------------------------------------------------------------------
CMD_START(NC_BeGoldStone)
	INT64		n64SrcItemID;	// 点金石
	INT64		n64DstItemID;	// 点金石要操作的物品
CMD_END
CMD_START(NS_BeGoldStone)
	DWORD		dwErrCode;		// 点金石操作结果
CMD_END

//-----------------------------------------------------------------------------
//	物品绑定
//-----------------------------------------------------------------------------
CMD_START(NS_ItemBind)
	EItemConType	eConType;
	INT64			n64Serial;
CMD_END

//-----------------------------------------------------------------------------
//	设置物品绑定状态
//-----------------------------------------------------------------------------
CMD_START(NS_ItemBindStatus)
	EItemConType	eConType;
	INT64			n64Serial;
	BYTE			byStatus;
CMD_END

// Jason 2010-4-15 v2.0.0
// 法宝其他相关操作，还走道具和装备那些流程，因此协议部分，没有单独体现，视情况扩展。
CMD_START(NS_NewFabaoAdd)
	tagFabao		fabao;
CMD_END
CMD_START(NS_FabaoChange)
	INT64			n64Serial;
	tagFabaoSpec	fabaoSpec;
CMD_END
// 妖精心情变化通知消息
CMD_START(NS_FabaoMoodChanged)
	INT64			n64Serial;		// 序号，妖精，在装备栏上的
	INT				nOldMood;
	INT				nNewMood;
CMD_END
CMD_START(NC_FabaoFeeding)
	DWORD			dwFoodTypeID;	// 妖精食物的typeid，该物品要在玩家背包内
CMD_END
CMD_START(NS_FabaoFeeding)
	DWORD			dwErrorCode;	
	DWORD			dwBuffID;		// 成功喂食后，buffid，无效时为GT_INVALID
CMD_END

// wcy 2012-04-01
CMD_START(NS_NewHolyAdd)
tagHolyMan		holy;
CMD_END

// wcy 2012-04-18
CMD_START(NS_NewHolyEquipAdd)
tagHolyEquip		holyEquip;
CMD_END

// 物品动态属性值
CMD_START(NS_ItemSpecValChanged)
	INT64	n64Serial;	// 物品序号
	DWORD	dwSpecVal1;// 物品动态属性值1
	DWORD	dwSpecVal2;// 物品动态属性值2
CMD_END

// 同步妖精经验封印信息
CMD_START(NC_SyncFaBaoStoreExpInfo)
	BOOL bStoreExpOpen;			// 妖精经验封印是否激活
CMD_END

CMD_START(NS_SyncFaBaoStoreExpInfo)
	BOOL bStoreExpOpen;			// 妖精经验封印是否激活
	INT nCurStoreExp;					// 当前封印的经验
CMD_END

// 经验球转换为经验丹
CMD_START(NC_ExpBall2ExpPilular)
	INT64 n64ExpBallSerialID;				// 经验球道具ID
	DWORD dwExpPilularID;			// 经验丹道具ID
CMD_END

CMD_START(NS_ExpBall2ExpPilular)
	DWORD dwErrorCode;
CMD_END

// 经验球约定
CMD_START(NC_ExpBallBind2Role)
	INT64 n64ExpBallSerialID;				// 经验球道具ID
CMD_END

CMD_START(NS_ExpBallBind2Role)
	DWORD dwErrorCode;
CMD_END

//////////////////////////////////////////////////////////////////////////
//	妖精繁殖
//////////////////////////////////////////////////////////////////////////

// 查看妖精生育状态
CMD_START(NC_InquireSpirteBornState)
	INT64 n64ExpBallSerialID;				// 妖精64ID
CMD_END

CMD_START(NS_InquireSpirteBornState)
	EFabaoStatus	eFabaoStatus;					// 妖精状态
	DWORD			dwtagDwordTime;			// 状态转换剩余时间（如没有传0）
CMD_END

// 申请妖精配对
CMD_START(NC_ApplyFairyBirth)
	DWORD	dwRoleID;				// 向某人申请妖精配对
CMD_END
// 服务器转送给对方
CMD_START(NS_TransmitApplyFairyBirth)
	DWORD	dwApplicantID;			// 申请人id
CMD_END
// 对方的应答
CMD_START(NC_ReplyFairyBirth)
	DWORD	dwApplicantID;			// 申请人
	BOOL	bAgreeOrNot;			// 是否同意
CMD_END
// 服务器转送给申请人
CMD_START(NS_TransmitReplyFairyBirth)
	DWORD	dwInvitee;				// 被邀请人
	DWORD	dwErrorCode;			// 是否同意
CMD_END


// 放妖精
CMD_START(NC_PutFairyInto)
	INT64		n64FairyID;			// 64位id
CMD_END
// 服务器应答
CMD_START(NS_PutFairyInto)
	DWORD dwErrorCode;
CMD_END
// 转递对方，妖精重要属性
CMD_START(NS_TransmitPutFairyInto)
	BYTE		byQlty;					// 品质
	INT			nBirthTimes;			// 配对次数，生育次数
	INT			nQualification;		// 资质
	DWORD		dwFairyTypeID;			// 妖精的typeid
CMD_END


// 确认配对
CMD_START(NC_FairyMating)
	BOOL		bAgreement;			// 是否
CMD_END
CMD_START(NS_TransmitFairyMating)
	DWORD		dwRoleID;				// 对方id
	BOOL		bAgreement;			// 是否
CMD_END
CMD_START(NS_FairyMating)				// 通知双方开始走条
CMD_END


// 取消妖精配对的所有操作
CMD_START(NC_FairyMatingCancelAll)
CMD_END

CMD_START(NS_FairyMatingCancelAll)
CMD_END

// 妖精生育
CMD_START(NC_FairyBorn)
	DWORD		dwNPCID;
	INT64			n64FairyID;			// 64位id
CMD_END
CMD_START(NS_FairyBorn)
	DWORD		dwErrCode;
CMD_END

// 账号回购
CMD_START(NS_LiLianChange)
	DWORD dwExp;	//历练改变量
CMD_END

CMD_START(NC_GetLiLianExp)
CMD_END

CMD_START(NS_GetLiLianExp)
	DWORD dwExp;		//总的历练值
	DWORD dwReceiveNum;	//领取礼包次数
CMD_END

CMD_START(NC_ReceiveGift)
CMD_END

CMD_START(NS_ReceiveGift)
	DWORD dwErrcode;
CMD_END

// 魂晶
CMD_START(NS_NewSoulCrystalAdd)
	tagSoulCrystal		hunjing;
CMD_END

CMD_START(NS_SoulCrystalChg)
	INT64 n64Serial;
	tagSoulCrystalSpec info;
CMD_END

// 圣灵
CMD_START(NS_ShengLingChg)
	INT64 n64Serial;
	tagHolySpec info;
CMD_END

// 圣灵默契值更新
CMD_START(NS_ShengLingCoValueChg)
INT	nCoValue;
CMD_END

//新新Key码
CMD_START(NC_GetKeyCodeGift)
	DWORD dwKeyCodeCrc;
CMD_END

CMD_START(NS_GetKeyCodeGift)
	DWORD dwErrorCode;
CMD_END

//妖精融合
CMD_START(NC_FairyFusion)
	INT64 n64FirstFairy;
	INT64 n64SecondFairy;
	INT64 n64IMID;
	BYTE byItemNum;
CMD_END

CMD_START(NS_FairyFusion)
	DWORD dwErrorCode;
CMD_END

CMD_START(NS_FairyFusionResult)
	tagFabao FirstFairy;	//生成的妖精
CMD_END

CMD_START(NC_GetFusionFairy)
	bool bWhichOne;		//true表示选择第一只，false表示选择第二只
CMD_END

CMD_START(NS_GetFusionFairy)
	DWORD dwErrorCode;
CMD_END

// 圣灵吸收妖精
CMD_START(NC_SLEatFairy)
	INT64 n64Fairy;	//妖精64位id或代妖精道具的64位Id
CMD_END

CMD_START(NS_SLEatFairy)
	DWORD dwErrorCode;	//错误码
CMD_END

//圣灵召唤消息
CMD_START(NC_CallShengLing)
CMD_END

//添加一条取消召唤圣灵消息
CMD_START(NC_CancelShengLing)
CMD_END

CMD_START(NS_CallShengLing)
	DWORD dwPlayID;
	DWORD dwShengLingTypeID;
	DWORD dwEatFairyNum;
	DWORD dwErrorCode;
CMD_END

CMD_START(NS_CallShengLingDisappear)
	DWORD dwPlayerID;
CMD_END

// 给圣灵穿装备
CMD_START(NC_EquipHoly)
INT64 n64Equip;	//圣纹64位id
CMD_END

CMD_START(NS_EquipHoly)
DWORD dwErrorCode;	//错误码
CMD_END

// 给圣灵卸装备
CMD_START(NC_UnEquipHoly)
	BYTE byIndex;
	DWORD dwTypeID;
CMD_END

CMD_START(NS_UnEquipHoly)
DWORD dwErrorCode;	//错误码
CMD_END

CMD_START(NC_ChongNeng)
	BYTE byIndex;			//装备索引
	INT64 n64ChongNeng;		//充能道具
	INT64 n64PianXiang;		//偏向道具
	BYTE byPianXiangIndex;	//偏向属性索引值
CMD_END

CMD_START(NS_ChongNeng)
	DWORD dwErrorCode;
	BYTE byAtt;		//属性类型
	DWORD dwAttValue;	//属性值
CMD_END


CMD_START(NC_LingNeng)
	BYTE byIndex;		//装备索引
	INT64 n64ItemId;	//灵能强化道具
CMD_END

CMD_START(NS_LingNeng)
	DWORD dwErrorCode;
	DWORD dwValue;		//灵能减少值
CMD_END

CMD_START(NC_ChongNengResult)
	bool isConfirm;	//是否确认
	bool isLingNeng;	//是否是灵能充能
CMD_END
// 圣灵
CMD_START(NS_HolyEquipChg)
INT64 n64Serial;
tagHolyEquipSpec info;
CMD_END

// 存储玩家手机号
CMD_START(NC_SaveTelNum)
INT64 n64TelNum;	//玩家手机号
CMD_END


// 玩家不存储手机号
CMD_START(NC_NotSaveTelNum)
CMD_END

// 领取圣币卷
CMD_START(NC_ReceiveYuanBao)
CMD_END

CMD_START(NS_ReceiveYuanBao)
	DWORD dwErrorCode;
CMD_END

#pragma pack(pop)
