#ifndef _OBJINFO_GFXOBJINFO_H
#define _OBJINFO_GFXOBJINFO_H

#include <ID32.h>
#include <types.hpp>

struct GfxobjInfo {
    virtual void attach() { }
    virtual void detach() { }

    // _00 VTBL
    GfxobjInfo* m_previous; // _04
    GfxobjInfo* m_next;     // _08
    char* m_name;           // _0C
    ID32 m_id;              // _10
    s32 m_attached;         // _1C
};

#endif