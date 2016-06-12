/*****************************file head************************************
project name : wuya for tq2440
file name : main.c
file auther : wuya
creat time : 2016/7/26
histroy:
*************************************************************************/
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUnit.h>
#include <CUnit/TestDB.h>

#include <assert.h>

#include "hi_type.h"


HI_VOID ST_wuya_test3(HI_VOID)
{
	printf("hello runafterhit test3!\n");
}
HI_VOID ST_wuya_test2(HI_VOID)
{
	printf("hello runafterhit  test2!\n");
}

HI_VOID ST_wuya_test1(HI_VOID)
{
	printf("hello runafterhit  test1!\n");
}

CU_TestInfo g_testcase1[] = {
    {"wuya test 3:",ST_wuya_test3},
    {"wuya test 2:", ST_wuya_test2 },
    CU_TEST_INFO_NULL
};

CU_TestInfo g_testcase2[] = {
    {"wuya test 1:",ST_wuya_test1},
    CU_TEST_INFO_NULL
};

CU_SuiteInfo g_suites[] = {
    {"testSuite1",NULL,NULL,NULL , NULL,g_testcase1},
    {"testsuite2",NULL,NULL, NULL, NULL,g_testcase2},
    CU_SUITE_INFO_NULL
};

HI_VOID AddTests(HI_VOID)
{
    	assert(NULL != CU_get_registry());
   	assert(!CU_is_test_running());
    	if(CUE_SUCCESS != CU_register_suites(g_suites))
	{
		printf("AddTests  error!\n");
        	return;
    	}
}

HI_S32 main(HI_S32 argc, HI_S8 * argv[])
{
	printf("hello runafterhit !\n");
        if(CU_initialize_registry())
	{
                fprintf(stderr, " Initialization of Test Registry failed. ");
                return HI_FAUTRUE; 
        }
	else
	{
                AddTests();
                /**** Automated Mode *****************
                CU_set_output_filename("TestMax");
                CU_list_tests_to_file();
                CU_automated_run_tests();
                //************************************/
                
                /***** Basice Mode *******************
                CU_basic_set_mode(CU_BRM_VERBOSE);
                CU_basic_run_tests();
                //************************************/

                /*****Console Mode ********************/
                CU_console_run_tests();
                //************************************/

                CU_cleanup_registry();   
                return HI_SUCCESS; 
        }
}
