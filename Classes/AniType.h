#ifndef __ANITYPE_H__
#define __ANITYPE_H__

class AniType {
    public:
        enum Type
        {
            NONE,
            GEN,
            MOVE,
            BLOCKED,
            MERGED,     // remain part
            MERGING,    // disappear part
        };
};

#endif // __ANITYPE_H__
