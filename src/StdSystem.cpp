#include <StdSystem.h>

StdSystem::StdSystem()
{
    m_consFont = nullptr;

    m_currentFade = 0.0f;
    m_fadeStart   = 0.0f;
    m_fadeEnd     = 1.0f;

    m_toggleFileInfo = true;

    m_activeHeapNum = 0;

    m_gfxObjects.m_previous = &m_gfxObjects;
    m_gfxObjects.m_next     = m_gfxObjects.m_previous;
    m_hasGfxObjects         = true;

    m_lightFlares = nullptr;

    initSoftReset();
    setDataRoot("dataDir/");

    _1A0 = 0;
}

void StdSystem::Activate(bool) { }

void StdSystem::Shutdown() { m_flags = SystemFlag::Shutdown; }

// TODO
void StdSystem::initSoftReset()
{
    // CmdStream::statbuff = nullptr;
    m_currentShape = nullptr;
}

void StdSystem::setDataRoot(char* dataRoot) { m_dataRoot = dataRoot; }
