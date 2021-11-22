#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "e.h"


class testy {
    virtual void tt() = 0;
public:
    virtual void rr() {
        tt();
    }
};

class mockTesty : public testy {
public:
    MOCK_METHOD(void,tt,(),(override));
//    MOCK_METHOD(void,rr,(),());
};



TEST(tt,te) {
    //SETUP
    ::testing::NiceMock<mockTesty> m;
    m.tt();
    EXPECT_CALL(m,tt()).Times(1);
    //ACTION
    m.tt();
}
TEST(tt,re) {
    mockTesty m;
    EXPECT_CALL(m,tt()).Times(2);
    m.rr();
    m.tt();
}


class mockEmulator: public carEmulator {
public:
    MOCK_METHOD(int,calculateGear,(int gear),(override));
    MOCK_METHOD(int,calculateRPM,(int acc),(override));
};

TEST(Em,ee) {
    /*::testing::StrictMock<*/mockEmulator/*>*/ me;
    int rpm = 1400, gear = 1, acc = 3;
    userInput fakeInput(acc,gear,true);
    EXPECT_CALL(me,calculateGear(fakeInput.gear)).Times(1).WillOnce(::testing::Return(gear));
    EXPECT_CALL(me,calculateRPM(fakeInput.acc)).Times(2).WillOnce(::testing::Return(rpm));
//    EXPECT_CALL(me,calculateRPM(fakeInput.acc));
    me.run(fakeInput);
    EXPECT_EQ(me.calculateSpeed(), rpm * gear);
}



int main (int _, char**__) {
    ::testing::InitGoogleMock(&_,__);
    return RUN_ALL_TESTS();
}








