#include <Node/CoreNode.h>

CoreNode::CoreNode()
    : CoreNode("CoreNode")
{
}

CoreNode::CoreNode(char* name)
    : ANode()
{
    initCore(name);
}

char* CoreNode::Name() { return m_name; }

CoreNode* CoreNode::Parent() { return m_parent; }

CoreNode* CoreNode::Child() { return m_child; }
void CoreNode::Child(CoreNode* newChild) { m_child = newChild; }

CoreNode* CoreNode::Next() { return m_next; }
void CoreNode::Next(CoreNode* newNext) { m_next = newNext; }

void CoreNode::initCore(char* name)
{
    m_child  = nullptr;
    m_next   = nullptr;
    m_parent = nullptr;
    setName(name);
}

void CoreNode::setName(char* name) { m_name = name; }

void CoreNode::add(CoreNode* next)
{
    // Set the parent to this object
    next->m_parent = this;

    // If we don't have a child, make the next node the child
    if (!m_child) {
        m_child = next;
        return;
    }

    // Iterate through our children's next nodes, assign to the end
    CoreNode* child = m_child;
    while (child->m_next) {
        child = child->m_next;
    }
    child->m_next = next;
}

void CoreNode::del()
{
    // Works only if we are a child
    if (!m_parent) {
        return;
    }

    // Honestly, not 100% sure what this means
    CoreNode* prevNode = nullptr;
    for (CoreNode* i = m_parent->m_child; i; i = i->m_next) {
        if (i == this) {
            if (prevNode) {
                prevNode->m_next = i->m_next;
            } else {
                m_parent->m_child = i->m_next;
            }

            m_next   = nullptr;
            m_parent = nullptr;
            return;
        }

        prevNode = i;
    }
}

// TODO
void CoreNode::load(char* directory, char* filename, u32 type) { }

u32 CoreNode::getChildCount()
{
    u32 count = 0;

    for (CoreNode* i = m_child; i; i = i->m_next) {
        count++;
    }

    return count;
}

char* CoreNode::getName() { return m_name; }

// TODO
void CoreNode::genAge(AgeServer& editorServer) { }

// TODO
void CoreNode::genAgeNode(AgeServer& editorServer) { }

// TODO
void CoreNode::genRead(AgeServer&) { }

// TODO
void CoreNode::genWrite(AgeServer&) { }

u32 CoreNode::getAgeNodeType() { return static_cast<u32>(NodeType::CoreNode); }

inline void CoreNode::read(RandomAccessStream& stream) { }

inline void CoreNode::write(RandomAccessStream& stream) { }
