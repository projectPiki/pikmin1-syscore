#include <Stream/Stream.h>
#include <String_.h>
#include <cstdarg>
#include <stdio.h>
#include <string.h>

Stream* sysCon;

Stream::Stream() { }

int Stream::readInt()
{
    int c;
    read(&c, sizeof(int));
    return (c << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8)
        | ((c & 0xFF000000) >> 24);
}

u8 Stream::readByte()
{
    u8 c;
    read(&c, sizeof(u8));
    return c;
}

s16 Stream::readShort()
{
    s16 c;
    read(&c, sizeof(s16));
    return (c << 8) | ((c & 0xFF00) >> 8);
}

f32 Stream::readFloat()
{
    int c;
    read(&c, sizeof(f32));
    c = (c << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8)
        | ((c & 0xFF000000) >> 24);
    return *reinterpret_cast<f32*>(&c);
}

void Stream::readString(char* str, int len)
{
    String temp(str, len);
    readString(temp);
}

void Stream::readString(String& str)
{
    const u32 length = readInt();

    // Correct size of string if incorrect
    if (str.m_length < length) {
        str.init(length);
    }

    read(str.m_string, length);
    str.m_string[length] = '\0';
}

char* Stream::readString()
{
    const u32 stringLength = readInt();
    char* str              = new char[stringLength + 1];
    read(str, stringLength);
    str[stringLength] = '\0';

    return str;
}

void Stream::writeInt(int c)
{
    s32 cw = ((u8)c << 24) | ((c & 0xFF00) << 8) | ((c & 0xFF0000) >> 8)
        | ((c & 0xFF000000) >> 24);
    write(&cw, sizeof(int));
}

void Stream::writeByte(u8 c) { write(&c, sizeof(u8)); }

void Stream::writeShort(s16 c)
{
    s16 cw = (c << 8) | ((c & 0xFF00) >> 8);
    write(&cw, sizeof(s16));
}

void Stream::writeFloat(f32 c)
{
    s32 cw = *reinterpret_cast<int*>(&c);
    cw     = ((u8)cw << 24) | ((cw & 0xFF00) << 8) | ((cw & 0xFF0000) >> 8)
        | ((cw & 0xFF000000) >> 24);
    write(&cw, sizeof(f32));
}

void Stream::writeString(char* str)
{
    String writer(str, 0);
    writeString(writer);
}

void Stream::writeString(String& str)
{
    // Align the length of the string to the nearest 4 byte upwards
    const u32 strLen   = str.getLength();
    const u32 alignLen = (strLen + 3) & ~3;
    writeInt(alignLen);
    write(str.m_string, strLen);

    for (u32 i = 0; i < alignLen - strLen; i++) {
        writeByte('\0');
    }
}

void Stream::print(char* format, ...)
{
    va_list va;
    va_start(va, format);

    char out[256];
    vsprintf(out, (const char*)format, va);

    const size_t outLen = strlen(out);
    if (outLen) {
        write(out, outLen);
    }
}

void Stream::vPrintf(char* format, char* args)
{
    char out[1024];
    vsprintf(out, (const char*)format, (char*)args);

    const size_t outLen = strlen(out);
    if (outLen) {
        write(out, outLen);
    }
}
