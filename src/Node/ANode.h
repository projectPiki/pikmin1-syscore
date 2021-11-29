#ifndef _NODE_ANODE_H
#define _NODE_ANODE_H

#include <types.hpp>

enum class NodeType : u32 {
    ANode = 0,
};

struct AgeServer;

struct ANode {
    virtual void genAge(AgeServer&);
    virtual void genAgeNode(AgeServer&);
    virtual u32 getAgeNodeType();
};

#endif