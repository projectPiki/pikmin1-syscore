#ifndef _STREAM_H
#define _STREAM_H

#include <types.hpp>

struct String;

struct Stream {
    // _00 VTBL
    s8* m_source; // _04 file path

    Stream();

    virtual int readInt();                      // _00
    virtual u8 readByte();                      // _04
    virtual s16 readShort();                    // _08
    virtual f32 readFloat();                    // _0C
    virtual void readString(char*, int);        // _10
    virtual void readString(String&);           // _14
    virtual char* readString();                   // _18
    virtual void writeInt(int);                 // _1C
    virtual void writeByte(u8);                 // _20
    virtual void writeShort(s16);               // _24
    virtual void writeFloat(f32);               // _28
    virtual void writeString(char*);              // _2C
    virtual void writeString(String&);          // _30
    virtual void read(void*, int) { }           // _34
    virtual void write(void*, int) { }          // _38
    virtual int getPending() { return 0; }      // _3C
    virtual int getAvailable() { return 0; }    // _40
    virtual void close() { }                    // _44
    virtual bool getClosing() { return false; } // _48
    virtual void flush() { }                    // _4C

    void print(char* print, ...);
    void vPrintf(char* print, char* args);
};

extern Stream* sysCon;

#endif