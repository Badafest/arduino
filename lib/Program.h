#ifndef __PROGRAM_H__
#define __PROGRAM_H__

class Program
{
public:
    virtual void Setup() = 0;
    virtual void Loop() = 0;
};

#endif
