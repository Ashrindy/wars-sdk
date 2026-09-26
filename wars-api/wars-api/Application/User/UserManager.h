#pragma once

namespace app::user {
    class UserManager : public hh::fnd::ReferencedObject, public csl::fnd::Singleton<UserManager>, public hh::fnd::user::UserInfoEventListener {
    public:
        struct UnkStr {
            char byte0[120];
        };

        int64_t qword20;
        csl::ut::InplaceMoveArray<UnkStr, 4> qword28;
        int dword228;
        char byte22C;
        bool byte22D;
        unsigned int userId;

        UserManager();
        static UserManager* Create();

        virtual void UIEL_UnkFunc1(int eventId) override;
    };
}
