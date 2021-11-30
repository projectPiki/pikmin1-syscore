#ifndef _STDSYSTEM_H
#define _STDSYSTEM_H

#include <Ayu/AyuHeap.h>
#include <Node/CoreNode.h>
#include <ObjInfo/GfxobjInfo.h>
#include <types.hpp>

struct BaseShape;
struct LightFlare;
struct Font;
struct Timers;
struct Matrix4f;

class StdSystem {
public:
    StdSystem();

    void Activate(bool);
    void Shutdown();

    void initSoftReset();
    void setDataRoot(char* dataRoot);

private:
    // _00 VTBL
    bool m_pending;    // _04
    f32 m_currentFade; // _08
    f32 m_fadeStart;   // _0C
    f32 m_fadeEnd;     // _10
    Font* m_consFont;  // _14
    s32 m_frameClamp;  // _18

    enum TimerState : u32 {
        TS_Off = 0,         // _00
        TS_On,              // _01
        TS_Full             // _02
    } m_timerState;         // _1C
    u32 m_togglePrint;      // _20
    u32 m_toggleDInfo;      // _24
    u32 m_toggleDExtra;     // _28
    u32 m_toggleBlur;       // _2C
    u32 m_toggleFileInfo;   // _30
    u32 m_toggleColls;      // _34
    Timers* m_timer;        // _38
    u32 m_dword3C;          // _3C
    u32 m_dword40;          // _40
    Matrix4f* m_matrix;     // _44
    char* m_bloDirectory;     // _48
    char* m_texDirectory;     // _4C
    char* m_currentDirectory; // _50
    char* m_dataRoot;         // _54
    AyuHeap m_heaps[8]; // _58 (sys, ovl, app, load, teki, movie, message, lang)
    s32 m_activeHeapNum; // _19C
    u32 _1A0;
    u8 _1A4[40];
    enum class SystemFlag : u32 {
        Shutdown = 0x80000000,
    } m_flags;                 // _1CC
    GfxobjInfo m_gfxObjects;   // _1D0
    bool m_hasGfxObjects;      // _1F0
    char* m_textureBase1;      // _1F4
    char* m_textureBase2;      // _1F8
    BaseShape* m_currentShape; // _1FC
    CoreNode m_coreNode200;    // _200
    CoreNode m_coreNode214;    // _214
    u32 m_dword228;            // _228
    u32 m_flareCount;          // _22C
    u32 m_dword230;            // _230
    u32 m_dword234;            // _234
    LightFlare* m_lightFlares; // _238
    u32 m_dword23C;            // _23C
    u32 m_dword240;            // _240
};

#endif