#ifndef __MESSAGE_H__
#define __MESSAGE_H__
    #include <stdint.h>
    #include "go.h"

    typedef void* MessageSegment;

    typedef void* Message;

    struct message {
        // EscapeCQText escapes special characters in a non-media plain message.
        //
        // CQ码字符转换
        string(*EscapeCQText)(string);
        // UnescapeCQText unescapes special characters in a non-media plain message.
        //
        // CQ码反解析
        string(*UnescapeCQText)(string);
        // EscapeCQCodeText escapes special characters in a cqcode value.
        //
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/string.md#%E8%BD%AC%E4%B9%89
        //
        // cq码字符转换
        string(*EscapeCQCodeText)(string);
        // UnescapeCQCodeText unescapes special characters in a cqcode value.
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/string.md#%E8%BD%AC%E4%B9%89
        //
        // cq码反解析
        string(*UnescapeCQCodeText)(string);


        // Text 纯文本
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E7%BA%AF%E6%96%87%E6%9C%AC
        MessageSegment(*Text)(char**, void*);
        // Face QQ表情
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#qq-%E8%A1%A8%E6%83%85
        MessageSegment(*Face)(int);
        // Image 普通图片
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E5%9B%BE%E7%89%87
        MessageSegment(*Image)(string);
        // Record 语音
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E8%AF%AD%E9%9F%B3
        MessageSegment(*Record)(string);
        // At @某人
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E6%9F%90%E4%BA%BA
        MessageSegment(*At)(int64_t);
        // Music 音乐分享
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E9%9F%B3%E4%B9%90%E5%88%86%E4%BA%AB-
        MessageSegment(*Music)(string, int64_t);
        // CustomMusic 音乐自定义分享 url, audio, title 
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E9%9F%B3%E4%B9%90%E8%87%AA%E5%AE%9A%E4%B9%89%E5%88%86%E4%BA%AB-
        MessageSegment(*CustomMusic)(string, string, string);
        // Reply 回复
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E5%9B%9E%E5%A4%8D
        MessageSegment(*Reply)(int64_t);
        // Forward 合并转发
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E5%90%88%E5%B9%B6%E8%BD%AC%E5%8F%91-
        MessageSegment(*Forward)(string);
        // Node 合并转发节点
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E5%90%88%E5%B9%B6%E8%BD%AC%E5%8F%91%E8%8A%82%E7%82%B9-
        MessageSegment(*Node)(int64_t);
        // CustomNode 自定义合并转发节点
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#%E5%90%88%E5%B9%B6%E8%BD%AC%E5%8F%91%E8%87%AA%E5%AE%9A%E4%B9%89%E8%8A%82%E7%82%B9
        MessageSegment(*CustomNode)(string, int64_t, void*);
        // XML 消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#xml-%E6%B6%88%E6%81%AF
        MessageSegment(*XML)(string);
        // JSON 消息
        // https://github.com/howmanybots/onebot/blob/master/v11/specs/message/segment.md#xml-%E6%B6%88%E6%81%AF
        MessageSegment(*JSON)(string);

        // Expand CQCode

        // Gift 群礼物
        // https://github.com/Mrs4s/go-cqhttp/blob/master/docs/cqhttp.md#%E7%A4%BC%E7%89%A9
        //
        // Deprecated: 群礼物改版
        MessageSegment(*Gift)(string, string);
        // Poke 戳一戳
        // https://github.com/Mrs4s/go-cqhttp/blob/master/docs/cqhttp.md#%E6%88%B3%E4%B8%80%E6%88%B3
        MessageSegment(*Poke)(int64_t);
        // TTS 文本转语音
        // https://github.com/Mrs4s/go-cqhttp/blob/master/docs/cqhttp.md#%E6%96%87%E6%9C%AC%E8%BD%AC%E8%AF%AD%E9%9F%B3
        MessageSegment(*TTS)(string);
        // ReplyWithMessage returns a reply message
        //func ReplyWithMessage(messageID int64, m ...MessageSegment) Message


        // ParseMessageFromString parses msg as type string to a sort of MessageSegment.
        // msg is the value of key "message" of the data unmarshalled from the
        // API response JSON.
        //
        // CQ字符串转为消息
        Message(*ParseMessageFromString)(string);


        // Modified from https://github.com/catsworld/qq-bot-api

        // ParseMessage parses msg, which might have 2 types, string or array,
        // depending on the configuration of cqhttp, to a Message.
        // msg is the value of key "message" of the data unmarshalled from the
        // API response JSON.
        Message(*ParseMessage)(bytes);
        // ParseMessageFromArray parses msg as type array to a Message.
        // msg is the value of key "message" of the data unmarshalled from the
        // API response JSON.
        // ParseMessageFromArray cq字符串转化为json对象
        //func ParseMessageFromArray(msgs gjson.Result) Message
    };
    typedef struct message message;
#endif