#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "leptjson.h"

using namespace lept;
static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define TEST_EQ_BASE(equality,expect,actual) \
	do { \
		test_count++;\
		if(equality) \
		    test_pass++;\
		else \
		{ \
			std::cerr << __FILE__ << ":" << __LINE__ << ":expect:" << expect << "actual:" << actual << std::endl; \
		main_ret = 1; \
		}\
	   }\
	while(0)\

#define TEST_EQ_INT(expect,actual) TEST_EQ_BASE((expect == actual),expect,actual)

static void test_parse_null() {
	lept_value v;
	v.type = LEPT_TRUE;
	TEST_EQ_INT(LEPT_PARSE_OK,lept_parse(v,"null"));
	TEST_EQ_INT(LEPT_NULL,lept_get_type(v));
}

static void test_parse() {
	test_parse_null();
}

int main() {
	test_parse();
	return main_ret;
	std::cout << test_pass << "/" << test_count;
	std::cout << std::setprecision(3) << "(" << test_pass * 100 / test_count << ") passed" << std::endl; 
}	
