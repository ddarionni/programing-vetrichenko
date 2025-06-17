/* #include <gtest/gtest.h>
#include "../src/entity.h"
#include "../src/list.h"
#include <fstream>

TEST(PolymorphismTest, CloneAndInfo) {
    Phone p("iPhone", 6.1f, 999);
    Device* d = p.clone();
    EXPECT_EQ(d->getType(), "Phone");
    EXPECT_TRUE(d->info().find("iPhone") != std::string::npos);
    delete d;

    Tablet t("iPad", 12.9f, 1499, true);
    Device* d2 = t.clone();
    EXPECT_EQ(d2->getType(), "Tablet");
    EXPECT_TRUE(d2->info().find("iPad") != std::string::npos);
    delete d2;
}

TEST(ListTest, AddRemoveAndIO) {
    List l;
    l.add(new Phone("A", 1, 10));
    l.add(new Tablet("T", 7, 100, false));
    EXPECT_EQ(l.size(), 2u);
    EXPECT_EQ(l[0].getType(), "Phone");
    EXPECT_EQ(l[1].getType(), "Tablet");

    std::stringstream ss;
    ss << l;
    List l2;
    ss >> l2;
    EXPECT_EQ(l2.size(), 2u);

    l.remove(0);
    EXPECT_EQ(l.size(), 1u);
    l.clear();
    EXPECT_EQ(l.size(), 0u);
}

TEST(ListTest, FileIO) {
    List l;
    l.add(new Phone("A", 1, 10));
    l.add(new Tablet("T", 7, 100, true));
    std::string fname = "testdev.txt";
    {
        std::ofstream fout(fname);
        fout << l;
    }
    List l2;
    {
        std::ifstream fin(fname);
        fin >> l2;
    }
    EXPECT_EQ(l2.size(), 2u);
    EXPECT_EQ(l2[1].getType(), "Tablet");
    std::remove(fname.c_str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
