#include "factory.h"

#define REGISTER_TYPE(klass) \
    class klass##Factory : public Factory { \
    public: \
        klass##Factory() \
        { \
            Object::registerType(#klass, this); \
        } \
        virtual Object *create() { \
            return new klass(); \
        } \
    }; \
    static klass##Factory global_##klass##Factory;
