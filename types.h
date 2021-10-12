#ifndef __TYPES_H__
#define __TYPES_H__
    #include <stdint.h>
    #include "go.h"
    #include "message.h"
    // User is a user on QQ.
    struct User {
        // Private sender
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/event/message.md#%E7%A7%81%E8%81%8A%E6%B6%88%E6%81%AF
        int64_t ID;
        string NickName;
        string Sex;
        int Age;
        string Area;
        // Group member
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/event/message.md#%E7%BE%A4%E6%B6%88%E6%81%AF
        string Card;
        string Title;
        string Level;
        string Role;
        // Group anonymous
        int64_t AnonymousID;
        string AnonymousName;
        string AnonymousFlag;
        // Name displays a simple text version of a user.
        string(*Name)();
        // String displays a simple text version of a user.
        // It is normally a user's card, but falls back to a nickname as available.
        string(*String)();
    };
    // File 文件
    struct File {
        string ID;
        string Name;
        int64_t Size;
        int64_t BusID;
    };
    // Event is the event emitted form cqhttp
    struct Event {
        int64_t Time;
        string PostType;
        string DetailType;
        string MessageType;
        string SubType;
        int64_t MessageID;
        int64_t GroupID;
        int64_t UserID;
        int64_t TargetID;
        int64_t SelfID;
        string RawMessage;
        //Anonymous     interface{}         `json:"anonymous"`
        string AnonymousFlag;
        string Event;
        string NoticeType;
        int64_t OperatorID;
        struct File* File;
        string RequestType;
        string Flag;
        string Comment;
        Message Message_;
        struct User* Sender;
        //NativeMessage jsoniter.RawMessage `json:"message"`
        int IsToMe;
        //RawEvent      gjson.Result        `json:"-"` // raw event
    };
    // Group 群
    struct Group {
        int64_t ID;
        string Name;
        int64_t MemberCount;
        int64_t MaxMemberCount;
    };
#endif