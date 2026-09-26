#pragma once

namespace hh::fnd {
    namespace user {
        class UserInfoEventListener {
        public:
            virtual ~UserInfoEventListener();
            virtual void UIEL_UnkFunc1(int eventId) = 0;
        };
    }

    class UserService : public ReferencedObject, public csl::fnd::Singleton<UserService> {
    public:
        unsigned int userId;
        int64_t qword20;
        int64_t qword28;
        int64_t qword30;
        int64_t qword38;
        char gap40[896];
        int dword3C0;
        char gap3C4[380];
        int64_t qword540;
        char gap548[240];
        int64_t qword638;
        int64_t qword640;
        int64_t qword648;
        int64_t qword650;
        int dword658;

        UserService();

        virtual void Setup() = 0;
        virtual void Cleanup() = 0;
        virtual void UpdateEvent(float deltaTime) = 0;
        virtual int GetActiveUser() const = 0;
        virtual csl::ut::String GetUserName(const unsigned int& id) const = 0;
        virtual unsigned int UnkFunc0(unsigned int& id);
        virtual bool UnkFunc1() { return true; }
        virtual bool UnkFunc2() { return false; }
        virtual int64_t UnkFunc3(unsigned int& id, char a3);

        unsigned int GetUserId() const;
    };

    class UserServiceWin32 : public UserService {
    public:
        // TODO

        UserServiceWin32();

        virtual void Setup() override;
        virtual void Cleanup() override {}
        virtual void UpdateEvent(float deltaTime) override;
        virtual int GetActiveUser() const override;
        virtual csl::ut::String GetUserName(const unsigned int& id) const override;
    };
}
