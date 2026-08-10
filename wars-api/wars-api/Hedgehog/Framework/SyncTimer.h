#pragma once

namespace hh {
    class SyncTimer : public hh::fnd::ReferencedObject, public csl::fnd::Singleton<SyncTimer> {
    public:
        float maxFps;
        csl::fnd::Tick tick;
        float threadSleepSeconds; //deltaTime
        float afterSleepDeltaTime;
        float beforeSleepDeltaTime;
        float maxDeltaTime;
        int dword38;
        csl::fnd::Tick ticks[32];
        csl::fnd::Tick deltaTick;
        int tickCount;
        float fps;
        char byte150;

        SyncTimer();
        void Sync(bool threadSleep);
        void SetFPS(float fps);
    };
}
