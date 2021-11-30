#ifndef _NODE_CORENODE_H
#define _NODE_CORENODE_H

#include <Node/ANode.h>

struct RandomAccessStream;

class CoreNode : public ANode {
public:
    CoreNode();
    CoreNode(char* name);

    char* Name();
    CoreNode* Parent();
    CoreNode* Child();
    void Child(CoreNode* newChild);
    CoreNode* Next();
    void Next(CoreNode* newNext);

    void initCore(char* name);
    void setName(char* name);

    void add(CoreNode* next);
    void del();
    void load(char* directory, char* filename,
              u32 type); // Arguments are guessed

    u32 getChildCount();
    char* getName();

    void genAge(AgeServer& editorServer) override;
    void genAgeNode(AgeServer& editorServer) override;
    void genRead(AgeServer&);
    void genWrite(AgeServer&);
    u32 getAgeNodeType() override;

    virtual void read(RandomAccessStream& stream);
    virtual void write(RandomAccessStream& stream);

private:
    // _00 VTBL
    char* m_name;       // _04
    CoreNode* m_parent; // _08
    CoreNode* m_next;   // _0C
    CoreNode* m_child;  // _10
};

#endif