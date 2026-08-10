#pragma once

namespace hh::scene {
    struct ControlNode {
        enum class ValueType : unsigned int {
            NONE,
            BOOLEAN,
            FLOAT,
            DOUBLE,
            INTEGER,
            STRING,
            VECTOR3,
            UNK
        };

        union Value {
            bool b;
            float f;
            double d;
            int i;
            const char* s;
            csl::math::Position v;
        };

        struct ValueSet {
            ValueType type;
            Value value;

            const char* GetValueAsString() const;
            float GetValueAsFloat() const;
        };

        const char* nodeName;
        const char* parameterName;
        ValueSet finalValue;
        ValueSet value;
        int unkType; // @ 0x14061E350, a2 - ControlNode
        bool isntActive;
    };
}
