#pragma once
#include <ucsl/resources/scene/v106.h>

namespace hh::scene {
    class CurveEvaluatorBase {
    public:
        ucsl::resources::scene::v106::TrackNode::CurveData* curveData;
        ucsl::resources::scene::v106::TrackNode::CurveData::Keyframe* keyframes;
        int64_t qword18;
    };

    class ICurveEvaluator : public CurveEvaluatorBase {
    public:
        virtual bool SetParameters(ucsl::resources::scene::v106::TrackNode::CurveData* curveData) = 0;
        virtual float Calculate(float time) = 0;
    };

    class LinearCurveEvaluator : public ICurveEvaluator {
    public:
        float dword20;
        float dword24;

        virtual bool SetParameters(ucsl::resources::scene::v106::TrackNode::CurveData* curveData) override;
        virtual float Calculate(float time) override;

        LinearCurveEvaluator();
    };

    class HermiteCurveEvaluator : public ICurveEvaluator {
    public:
        float dword20;
        float dword24;
        float dword28;
        float dword2C;

        virtual bool SetParameters(ucsl::resources::scene::v106::TrackNode::CurveData* curveData) override;
        virtual float Calculate(float time) override;

        HermiteCurveEvaluator();
    };
}
