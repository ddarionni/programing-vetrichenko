/* #include <gtest/gtest.h>
#include "../src/entity.h"
#include "../src/list.h"
#include <fstream>

using std::string;

TEST(PhoneTest, AssignmentAndEquality) {
    Phone a("iPhone", 5.5f, 700);
    Phone b;
    b = a;
    EXPECT_TRUE(b == a);
    Phone c("Samsung", 6.1f, 900);
    EXPECT_TRUE(a != c);
}

TEST(PhoneTest, StreamOperators) {
    Phone p("Pixel", 6.0f, 650);
    std::stringstream ss;
    ss << p;
    Phone q;
    ss.seekg(0);
    ss >> q;
    EXPECT_TRUE(p == q);
}

TEST(ListTest, AddRemoveAndIndex) {
    List l;
    Phone p1("A", 1, 10), p2("B", 2, 20);
    l.addPhone(p1);
    l.addPhone(p2);
    EXPECT_EQ(l.getSize(), 2u);
    EXPECT_EQ(l[1].getModel(), "B");
    l.removePhone(0);
    EXPECT_EQ(l.getSize(), 1u);
    EXPECT_EQ(l[0].getModel(), "B");
}

TEST(ListTest, AssignmentAndFileIO) {
    List l;
    l.addPhone(Phone("A", 1, 10));
    l.addPhone(Phone("B", 2, 20));
    List l2;
    l2 = l;
    EXPECT_EQ(l2.getSize(), 2u);
    EXPECT_EQ(l2[1].getModel(), "B");

    string fname = "testphones.txt";
    {
        std::ofstream fout(fname);
        fout << l;
    }
    List l3;
    {
        std::ifstream fin(fname);
        fin >> l3;
    }
    EXPECT_EQ(l3.getSize(), 2u);
    EXPECT_EQ(l3[0].getModel(), "A");
    std::remove(fname.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
