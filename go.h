#ifndef __GO_H__
#define __GO_H__
    struct __string {
        char* data;
        void* len;
    };
    typedef struct __string _string;
    typedef _string* string;

    struct __bytes {
        char* data;
        void* len;
        void* cap;
    };
    typedef struct __bytes _bytes;
    typedef _bytes* bytes;

    // map[string]string
    struct __MapStrStr{
        void*(*New);
        void(*Add)(string, string);
        string(*Get)(string);
    };
    typedef struct __MapStrStr _MapStrStr;
    typedef _MapStrStr* MapStrStr;
#endif