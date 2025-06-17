/* #include <gtest/gtest.h>
#include "../src/entity.h"
#include "../src/list.h"
#include <fstream>

using std::string;

TEST(PhoneTest, ToStringFromString) {
    Phone p("iPhone", 5.5f, 700);
    string s = p.toString();
    Phone p2 = Phone::fromString(s);
    EXPECT_EQ(p.getModel(), p2.getModel());
    EXPECT_FLOAT_EQ(p.getDiagonal(), p2.getDiagonal());
    EXPECT_EQ(p.getPrice(), p2.getPrice());
}

TEST(ListTest, AddRemoveGet) {
    List l;
    Phone p1("A", 1, 10), p2("B", 2, 20);
    l.addPhone(p1);
    l.addPhone(p2);
    EXPECT_EQ(l.getSize(), 2u);
    EXPECT_EQ(l.getPhone(1).getModel(), "B");
    l.removePhone(0);
    EXPECT_EQ(l.getSize(), 1u);
    EXPECT_EQ(l.getPhone(0).getModel(), "B");
}

TEST(ListTest, FindCheapestPhone) {
    List l;
    l.addPhone(Phone("A", 5, 100));
    l.addPhone(Phone("B", 5, 80));
    l.addPhone(Phone("C", 6, 70));
    auto& p = l.findCheapestPhone(5);
    EXPECT_EQ(p.getModel(), "B");
    EXPECT_EQ(p.getPrice(), 80u);
}

TEST(ListTest, ReadWriteFile) {
    List l;
    Phone p1("A", 1, 10), p2("B", 2, 20);
    l.addPhone(p1);
    l.addPhone(p2);
    string fname = "testphones.txt";
    l.writeToFile(fname);
    List l2;
    l2.readFromFile(fname);
    EXPECT_EQ(l2.getSize(), 2u);
    EXPECT_EQ(l2.getPhone(1).getModel(), "B");
    std::remove(fname.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
