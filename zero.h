#ifndef __ZERO_H__
#define __ZERO_H__
    #include <stdint.h>
    #include "go.h"
    #include "types.h"

    typedef void Engine;

    typedef void Matcher;

    // Ctx represents the Context which hold the event.
    // 代表上下文
    struct Ctx {
        struct Event* Event;
        MapStrStr State;

        // GetMatcher ...
        Matcher*(*GetMatcher)();
        // CheckSession 判断会话连续性
        Rule(*CheckSession)();
        // Send 快捷发送消息
        int64_t(*Send)(Message);
        // SendChain 快捷发送消息-消息链
        int64_t(*SendChain)(MessageSegment, int);
        // ExtractPlainText 提取消息中的纯文本
        string(*ExtractPlainText)();
        // Block 阻止后续触发
        void(*Block)();
        // MessageString 字符串消息便于Regex
        string(*MessageString)();

        // SendGroupMessage 发送群消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#send_group_msg-%E5%8F%91%E9%80%81%E7%BE%A4%E6%B6%88%E6%81%AF
        int64_t(*SendGroupMessage)(int64_t, Message);
        // SendPrivateMessage 发送私聊消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#send_private_msg-%E5%8F%91%E9%80%81%E7%A7%81%E8%81%8A%E6%B6%88%E6%81%AF
        int64_t(*SendPrivateMessage)(int64_t, Message);
        // DeleteMessage 撤回消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#delete_msg-%E6%92%A4%E5%9B%9E%E6%B6%88%E6%81%AF
        (*DeleteMessage)(int64_t);
        // GetMessage 获取消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#get_msg-%E8%8E%B7%E5%8F%96%E6%B6%88%E6%81%AF
        Message(*GetMessage)(int64_t);
        // SetGroupKick 群组踢人
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_kick-%E7%BE%A4%E7%BB%84%E8%B8%A2%E4%BA%BA
        (*SetGroupKick)(int64_t, int64_t, int);
        // SetGroupBan 群组单人禁言
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_ban-%E7%BE%A4%E7%BB%84%E5%8D%95%E4%BA%BA%E7%A6%81%E8%A8%80
        (*SetGroupBan)(int64_t, int64_t, int64_t);
        // SetGroupWholeBan 群组全员禁言
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_whole_ban-%E7%BE%A4%E7%BB%84%E5%85%A8%E5%91%98%E7%A6%81%E8%A8%80
        (*SetGroupWholeBan)(int64_t, int);
        // SetGroupAdmin 群组设置管理员
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_whole_ban-%E7%BE%A4%E7%BB%84%E5%85%A8%E5%91%98%E7%A6%81%E8%A8%80
        (*SetGroupAdmin)(int64_t, int64_t, int);
        // SetGroupAnonymous 群组匿名
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_anonymous-%E7%BE%A4%E7%BB%84%E5%8C%BF%E5%90%8D
        (*SetGroupAnonymous)(int64_t, int);
        // SetGroupCard 设置群名片（群备注）
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_card-%E8%AE%BE%E7%BD%AE%E7%BE%A4%E5%90%8D%E7%89%87%E7%BE%A4%E5%A4%87%E6%B3%A8
        (*SetGroupCard)(int64_t, int64_t, string);
        // SetGroupName 设置群名
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_name-%E8%AE%BE%E7%BD%AE%E7%BE%A4%E5%90%8D
        (*SetGroupName)(int64_t, string);
        // SetGroupLeave 退出群组
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_leave-%E9%80%80%E5%87%BA%E7%BE%A4%E7%BB%84
        (*SetGroupLeave)(int64_t, int);
        // SetGroupSpecialTitle 设置群组专属头衔
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_special_title-%E8%AE%BE%E7%BD%AE%E7%BE%A4%E7%BB%84%E4%B8%93%E5%B1%9E%E5%A4%B4%E8%A1%94
        (*SetGroupSpecialTitle)(int64_t, int64_t, string);
        // SetFriendAddRequest 处理加好友请求
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_friend_add_request-%E5%A4%84%E7%90%86%E5%8A%A0%E5%A5%BD%E5%8F%8B%E8%AF%B7%E6%B1%82
        (*SetFriendAddRequest)(string, int, string);
        // SetGroupAddRequest 处理加群请求／邀请
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#set_group_add_request-%E5%A4%84%E7%90%86%E5%8A%A0%E7%BE%A4%E8%AF%B7%E6%B1%82%E9%82%80%E8%AF%B7
        (*SetGroupAddRequest)(string, string, int, string);
        // GetGroupInfo 获取群信息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/api/public.md#get_group_info-%E8%8E%B7%E5%8F%96%E7%BE%A4%E4%BF%A1%E6%81%AF
        struct Group*(*GetGroupInfo)(int64_t, int);

        // Expand API

        // SetGroupPortrait 设置群头像
        // https://github.com/Mrs4s/go-cqhttp/blob/master/docs/cqhttp.md#%E8%AE%BE%E7%BD%AE%E7%BE%A4%E5%A4%B4%E5%83%8F
        (*SetGroupPortrait)(int64_t, string);
    };

    // Rule filter the event
	typedef int(*Rule)(struct Ctx*);
	// Handler 事件处理函数
	typedef void(*Handler)(struct Ctx*);

    #define DISABLE_ON_DEFAULT 1
    #define ENABLE_ON_DEFAULT 0
    struct zero {
        // Register 注册引擎 name, help, disableOnDefault
        Engine*(*Register)(string, string, int);
        void(*SetBlock)(Engine*, int);
        // On 添加新的指定消息类型的匹配器
        Matcher*(*On)(Engine*, string, Rule*, int);
        // OnPrefix 前缀触发器
        Matcher*(*OnPrefix)(Engine*, string, Rule*, int);
        // OnSuffix 后缀触发器
        Matcher*(*OnSuffix)(Engine*, string, Rule*, int);
        // OnCommand 命令触发器
        Matcher*(*OnCommand)(Engine*, string, Rule*, int);
        // OnRegex 正则触发器
        Matcher*(*OnRegex)(Engine*, string, Rule*, int);
        // OnKeyword 关键词触发器
        Matcher*(*OnKeyword)(Engine*, string, Rule*, int);
        // OnFullMatch 完全匹配触发器
        Matcher*(*OnFullMatch)(Engine*, string, Rule*, int);
        // OnFullMatchGroup 完全匹配触发器组
        Matcher*(*OnFullMatchGroup)(Engine*, string*, int, Rule*, int);
        // OnKeywordGroup 关键词触发器组
        Matcher*(*OnKeywordGroup)(Engine*, string*, int, Rule*, int);
        // OnCommandGroup 命令触发器组
        Matcher*(*OnCommandGroup)(Engine*, string*, int, Rule*, int);
        // OnPrefixGroup 前缀触发器组
        Matcher*(*OnPrefixGroup)(Engine*, string*, int, Rule*, int);
        // OnSuffixGroup 后缀触发器组
        Matcher*(*OnSuffixGroup)(Engine*, string*, int, Rule*, int);
    };
    typedef struct zero zero;

#endif