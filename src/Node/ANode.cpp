#include <Node/ANode.h>

void ANode::genAge(AgeServer&) { }

void ANode::genAgeNode(AgeServer&) { }

u32 ANode::getAgeNodeType() { return static_cast<u32>(NodeType::ANode); }
