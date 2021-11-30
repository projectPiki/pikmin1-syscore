#ifndef _STRING_H
#define _STRING_H

#include <types.hpp>

// TODO
struct String {
    u32 m_length;
    char* m_string;

    String();
    String(int len);
    String(char* str, int len);

    double toFloat() { return 0.0; }
    int toInt();

    void init(int len);
    void init(char* str, int len);
    void init(char* str);

    u32 calcHash();
    static u32 calcHash(char* str);

    u32 getLength();
    static u32 getLength(char* str);

    char* dup();
    static char* dup(char* str);

    bool isSame(char* str);
    bool isSame(String* str);
    bool contains(char* str);

    static void concat(char* a1, char* a2);
    static char* copy(char* a1, char* a2);
    static bool isSame(char* a1, char* a2);
    static bool isWhiteSpace(char letter);
    static bool copyUntil(char*, char*, char, char**);
    static bool equals(char*, char*);
    static bool contains(char*, char*);
    static bool contains(char*, char);
};

#endif