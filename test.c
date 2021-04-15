#include<stdio.h>
#include "contact.h"
#include "unity.h"

void setUp(){}

void tearDown(){}

void test_createcontact(void){
    TEST_ASSERT_EQUAL(1,create_contact("Navaneeth","Bangarpet",7619259792,"navneeth023@gmail.com"));
}





int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_createcontact);
    //RUN_TEST(test_searchcontact);
    //RUN_TEST(test_compare_name);

    return UNITY_END();
}
