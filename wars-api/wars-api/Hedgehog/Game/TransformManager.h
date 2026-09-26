#pragma once

namespace hh::game {
    class TransformManager : public fnd::ReferencedObject, public csl::fnd::Singleton<TransformManager> {
    public:
        csl::ut::detail::LinkListImpl qword10[32];

        TransformManager();
    };
}
