/* #include <gtest/gtest.h>
#include "../src/entity.h"
#include "../src/list.h"

TEST(PhoneTest, ConstructorsAndSetters) {
    Phone p1;
    EXPECT_EQ(p1.getModel(), "");
    EXPECT_FLOAT_EQ(p1.getDiagonal(), 0.0f);
    EXPECT_EQ(p1.getPrice(), 0u);

    Phone p2("iPhone", 5.5f, 700);
    EXPECT_EQ(p2.getModel(), "iPhone");
    EXPECT_FLOAT_EQ(p2.getDiagonal(), 5.5f);
    EXPECT_EQ(p2.getPrice(), 700u);

    Phone p3 = p2;
    EXPECT_EQ(p3.getModel(), "iPhone");
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
 в мене проблема з компліцяєю тестів, так як є помилка визову двух функцій мейн
*/

