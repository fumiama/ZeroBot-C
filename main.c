#include "zero.h"

zero z;
zero* GetZPtr() {
    return &z;
}

const Rule handlers[1] = {handle_test};

int handle_test(struct Ctx * c) {
    c->Send("返回");
}

int Init() {
    Engine* en = z.Register("template", "this is help of template.", ENABLE_ON_DEFAULT);
    z.OnKeyword(en, "测试", handlers, 1);
}
