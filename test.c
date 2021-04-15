#include<stdio.h>
#include "contact.h"
#include "unity.h"

void setUp(){}

void tearDown(){}

void test_createcontact(void){
    TEST_ASSERT_EQUAL(1,create_contact("Navaneeth","Bangarpet",7619259792,"navneeth023@gmail.com"));
}

void test_searchcontact(){
    TEST_ASSERT_EQUAL(1,search_result("Navaneeth"));
    TEST_ASSERT_EQUAL(0,search_result("Vishwas"));
}

/*void test_compare_name(void){
    TEST_ASSERT_EQUAL(1,compare_name("sobin","Sobin"));
    TEST_ASSERT_EQUAL(0,compare_name("sobin","rajan"));
}*/

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_createcontact);
    //RUN_TEST(test_searchcontact);
    //RUN_TEST(test_compare_name);

    return UNITY_END();
}
