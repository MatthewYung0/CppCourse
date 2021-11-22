#include <gtest/gtest.h>
//#include <
typedef struct _t {
    enum class TYPES {
        CHAR, INT, VOID
    };
    std::size_t _s = 0;
    TYPES _t;

}TypeInfo_t;
using Element_t = std::pair<TypeInfo_t,void*>;


class RingBuffer {
    RingBuffer() = delete;
    std::size_t _r = 0;
    std::size_t _w = 0;
    std::size_t _size;
    Element_t *_buffer = nullptr;
public:
    RingBuffer(const std::size_t &s):_size(s),_buffer(new Element_t[s]){}
    ~RingBuffer();
    inline std::size_t size(){return this->_size;}
    Element_t read();
    void      write(const Element_t &_e);
    void      clean();
};

RingBuffer::~RingBuffer() {
    if (this->_buffer != nullptr) {
        (this->size() > 1) ? delete [] this->_buffer: delete this->_buffer;
    }
}

Element_t RingBuffer::read() {
    Element_t ret = this->_buffer[_r];
    if ((++_r) == _size ) _r = 0;
    return ret;
}

void RingBuffer::write(const Element_t &_e) {
    auto i = this->_buffer[_w];
    (i.first._s > 1) ? delete [] i.second : delete i.second;
    _buffer[_w] = _e;
    if ((++_w) == _size) _w = 0;
}

void RingBuffer::clean() {
    for (std::size_t var = 0; var < this->_size; ++var) {
        auto i = this->_buffer[var];
        (i.first._s > 1) ? delete [] i.second : delete i.second;
    }
}

class RingBufferTestFixtures : public ::testing::Test {
    void addInt() {
//        this->B->write();
    }
    void addChar() {

    }
protected:
//    RingBufferTestFixtures() {
//        std::cout << "I aM NewEd" << std::endl;
//    }
    void SetUp () override {
        B = new RingBuffer(100);
        std::cout << "I aM SetEd" << std::endl;

        tinfo_int._s = 40;
        tinfo_int._t = TypeInfo_t::TYPES::INT;

        tinfo_chr._s = 20;
        tinfo_chr._t = TypeInfo_t::TYPES::CHAR;
    }

    void TearDown() override {
        B->clean();
        delete B;
    }
    RingBuffer *B;
    TypeInfo_t tinfo_int, tinfo_chr;
};


TEST_F(RingBufferTestFixtures, SizeIsSet) {
    EXPECT_EQ(B->size(),100);
}

TEST_F(RingBufferTestFixtures, TestWrite) {
    Element_t e(tinfo_chr,new char[tinfo_chr._s]);
    B->write(e);
    auto ie = B->read();
    EXPECT_EQ(ie.first._s,tinfo_chr._s);
    EXPECT_EQ(ie.first._s,tinfo_chr._s);
}

TEST(RingBufferTest, TestWrite) {
    //SETUP
    RingBuffer b(2);
    TypeInfo_t tinfo;
    tinfo._s = 40;
    tinfo._t = TypeInfo_t::TYPES::INT;
    Element_t e(tinfo,new int[40]);
    //ACTION
    b.write(e);
    //VERIFICATION
    auto ie = b.read();
    EXPECT_EQ(ie.first._s,40);
    //CLEANUP
    b.clean();
}

int main (int _, char**__) {
    ::testing::InitGoogleTest(&_,__);
    return RUN_ALL_TESTS();
}
