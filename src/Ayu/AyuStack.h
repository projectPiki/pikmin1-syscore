#ifndef _AYU_AYUSTACK_H
#define _AYU_AYUSTACK_H

#include <types.hpp>

class AyuStack {
public:
    AyuStack();

    s32 m_allocType;        // _00
    s32 m_size;             // _04
    s32 m_used;             // _08
    u32* m_top;             // _0C
    s32 m_topSize;          // _10
    u32* m_sp;              // _14
    s32 m_topFree;          // _18
    bool m_overflowProtect; // _1C
    bool m_active;          // _1D
    s8* m_name;             // _20
private:
};

#endif